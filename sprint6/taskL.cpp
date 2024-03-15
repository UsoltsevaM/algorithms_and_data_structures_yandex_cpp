#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::set<int>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        if (u > v)
            std::swap(u, v);

        if (v == u)
            continue;

        graph[u - 1].emplace(v - 1);
    }

    for (int i = 0; i < n; ++i)
        if (graph[i].size() != n - 1 - i)
        {
            std::cout << "NO";
            return 0;
        }

    std::cout << "YES";

    return 0;
}