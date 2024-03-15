#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++)
        std::cin >> weights[i];

    std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1));

    for (int j = 0; j <= m; j++)
        dp[0][j] = j - weights[0] >= 0 ? weights[0] : 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= m; j++)
        {
            int withoutItem = dp[i - 1][j];
            int withItem = j - weights[i] >= 0 ? (dp[i - 1][j - weights[i]] + weights[i]) : 0;
            dp[i][j] = std::max(withoutItem, withItem);
        }

    std::cout << dp[n - 1][m];

    return 0;
}