#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<int>> field(n, std::vector<int>(m));
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
        {
            char ch;
            std::cin >> ch;
            field[i][j] = ch - '0';
        }

    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int f = i - 1 >= 0 ? dp[i - 1][j] : 0;
            int s = j - 1 >= 0 ? dp[i][j - 1] : 0;
            dp[i][j] = std::max(f, s) + field[i][j];
        }

    std::cout << dp[n - 1][m - 1];

    return 0;
}