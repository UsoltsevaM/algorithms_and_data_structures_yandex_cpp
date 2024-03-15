// Отчет https://contest.yandex.ru/contest/25070/run-report/63427248/

/*
-- ПРИНЦИП РАБОТЫ --
Требуется найти вес максимального остовного дерева в неориентированном графе. Для этого используется модификация
алгоритма Прима с очередью с приоритетом.

Функция primMST(const std::vector<std::vector<Edge>>& graph):
1. Формируется множество вершин еще не добавленных в остов - notAddedVertices. В первый момент множество состоит из всех
вершин графа.
2. Берётся любая вершина графа. Пусть это будет вершина с нулевым индексом vertIdx = 0.

3.
Функция addVertex():
- Вершина vertIdx удаляется из множества notAddedVertices, т.к. теперь она входит в остов.
- Рассмотрим все рёбра, инцидентные вершине vertIdx - adjacents. Добавим в очередь с приоритетом prioritizedEdges
все те из них, у которых другой конец не лежит в остове.

4. Пока не все вершины добавлены в остов и очередь из ребер не пуста выполняем следующие шаги:
- extractMaximum() - извлекаем edge ребро с максимальным весом из очереди
- Если другой конец ребра не лежит в остове, то добавляем его вес edge.weight к весу MSTSum остовного дерева.
Данное ребро добавляется к остовному дереву.
- Добавим ко множеству потенциально добавляемых рёбер prioritizedEdges все, которые исходят из новой вершины
edge.vert и входят в вершины, ещё не включённые в остов, с помощью функции addVertex().

Если после завершения всех шагов алгоритма множество не добавленных в остов вершин не пусто, значит граф не связный.
Иначе переменная MSTSum содержит искомое значение веса максимального остовного дерева.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --

Пусть граф G был связным, т.е. ответ существует. Обозначим через T остов, найденный алгоритмом Прима (для поиска максимального остова),
а через S — максимальный остов. Покажем, что веса S и T совпадают.

Рассмотрим первый момент времени, когда в T происходило добавление ребра, не входящего в оптимальный остов S.
Обозначим это ребро через e, концы его — через a и b, а множество входящих на тот момент в остов вершин — через V
(согласно алгоритму, a принадлежит V, b не принадлежит V, либо наоборот). В оптимальном остове S вершины a и b соединяются
каким-то путём P. Найдём в этом пути любое ребро g, один конец которого лежит в V, а другой — нет. Поскольку алгоритм Прима
выбрал ребро e вместо ребра g, то это значит, что вес ребра g меньше либо равен весу ребра e.

Удалим теперь из S ребро g, и добавим ребро e. По только что сказанному, вес остова в результате не мог уменьшится
(увеличиться он тоже не мог, поскольку S было оптимальным). Кроме того, S не перестало быть остовом (в том, что связность
не нарушилась, нетрудно убедиться: мы замкнули путь P в цикл, и потом удалили из этого цикла одно ребро).

Итак, мы показали, что можно выбрать оптимальный остов S таким образом, что он будет включать ребро e.
Повторяя эту процедуру необходимое число раз, мы получаем, что можно выбрать оптимальный остов S так,
чтобы он совпадал с T. Следовательно, вес построенного алгоритмом Прима T максимален, что и требовалось доказать.

Источники: https://e-maxx.ru/algo/mst_prim, https://wikiboard.ru/wiki/Prim%27s_algorithm

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --

Время инициализации notAddedVertices - O(|V|).
Каждая операция extractMaximum() занимает время О(1). Общее время всех вызовов extractMaximum() О(|V|).
Множество notAddedVertices представлено массивом из булевых значений. Операции доступа к массиву по индексу выполнятся за О(1).
Цикл for в addVertex() выполняется всего О(|Е|) раз, поскольку сумма длин всех списков смежности равна 2|Е|.
Добавление вершины ребра в очередь с приоритетом займет O(|log V|).
Общее время - O(|V| + |Е| * |log V|) = O(|Е| * |log V|).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --

Граф представлен списками смежности - следовательно, занимаемая память O(|V|+|E|).
Размер множества notAddedVertices равен количеству вершины графа - O(|V|).
Максимальный размер очереди prioritizedEdges равен числу ребер в графе - O(|E|).
Общая пространственная сложность - O(|V|+|E|).

*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge
{
    Edge(int vert, int weight) : vert(vert), weight(weight) {};

    int vert = 0;
    int weight = 0;
};

bool operator<(Edge lhs, Edge rhs)
{
    return lhs.weight < rhs.weight;
};

typedef std::priority_queue<Edge, std::vector<Edge>> PriorityEdgesQueue;

void addVertex(int vertIdx, const std::vector<Edge>& adjacents, std::vector<bool>& notAddedVertices,
    PriorityEdgesQueue& prioritizedEdges, int& addedVerticesCnt)
{
    notAddedVertices[vertIdx] = false;
    addedVerticesCnt++;

    for (const auto& adj : adjacents)
        if (notAddedVertices[adj.vert])
            prioritizedEdges.emplace(adj.vert, adj.weight);
}

Edge extractMaximum(PriorityEdgesQueue& prioritizedEdges)
{
    auto edge = prioritizedEdges.top();
    prioritizedEdges.pop();
    return edge;
}

void primMST(const std::vector<std::vector<Edge>>& graph)
{
    std::vector<bool> notAddedVertices(graph.size(), true);
    int addedVerticesCnt = 0;

    PriorityEdgesQueue prioritizedEdges;

    addVertex(0, graph[0], notAddedVertices, prioritizedEdges, addedVerticesCnt);

    int MSTSum = 0;
    while (!notAddedVertices.empty() && !prioritizedEdges.empty())
    {
        auto edge = extractMaximum(prioritizedEdges);

        if (notAddedVertices[edge.vert])
        {
            MSTSum += edge.weight;
            addVertex(edge.vert, graph[edge.vert], notAddedVertices, prioritizedEdges, addedVerticesCnt);
        }
    }

    if (addedVerticesCnt < graph.size())
        std::cout << "Oops! I did it again";
    else
        std::cout << MSTSum;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        int w = 0;
        std::cin >> u >> v >> w;

        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }

    primMST(graph);

    return 0;
}