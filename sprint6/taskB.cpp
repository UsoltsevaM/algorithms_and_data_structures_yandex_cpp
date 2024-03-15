#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<int>> arr(n, std::vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;

        arr[u - 1][v - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}