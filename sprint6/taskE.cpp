#include <iostream>
#include <vector>
#include <unordered_map>

void dfs(int curVert, const std::vector<std::vector<int>>& vert, std::vector<int>& colors, int curColor)
{
    colors[curVert] = 0;

    auto adjacents = vert[curVert];
    for (const auto& idx : adjacents)
        if (colors[idx] == -1)
            dfs(idx, vert, colors, curColor);

    colors[curVert] = curColor;
}

void connectedComponents(const std::vector<std::vector<int>>& vert, std::vector<int>& colors, int& curColor)
{
    for (int i = 0; i < vert.size(); ++i)
        if (colors[i] == -1)
            dfs(i, vert, colors, curColor++);
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<int> colors(n);
    for (int i = 0; i < n; ++i)
        colors[i] = -1;
 
    std::vector<std::vector<int>> vert(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        vert[u - 1].push_back(v - 1);
        vert[v - 1].push_back(u - 1);
    }

    int componentCount = 1;

    connectedComponents(vert, colors, componentCount);

    std::cout << componentCount - 1 << std::endl;

    std::unordered_map<int, std::vector<int>> componentsToVertices;
    for (int i = 0; i < colors.size(); ++i)
        componentsToVertices[colors[i] - 1].push_back(i);


    for (int i = 0; i < componentCount - 1; i++)
    {
        auto& compVert = componentsToVertices[i];
        for (const auto& vert : compVert)
            std::cout << vert + 1 << " ";

        std::cout << std::endl;
    }

    return 0;
}