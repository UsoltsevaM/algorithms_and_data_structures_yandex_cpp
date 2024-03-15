// Отчет https://contest.yandex.ru/contest/24414/run-report/58823811/

/*
-- ПРИНЦИП РАБОТЫ --

Для решения используется обратный поисковый индекс - https://ru.wikipedia.org/wiki/Инвертированный_индекс -
структура данных, в которой для каждого слова коллекции документов в соответствующем списке перечислены все документы в коллекции,
в которых оно встретилось, а также количество вхождений данного слова в перечисленный документы.

Word1 -> Document1 -> Word1Num1, Document3 -> Word1Num2, Document7 -> Word1Num7
Word2 -> Document1 -> Word2Num1, Document5 -> Word2Num5, Document7 -> Word2Num7
Word3 -> Document1 -> Word3Num1
...

Решение задачи состоит из 2х этапов:

1. Построение поискового индекса для n документов.
Поисковый индекс представляется хэш таблицей m_wordDataMap, ключами которой word являются слова из текста.
В качестве значений используется другая хэш таблица, ставящая в соответвие документу documentNum количество
вхождений слова word в него.
Метод SearchEngine::addToWordDataMap() последовательно обрабатывает n документов, добавляя данные для
каждого из слов в m_wordDataMap.

2. Обработка запросов.
Обработка запроса происходит в методе SearchEngine::processQuery().
Релевантность документа оценивается следующим образом: для каждого уникального слова из запроса
берётся число его вхождений в документ, полученные числа для всех слов из запроса суммируются.
Итоговая сумма и является релевантностью документа. Чем больше сумма, тем больше документов подходит под запрос.
Для каждого запроса в SearchEngine::buildDocRelevanceData() строится массив пар со значениями релевантности
документов docRelevance. Индексом массива является номером документа, а значением - пара (индекс документа, релевантность)
где релевантность - количество вхождений в документ уникальных слов из запроса.
Далее, массив сортируется, используя std::partial_sort, по 2м критериям: 1. убыванию релевантости 2. возрастанию номера документа.
После сортировки в начале массива содержатся sQueryNumber = 5 документов, отсортированных по критериям (1,2) выше.
printRelevantDocuments() - печатает sQueryNumber = 5 наиболее релевантных документов.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --

Будем считать, что все входные данные корректны.

1. Построение поиского индекса для n документов.
Будем считать, что библиотечная функция построения словаря (на основе хеш таблицы) корректна.
Функция SearchEngine::addToWordDataMap(const std::string& document, int documentNum)
Принимает на вход документ и его номер. Для каждого слова Word_i1 из документа i будет построен
словарь вида Document_i -> Word_jNumi, где Word_jNumi число вхождений слова Word_j в документ i.
Т.е. для всех слов из документа i:

Word_1 -> Document_i -> Word_1Numi
Word_2 -> Document_i -> Word_2Numi
Word_3 -> Document_i -> Word_3Numi
...

Очевидно, что расссматривая все слова из документа i мы получим верные значения Word_ijNumi
количества вхождений слова j в документ i для каждого из j слов.

Обобщим данный подход на N документов. Для N документов словарь, представляющий собой композицию
словарей, будет иметь вид:

Word_1 -> Document_1 -> Word_1Num1
		  Document_2 -> Word_1Num2
		  ...
		  Document_N -> Word_1NumN

   ...

Word_j -> Document_1 -> Word_jNum1
		  Document_2 -> Word_jNum2
		  ...
		  Document_N -> Word_jNumN

	...

Word_K -> Document_1 -> Word_KNum1
		  Document_2 -> Word_KNum2
		  ...
		  Document_N -> Word_KNumN

Словари гарантируют отсутствие дубликатов ключей, как Word_j, так и Document_i, следовально
число вхождений каждого слова в каждый документ Word_jNumi будет подсчитано корректно.

2. Обработка запроса.
Пусть число уникальных слов в запросе L. Функция SearchEngine::buildDocRelevanceData(const std::string& query)
принимает запрос из L слов и строит массив с данными релевантности документов (docRelevance):

  Индекс         Индекс                   Релеантность 
[Document_1] = (Document_1, Word_1Num1 + Word_2Num1 + ... + Word_LNum1)
[Document_2] = (Document_2, Word_1Num2 + Word_2Num2 + ... + Word_LNum2)
...
[Document_N] = (Document_N, Word_1NumN + Word_2NumN + ... + Word_LNumN)

При этом на 1й из L итераций вычислится N значений:

  Индекс         Индекс     Релеантность
[Document_1] = (Document_1, Word_1Num1)
[Document_2] = (Document_2, Word_1Num2)
...
[Document_N] = (Document_N, Word_1NumN)

На jй из L итераций словарь содержит N сумм:

  Индекс         Индекс              Релеантность
[Document_1] = (Document_1, Word_1Num1 + ... + Word_jNum1)
[Document_2] = (Document_2, Word_1Num2 + ... + Word_jNum2)
...
[Document_N] = (Document_N, Word_1NumN + ... + Word_jNumN)

На Lй итерации получим искомый массив docRelevance, представленный выше, содержащий для каждого документа
пару - номер документа, релевантность - сумму всех вхождений уникальных слов из запроса.

Далее, считаем, что стандарные функции преобразования в вектор, сортировки и вывода корректны.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --

1. Сложность построения поиского индекса для N документов.
Пусть число слов в документе K.
Для каждого слова Word_i сложность вставки или поиска в хеш таблице Word_i -> Document_1, ... Document_t (m_wordDataMap)
равна O(1). Сложность добавления или поиска документа в в хеш таблице Document_j -> Word_iNum
(количество слов Word_i в документе Document_j) также равна O(1).
Поисковый индекс строится последовательным просмотром N * K слов и добавлением для каждого из них данных в 2 хэш таблицы
(по ключам Word_i и Document_j), за O(1) в каждую. Общая сложность равна O(N * K).

2. Обработка запросов.
Пусть каждый из M запросов в содержит L слов.
Для каждого из M запросов:
2.1. Строится словарь релевантности.
Для каждого уникального слова из запроса оно ищется в словаре m_wordDataMap за O(1).
Уникальность проверяется за O(1), используя unoredered_set, реализованный при помощи хэш таблицы.
Затем для всех документов, в которых встречается текущее слово (наибольшее число N), количество вхождений слова
суммируется с значением количества вхождений по соответвующему индеусу (номер документа) в массиве релевантности за O(N).
Массив с данными релевантности для запроса из L слов будет построен за O(N*L).
2.2. Данные сортируются по убыванию релевантности частичной сортировкой с сохранением порядка документов за 
O((last-first)log(middle-first)) = O(N*log(sQueryNumber)) = O(N*log(5)) ~ O(N).
https://en.cppreference.com/w/cpp/algorithm/partial_sort
Для одного запроса сложность равна O(N*L) + O(N) ~ O(N*L)
Для M запросов O(M*N*L).
Итоговая сложность алгоритма O(N*K) + O(M*N*L).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
1. Сложность построения поиского индекса для N документов.
Пусть K - число уникальный слов в N документах.
Для каждого из K слов в словаре m_wordDataMap нужно хранить словарь, состоящий из пар Document_j -> Word_iNum.
В худшем случае число таких пар равно числу документов N, т.е. O(N). Т.к. в словаре m_wordDataMap хранится
K слов, то общая пространственная сложность для поискового индекса равна O(K*N).

2. Обработка запросов.
Для обратки каждого из M запросов потребуется пространство размером равное числу документов N.
В текущей реализации - это массив размера N, где для каждого из документов будет суммироваться число вхождений 
в него уникальных слов из текущего запроса (релевантность) - O(N).
Пусть число уникальных слов в запросе L. Кроме того, для проверки уникальности слов
потребуется множество размера O(L). Таким образом, для одного запроса потребуется O(N+L) памяти.
Учитывая общее число запросов M, всего потребуется O(M*(N+L)) памяти. Однако в каждом из M запросов она
может быть переиспользована.

Общая сложность ~ O(K*N + M*(N+L))

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <unordered_set>

class SearchEngine
{
public:
	void addToWordDataMap(const std::string& document, int documentNum);
	void processQuery(const std::string& query);

private:
	using DocumentRelevance = std::vector<std::pair<int, int>>;
	using DocumentToWordNum = std::unordered_map<int, int>;
	using WordToData = std::unordered_map<std::string, DocumentToWordNum>;

	DocumentRelevance buildDocRelevanceData(const std::string& query);
	bool isWordChecked(const std::string& word, std::unordered_set<std::string>& checkedWords);
	void printRelevantDocuments(const std::vector<std::pair<int, int>>& documentsData);

	WordToData m_wordDataMap;
	static const int sQueryNumber = 5;
	static const int sTotalDocumentsNum = 10000;
};

void SearchEngine::addToWordDataMap(const std::string& document, int documentNum)
{
	std::istringstream iss(document);
	std::string word;
	while (iss >> word)
		m_wordDataMap[word][documentNum]++;
}

bool SearchEngine::isWordChecked(const std::string& word, std::unordered_set<std::string>& checkedWords)
{
	if (checkedWords.count(word))
		return true;

	checkedWords.emplace(word);
	return false;
}

SearchEngine::DocumentRelevance SearchEngine::buildDocRelevanceData(const std::string& query)
{
	std::istringstream iss(query);
	std::string word;

	DocumentRelevance docRelevance;
	docRelevance.resize(sTotalDocumentsNum);

	std::unordered_set<std::string> checkedWords;
	while (iss >> word)
	{
		if (isWordChecked(word, checkedWords))
			continue;

		auto wordIt = m_wordDataMap.find(word);
		if (wordIt != m_wordDataMap.end())
		{
			auto& documentMap = wordIt->second;
			for (const auto& documentData : documentMap)
			{
				docRelevance[documentData.first].first = documentData.first;
				docRelevance[documentData.first].second += documentData.second;
			}
		}
	}

	return docRelevance;
}

void SearchEngine::printRelevantDocuments(const std::vector<std::pair<int, int>>& documentsData)
{
	for (int i = 0; i < sQueryNumber; ++i)
	{
		if (i == documentsData.size() || documentsData[i].second == 0)
			break;

		std::cout << documentsData[i].first << " ";
	}
	std::cout << "\n";
}

void SearchEngine::processQuery(const std::string& query)
{
	auto docRelevance = buildDocRelevanceData(query);

	std::partial_sort(docRelevance.begin(), docRelevance.begin() + sQueryNumber, docRelevance.end(),
		[](const auto& a, const auto& b)
		{
			return std::make_tuple(a.second, -a.first) > std::make_tuple(b.second, -b.first);
		});

	printRelevantDocuments(docRelevance);
}

int main()
{
	int documentsNum = 0;
	std::cin >> documentsNum;
	std::cin.ignore();

	SearchEngine engine;
	for (int i = 1; i <= documentsNum; i++)
	{
		std::string document;
		std::getline(std::cin, document);
		engine.addToWordDataMap(document, i);
	}

	int queriesNum = 0;
	std::cin >> queriesNum;
	std::cin.ignore();

	for (int i = 0; i < queriesNum; i++)
	{
		std::string query;
		std::getline(std::cin, query);
		engine.processQuery(query);
	}

	return 0;
}