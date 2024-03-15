#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int curVert, const std::vector<std::vector<int>>& vert, std::vector<int>& colors)
{
    std::cout << curVert + 1 << " ";

    colors[curVert] = 1;

    auto adjacents = vert[curVert];
    std::sort(adjacents.begin(), adjacents.end());
    for (const auto& idx : adjacents)
        if (colors[idx] == 0)
            dfs(idx, vert, colors);
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<int> colors(n);
    std::vector<std::vector<int>> vert(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        vert[u - 1].push_back(v - 1);
        vert[v - 1].push_back(u - 1);
    }

    int startVertex = 0;
    std::cin >> startVertex;

    dfs(startVertex - 1, vert, colors);

    return 0;
}