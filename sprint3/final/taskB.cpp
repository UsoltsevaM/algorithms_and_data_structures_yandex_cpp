﻿// Отчет https://contest.yandex.ru/contest/23815/run-report/55989107/

/*
-- ПРИНЦИП РАБОТЫ --

Используемые ссылки: https://wikipedia.tel/Быстрая_сортировка

Для решения задачи используется алгоритм in-place быстрой сортировки с компаратором Participant::operator<().
Participant::operator<() использует обратные значения количества задач, т.к. значения количества задач
должны быть упорядочены по убыванию, штрафы должны быть упорядочены по возрастанию, строки лексикографически (также по возрастанию).

Пример:
(-5, 100, alla) < (-6, 1000, alex)
(-5, 1000, alla) < (-5, 100, alex)
(-5, 100, alla) < (-5, 100, alex)

Шаги решения:
1. Выбирается опорный элемент pivot. Для детерминированости алгоритма выберем средний элемент массива.
Переупорядочим массив таким образом, чтобы сначала шли элементы, не превосходящие опорного,
а затем большие опорного.
Пусть leftIdx - левая граница сортируемого массива, rightIdx - правая граница.
2. Двигаем i = leftIdx левую границу до тех пор пока перестанет выполнятся условие arr[i] > pivot, т.е. до тех пор
пока i указывает на элемент больший опорного.
3. Двигаем j = rightIdx правую границу до тех пор пока перестанет выполнятся условие arr[j] < pivot, т.е. до тех пор
пока j указывает на элемент меньший опорного.
Индексы i и j будут указывать на элементы, нарушающие возрастающий порядок массива.
4. При условии i < j для сохранения порядка переставим эти элементы местами, используя std::swap().
5. Увеличим индексы i, j.
6. Продолжим выполнять п. 2,3,4,5 пока i <= j.
Важно чтобы, оба цикла while должны сработали при i == j, чтобы отнести текущий элемент в правильное множество относительно pivot.

В итоге получим разбиение массива на две части:
[leftIdx, j] - все элементы >= pivot;
[j + 1, rightIdx]- все элементы <= pivot;

7. Вызовем рекурисивно quickSort() от каждой и частей - [leftIdx, j] и [j + 1, rightIdx].

Выход из рекурсии произойдет, когда столкунутся правая и левая границы - leftIdx >= rightIdx.
На каждом шаге обратного хода рекурсии будем иметь соответвующие отсортированные части массива
[leftIdx, j] и [j + 1, rightIdx].
На последнем шаге рекурсии отсортированный интервал будет равен [leftIdx, rightIdx].

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --

Пусть есть массив из n элементов и мы находимся на первом шаге обратного хода рекурсии. Докажем по индукции:
1. Массив, полученный из одного или нуля элементов отсортированы.
2. На следующем шаге, массив, полученный из 2х элементов также упорядочен, т.к до разбиения произошла сортировка относительно
опорного элемента из массива.
3. Пусть части массива отсортированы на шаге k - 1.
4. Тогда на шаге k исходный массив будет состоять из отсортированной части [leftIdx_k, j_k] и
отсортированной части [j_k + 1, rightIdx_k].
Известно, что все элементы из множества [leftIdx_k, j_k] >= pivot_k, а все элементы [j_k + 1, rightIdx_k] <= pivot_k.
Следовательно исходный массив [leftIdx_k, rightIdx_k] отсортирован.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --

Cуммарно на каждом уровне рекурсии потребуется также O(n) операций, т.к. нужно будет проверить n элементов массива.
Сложность алгорима определяется глубиной рекурсии. В лучшем случае массив делится на две одинаковые части относительно опорного
элемента. Максимальная глубина рекурсии, при которой размеры обрабатываемых подмассивов достигнут 1, будет O(logn), т.е.
общее число операций - O(n * logn).

В среднем случае, если массив делится в соотношении 1 к m, например, 1/10 и 9/10, глубина рекурсии будет равна
log по основанию 10/9 от n, т.к. на каждом шаге массив будет сокращаться в 10/9 раза и самая длинная ветка рекурсии
достигнет 1 элемента через log 10/9 n шагов (http://www.williamspublishing.com/PDF/978-5-8459-1794-2/part.pdf).
Таким образом, пренебрегая константой - общее число операций также - O(n * logn).

В самом несбалансированном варианте каждое разделение дает два подмассива размерами 1 и n-1, т.е. при каждом рекурсивном
вызове больший массив будет на 1 короче, чем в предыдущий раз. Такое может произойти, если в качестве опорного на каждом этапе
будет выбран элемент либо наименьший, либо наибольший из всех обрабатываемых. В этом случае потребуется n-1 операций
разделения, а общее время работы составит Sum{i=0, n}(n-i) = O(n^2) операций.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Память для хранения исходного массива - O(n).

Дополнительная память потребуется только для обмена элементов на шаге 4, хранения левой, правой границ, опорного элемета - O(1),
учитывая число рекурсивных вызовов - O(logn). Копирования массива не происходит, элементы упорядочиваются по месту.
Итоговая пространственная сложность - O(logn + n) ~ O(n).

*/

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

struct Participant
{
	std::string name;
	int tasksNum = 0;
	int penalty = 0;

	bool operator<(const Participant& rhs)
	{
		return std::make_tuple(-tasksNum, penalty, name) > std::make_tuple(-rhs.tasksNum, rhs.penalty, rhs.name);
	}
};

void quickSort(std::vector<Participant>& arr, int leftIdx, int rightIdx)
{
	if (leftIdx >= rightIdx)
		return;

	Participant pivot = arr[(leftIdx + rightIdx) / 2];

	int i = leftIdx;
	int j = rightIdx;
	while (i <= j)
	{
		// оба цикла while должны отработать при i == j, чтобы отнести текущий элемент в правильное множество относительно pivot
		while (pivot < arr[i])
			i++;

		while (arr[j] < pivot)
			j--;

		if (i >= j) // все элементы отнесены к правильным множествам
			break;

		std::swap(arr[i++], arr[j--]);
	}

	quickSort(arr, leftIdx, j); // при i == j интервалы пересекаются поэтому берем интервалы без пересечений
	quickSort(arr, j + 1, rightIdx);
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<Participant> participants(n);
	for (int i = 0; i < n; ++i)
		std::cin >> participants[i].name >> participants[i].tasksNum >> participants[i].penalty;

	quickSort(participants, 0, n - 1);

	for (const auto& participant : participants)
		std::cout << participant.name << std::endl;

	return 0;
}