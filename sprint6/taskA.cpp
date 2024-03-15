#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<int>> arr(n);
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        arr[u - 1].push_back(v);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i].size() << " ";
        for (int j = 0; j < arr[i].size(); ++j)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}