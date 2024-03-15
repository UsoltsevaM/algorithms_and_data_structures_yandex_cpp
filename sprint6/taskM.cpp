#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool isBipartite(int startVert, const std::vector<std::vector<int>>& graph, std::vector<int>& colors)
{
    std::queue<int> planned;
    planned.push(startVert);
    colors[startVert] = 1;

    while (!planned.empty())
    {
        auto curVert = planned.front();
        planned.pop();

        for (const auto& adj : graph[curVert])
            if (colors[adj] == -1)
            {
                colors[adj] = 1 - colors[curVert];
                planned.push(adj);
            }
            else if (colors[adj] == colors[curVert])
                return false;
    }

    return true;
}

bool isBipartite(const std::vector<std::vector<int>>& vert, std::vector<int>& colors)
{
    for (int i = 0; i < vert.size(); ++i)
        if (colors[i] == -1)
            if (!isBipartite(i, vert, colors))
                return false;

    return true;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    std::vector<int> colors(n);
    for (int i = 0; i < n; ++i)
        colors[i] = -1;

    if (isBipartite(graph, colors))
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}