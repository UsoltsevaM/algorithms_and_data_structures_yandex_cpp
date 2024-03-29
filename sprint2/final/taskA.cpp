﻿// Отчет https://contest.yandex.ru/contest/22781/run-report/55177922/

/*
-- ПРИНЦИП РАБОТЫ --
Реализован дек на кольцевом буфере константной длины.
В качестве буфера был использован std::vector<int> заданного размера maxSize.

Дек — структура данных, представляющая из себя список элементов, в которой
добавление новых элементов и удаление существующих производится с обоих концов.
Эта структура поддерживает как FIFO, так и LIFO.

Класс содержит две переменные head - индекс начала дека и tail - индекс конца дека.
Вставка/удаления из начала осуществляется при помощи индекса head, с конца -
при помощи индекса tail.

Дек поддерживает следующие операции:
* push_back(value) – добавить элемент в конец дека. Если в деке уже находится максимальное число элементов, вывести «error».
* push_front(value) – добавить элемент в начало дека. Если в деке уже находится максимальное число элементов, вывести «error».
* pop_front() – вывести первый элемент дека и удалить его. Если дек был пуст, то вывести «error».
* pop_back() – вывести последний элемент дека и удалить его. Если дек был пуст, то вывести «error».

Пример:

Empty deque

|---|---|---|---|
^
|
Head
Tail

push_front 1

|---|---|---|-1-|
^           ^
|           |
Tail        Head

push_back 2

|-2-|---|---|-1-|
^       ^
|       |
Tail    Head

push_back 3 -- full deque

|-2-|-3-|---|-1-|
^   ^
|   |
Tail Head

pop_front
pop_front
pop_front

|---|---|---|---|
^
|
Head
Tail

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Класс содержит две переменные head - индекс начала дека и tail - индекс конца дека.
При инициализации head = tail = 0 - условие пустоты дека.

Элементы в деке будут храниться по индексам
* от head до tail − 1
или
* от 0 до tail − 1 и от head до maxSize.

При вставке в конец дека вставка элемента происходит по текущему индексу, далее
индекс сдвигается вправо tail = tail + 1, при этом tail будет указывать на следующую
пустую ячейку в массиве.

При извлечении элементов с конца операции производятся в обратном порядке -
сначала происходит сдвиг индекса конца влево tail = tail - 1, затем по текущему индексу
возвращается значение. При этом при последующей вставке в конец значение будет переписано,
т.е. можно считать, что tail указывает на пустую ячейку массива.

При вставке в начало дека, сначала индекс сдвигается влево, head = head - 1, затем
происходит вставка элемента по соответствующему индексу, при этом head будет указывать
на текущее значение первого с начала элемента дека.

При извлечении элементов с начала операции производятся в обратном порядке -
сначала по текущему индексу возвращается значение, затем происходит сдвиг индекса конца вправо.
При этом head указвает на новый первый элемент в начале дека.

Чтобы эффективно использовать память вектора, будем считать, что он представляет собой кольцевой буфер.
Все операции сдвига происходят по модулю m_maxSize, что обеспечивает обращение в массиве
по корректному индексу и соотвествие заданную размеру дека.
Т.е., например, при вставке первого элемента в начало дека индек head изменится с 0 на (m_head - 1 + m_maxSize) % m_maxSize;
и будет указыать на последний элемент вектора.

При заполнение дека с любого конца индексы head и tail будут сближаться
друг с другом, при этом head будет двигаться влево (head = head - 1), а tail
вправо (tail = tail + 1), пока они не встретятся.

Для того чтобы отличить условие пустоты от условия полноты дека, в текущей реализации за
условие полноты примем ситуацию, когда индексы head и tail будут различаться на 1,
head == tail + 1. При полностью заполненном деке (число элементов = maxSize) tail будет
указывать на оставшуюся пустую ячейку массива.

Следовательно, для хранения maxSize элементов потребуется массив размера maxSize + 1.

При удалении элементов из дека с любого конца индексы head и tail будут сближаться
друг с другом, при этом head будет двигаться вправо (head = head + 1), а tail
влево (tail = tail - 1), не выполнится услолвие head == tail.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Добавление в дек и извлечение из него стоит O(1), т.к. происходит
* проверка на полноту/пустоту дека - сравнение индексов - O(1),
* запись/чтение элемента массива по индексу - O(1)
std::vector - непрырыный блок памяти позволяет осуществлять доступ
по индексу за константное время
* инкремент/декремент соотвествующего индекса - O(1).

Полностью дек будет заполнен за maxSize операций,
т.к. понадобится maxSize вставок или удалений сложностью O(1),
общая сложность заполенения будет O(n), n = maxSize.
Аналогично полный дек будет опустошен за O(n), n = maxSize.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Если максимальное число элементов в деке равно n, то всегда
потребуется выделить буфер на 1 элемент больше, т.е размера n + 1.

Поэтому дек будет потреблять O(n + 1) = O(n) памяти.
*/

#include <iostream>
#include <vector>
#include <string>
#include <optional>

class MyDequeSized
{
public:
	MyDequeSized(int maxSize) : m_maxSize(maxSize)
	{
		m_deque.resize(maxSize);
	};

	bool pushBack(int val)
	{
		if (m_head == (m_tail + 1) % m_maxSize)
			return false;

		m_deque[m_tail] = val;
		m_tail = (m_tail + 1) % m_maxSize;

		return true;
	}

	bool pushFront(int val)
	{
		if (m_head == (m_tail + 1) % m_maxSize)
			return false;

		m_head = (m_head - 1 + m_maxSize) % m_maxSize;
		m_deque[m_head] = val;

		return true;
	}

	std::optional<int> popBack()
	{
		if (m_head == m_tail)
			return std::nullopt;

		m_tail = (m_tail - 1 + m_maxSize) % m_maxSize;
		return{ m_deque[m_tail] };
	}

	std::optional<int> popFront()
	{
		if (m_head == m_tail)
			return std::nullopt;

		auto res = std::optional<int>{ m_deque[m_head] };
		m_head = (m_head + 1) % m_maxSize;

		return res;
	}

private:
	std::vector<int> m_deque;
	int m_maxSize = 0;
	int m_head = 0;
	int m_tail = 0;
};

void printValueOrError(const std::optional<int>& oVal)
{
	if (oVal)
		std::cout << *oVal << std::endl;
	else
		std::cout << "error" << std::endl;
}

int main()
{
	int commandsNumber = 0;
	std::cin >> commandsNumber;

	int maxSize = 0;
	std::cin >> maxSize;

	MyDequeSized deque(maxSize + 1);

	std::string command;
	for (int i = 0; i < commandsNumber; ++i)
	{
		std::cin >> command;
		if (command == "push_back")
		{
			int arg = 0;
			std::cin >> arg;

			if (!deque.pushBack(arg))
				std::cout << "error" << std::endl;

			continue;
		}
		if (command == "push_front")
		{
			int arg = 0;
			std::cin >> arg;

			if (!deque.pushFront(arg))
				std::cout << "error" << std::endl;

			continue;
		}
		if (command == "pop_back")
		{
			printValueOrError(deque.popBack());

			continue;
		}
		if (command == "pop_front")
		{
			printValueOrError(deque.popFront());

			continue;
		}
	}

	return 0;
}