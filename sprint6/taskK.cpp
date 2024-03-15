#include <iostream>
#include <vector>
#include <limits>

struct VertStruct
{
    int vert = 0;
    int weight = 0;
};

int minDistance(const std::vector<std::vector<int>>& dist, const std::vector<bool>& visited, int startVert)
{
    int min = std::numeric_limits<int>::max();
    int minIndex = -1;

    for (int v = 0; v < dist.size(); v++)
        if (!visited[v] && dist[startVert][v] <= min)
        {
            min = dist[startVert][v];
            minIndex = v;
        }

    return minIndex;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<VertStruct>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        int w = 0;
        std::cin >> u >> v >> w;

        graph[u - 1].push_back(VertStruct{v - 1, w});
        graph[v - 1].push_back(VertStruct{u - 1, w});
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    for (int startVertex = 0; startVertex < n; startVertex++)
    {
        std::vector<int> previous(n, -1);
        std::vector<bool> visited(n, false);

        dist[startVertex][startVertex] = 0;

        for (int count = 0; count < n ; count++)
        {
            int u = minDistance(dist, visited, startVertex);
            visited[u] = true;

            auto& neighbours = graph[u];
            for (const auto& neighbour : neighbours)
            {
                if (!visited[neighbour.vert] && dist[startVertex][u] + neighbour.weight < dist[startVertex][neighbour.vert])
                    dist[startVertex][neighbour.vert] = dist[startVertex][u] + neighbour.weight;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == std::numeric_limits<int>::max())
                std::cout << "-1" << " ";
            else
                std::cout << dist[i][j] << " ";
        }

        std::cout << std::endl;
    }


    return 0;
}