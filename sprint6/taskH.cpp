#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int curVert, const std::vector<std::vector<int>>& vert, std::vector<int>& colors, int& time, 
    std::vector<int>& entry, std::vector<int>& leave)
{
    time += 1;
    entry[curVert] = time;
    colors[curVert] = 1;

    auto adjacents = vert[curVert];
    std::sort(adjacents.begin(), adjacents.end());
    for (const auto& idx : adjacents)
        if (colors[idx] == 0)
            dfs(idx, vert, colors, time, entry, leave);

    time += 1;
    leave[curVert] = time;
    colors[curVert] = 2;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<int> colors(n);
    std::vector<int> entry(n);
    std::vector<int> leave(n);

    std::vector<std::vector<int>> vert(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        vert[u - 1].push_back(v - 1);
    }

    int startVertex = 0;
    int time = -1;

    dfs(startVertex, vert, colors, time, entry, leave);

    for (int i = 0; i < n; ++i)
        std::cout << entry[i] << " " << leave[i] << std::endl;

    return 0;
}