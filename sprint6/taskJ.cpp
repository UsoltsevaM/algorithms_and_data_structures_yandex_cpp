#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

void dfs(int curVert, const std::vector<std::vector<int>>& vert, std::vector<int>& colors, std::stack<int>& order)
{
    colors[curVert] = 1;

    auto adjacents = vert[curVert];
    for (const auto& idx : adjacents)
        if (colors[idx] == 0)
            dfs(idx, vert, colors, order);

    colors[curVert] = 2;
    order.push(curVert);
}

void topologicalSort(const std::vector<std::vector<int>>& vert, std::vector<int>& colors, std::stack<int>& order)
{
    for (int i = 0; i < vert.size(); ++i)
        if (colors[i] == 0)
            dfs(i, vert, colors, order);
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
    }
    
    std::stack<int> order;
    topologicalSort(vert, colors, order);

    while (!order.empty())
    {
        int vert = order.top();
        order.pop();
        std::cout << vert + 1 << " ";
    }

    return 0;
}