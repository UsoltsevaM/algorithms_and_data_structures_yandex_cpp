#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(int startVert, const std::vector<std::vector<int>>& verts, std::vector<int>& colors, std::vector<int>& dist)
{
    std::queue<int> planned;
    planned.push(startVert);
    colors[startVert] = 0;
    dist[startVert] = 0;

    while (!planned.empty())
    {
        auto curVert = planned.front();
        planned.pop();

        for (const auto& adj : verts[curVert])
            if (colors[adj] == -1)
            {
                dist[adj] = dist[curVert] + 1;
                colors[adj] = 0;
                planned.push(adj);
            }

        colors[curVert] = 1;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<int>> vert(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        vert[u - 1].push_back(v - 1);
        vert[v - 1].push_back(u - 1);
    }

    int startVert = 0;
    std::cin >> startVert;

    std::vector<int> colors(n);
    for (int i = 0; i < n; ++i)
        colors[i] = -1;

    std::vector<int> dist(n);
    for (int i = 0; i < n; ++i)
        dist[i] = -1;

    bfs(startVert - 1, vert, colors, dist);

    int maxDist = -1;
    for (int i = 0; i < n; i++)
        if (dist[i] > maxDist)
            maxDist = dist[i];

    std::cout << maxDist;

    return 0;
}