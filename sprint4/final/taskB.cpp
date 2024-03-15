// Отчет https://contest.yandex.ru/contest/24414/run-report/58762257/

/*
-- ПРИНЦИП РАБОТЫ --
https://ru.m.wikipedia.org/wiki/Хеш-таблица
Хеш-таблица — это структура данных, реализующая интерфейс ассоциативного массива, 
а именно, она позволяет хранить пары (ключ, значение) и выполнять три операции.
В текущей реализации:
* put(int key, int value) – операцию добавления новой пары. Если заданный ключ уже 
есть в таблице, то соответствующее ему значение обновляется;
* get(int key) – операцию поиска пары по ключу;
* remove(int key) – удаления пары по ключу.

В данной реализации хеш-таблица представляет собой стандартный контейнер std::vector 
константного размера sBucketsNum (sBucketsNum - число корзин хеш-таблицы), элементами 
которого являются списки пар ключ-значение.

Выполнение операции в хеш-таблице начинается с вычисления хеш-функции от ключа 
i = hash(key)
Получающееся хеш-значение является индексом в контейнере m_buckets.

Затем выполняемая операция (добавление, удаление или поиск) выполняется над 
объектом хранимом в по индексу i в контейнере m_buckets. В текущей реализации 
таким объектом является связный спискок пар ключ-значение.

Коллизии разрешаются методом цепочек. Каждая ячейка m_buckets является указателем 
на связный список пар ключ-значение, соответствующих одному и тому же хеш-значению
ключа. Коллизии приводят к тому, что появляются цепочки длиной более одного элемента.
Операции поиска или удаления элемента требуют просмотра всех элементов соответствующей
ему цепочки, чтобы найти в ней элемент с заданным ключом. 

В качестве хеш-функции используется мультипликативное хеширование 
https://en.wikipedia.org/wiki/Hash_function#Multiplicative_hashing
hash(key) = floor((key * a mod 2^w) / 2^(w - m));
что эквивалентно
hash(key) = (key * a mod 2 << (w - 1)) >> (w - m);
В качестве коэффицента a используется значение, предложеннное Д.Кнутом a = 2654435769.
https://practicum.yandex.ru/learn/algorithms/courses/7f101a83-9539-4599-b6e8-8645c3f31fad/sprints/15011/topics/618173c7-3c0e-4955-b88b-d7146f9ffe2e/lessons/db4e40bc-75c2-4302-95ae-e9cc04f86546/
Число корзин равно 2^16 < 10^5, m = 16. Вычисления производятся по модулю 2^w, w = 32.
Максимальное значение хеш-функции = 2^32 - 1 >> (32 - 16) = 65535.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --

Приведенная хеш-функция i = hash(key) детерминирована, значит для одного и того же значения 
ключа, будет получен одинаковый хеш и индекс i в массиве m_buckets. Возникновение коллизий
будет означать, что для двух ключенй key1, key2, key1 != key2,  hash(key1) = hash(key2) = i.
В этом случае в m_buckets[i] будет храниться список из пар key1-val1, key2-val2, ... с 
одинаковым хешем i, т.е. значения для таких ключей не будут утеряны.

Метод HashTable::put(int key, int value)
1. Вычисляет по ключу значение хеша или индекса i = hash(key) в массиве m_buckets.
2. Если спискок в m_buckets[i] пуст в голову связного списка добавляется пара key-value.
3. Иначе в списке ищется ключ key. Если он найден его значение обновляется.
4. Если ключ не найден (и массив не пуст) - значит произошла коллизия. Пара добавляется
 в голову связного списка.

 В итоге хеш-таблица имеет следующий вид:

 bucket1 -> <key11-val1> <key12-val2> .. <key1j-valj>
 ...
 bucketi -> <keyi1-vali>
 ...
 bucketM -> <keyM1-valM> <keyM2-val1>

Метод std::optional<int> HashTable::get(int key)
1. Вычисляет по ключу значение хеша или индекса i = hash(key) в массиве m_buckets.
2. Если спискок в m_buckets[i] пуст - значение не найдено.
3. Иначе в списке ищется ключ key. Если ключ найден возвращается его значение.
4. Если ключ не найден (и массив не пуст) - значит в массиве лежат пары с ключами,
образующими коллизию с данным ключом. Т.е. ключ - не найден.

Метод std::optional<int> HashTable::remove(int key) выполняется аналогично методу get(),
за исключением того, что на 3м шаге найденная пара удаляется из списка.

Таким образом, с помощью хеш функции и метода разрешения коллизий будет построено взаимно однозначное
отображение множества ключей в множество значений.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --

Время на вычисление хеш-функции O(1). Обращения к std::vector по индексу происходит за O(1).
* Операция добавления новой пары:
Помимо времени на вычисление хеш-функции O(1) потребуется O(1) для добавления этого 
элемента в начало списка. Общая сложность O(1).
* Поиск или удаления значения по ключу:
1. Время на вычисление хеш-функции O(1).
2. В лучшем случае сложность удаления равна O(1).
В лучшем случае удаляемый элемент находится в голове списка,
поэтому сложность его удаления константная.
В худшем случае потребуется перебрать все пары из связного списка. Само удаление из 
списка займет O(1). Если все N пар ключ-значение в результате вычисления хеш-функции попали в один связный
список, то длина такого списка равна - O(N).
В среднем случае O(1 + a), где a = N/M - коэффициент заполнения таблицы, 
M = 2^16 - количество корзин в хеш таблице.
https://practicum.yandex.ru/learn/algorithms/courses/7f101a83-9539-4599-b6e8-8645c3f31fad/sprints/15011/topics/618173c7-3c0e-4955-b88b-d7146f9ffe2e/lessons/a151c825-5a76-4ab2-a6f6-1886b1783383/
Можно считать, что все операции в среднем выполняются за O(1).
Пусть на входе пришло n запросов. Тогда общая сложность выполнения этих запросов - O(n).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --

Пусть K число уникальных пар ключ-значение из входных данных.
Для для массива m_buckets хеш-таблицы будет выделена фиксированная память,
равная числу корзин sBucketsNum * на размер указателя на связный список - O(sBucketsNum) = O(1).
Общее число хранимых в связных списках элементов равно O(K).
Общая пространственная сложность равна O(sBucketsNum) + O(K) ~ O(K).

*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <optional>

class HashTable
{
public:
	HashTable();

	void put(int key, int value);
	std::optional<int> get(int key);
	std::optional<int> remove(int key);

private:
	int hash(int key);

	std::vector<std::list<std::pair<int, int>>> m_buckets;
	static const int sBucketsNum = 65536; // 2^16
};

HashTable::HashTable()
{
	m_buckets = std::vector<std::list<std::pair<int, int>>>(sBucketsNum);
}

void HashTable::put(int key, int value)
{
	auto& bucketChain = m_buckets[hash(key)];
	for (auto it = bucketChain.begin(); it != bucketChain.end(); it++)
	{
		if (it->first == key)
		{
			it->second = value;
			return;
		}
	}

	// empty or collision
	bucketChain.emplace_front(key, value);
}

std::optional<int> HashTable::get(int key)
{
	auto& bucketChain = m_buckets[hash(key)];
	for (auto it = bucketChain.begin(); it != bucketChain.end(); it++)
		if (it->first == key)
			return it->second;

	return std::nullopt;
}

std::optional<int> HashTable::remove(int key)
{
	auto& bucketChain = m_buckets[hash(key)];
	for (auto it = bucketChain.begin(); it != bucketChain.end(); it++)
	{
		if (it->first == key)
		{
			int value = it->second;
			bucketChain.erase(it);
			return value;
		}
	}

	return std::nullopt;
}

int HashTable::hash(int key)
{
	long long knuth = key * 2654435769LL; // 2 654 435 769 000 000 000
	long long modulo = 2LL << 31; // 4 294 967 296
	return static_cast<int>(knuth % modulo >> 16);
}

void printValue(const std::optional<int>& oVal)
{
	if (oVal)
		std::cout << *oVal << "\n";
	else
		std::cout << "None" << "\n";
}

int main()
{
	int queriesNumber = 0;
	std::cin >> queriesNumber;

	HashTable hashTable;

	std::string query;
	for (int i = 0; i < queriesNumber; ++i)
	{
		std::cin >> query;
		if (query == "put")
		{
			int key = 0;
			int value = 0;
			std::cin >> key >> value;

			hashTable.put(key, value);

			continue;
		}
		if (query == "get")
		{
			int key = 0;
			std::cin >> key;

			printValue(hashTable.get(key));

			continue;
		}
		if (query == "delete")
		{
			int key = 0;
			std::cin >> key;

			printValue(hashTable.remove(key));

			continue;
		}
	}

	return 0;
}