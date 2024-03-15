#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<int> weights(n);
    std::vector<int> costs(n);
    for (int i = 0; i < n; i++)
        std::cin >> weights[i] >> costs[i];

    std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1));

    for (int j = 0; j <= m; j++)
        dp[0][j] = j - weights[0] >= 0 ? costs[0] : 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= m; j++)
        {
            int withoutItem = dp[i - 1][j];
            int withItem = j - weights[i] >= 0 ? (dp[i - 1][j - weights[i]] + costs[i]) : 0;
            dp[i][j] = std::max(withoutItem, withItem);
        }

    int i = n - 1;
    int j = m;

    std::vector<int> optimalSet;

    while (i > 0)
    {
        int withoutItem = dp[i - 1][j];
        int withItem = j - weights[i] >= 0 ? (dp[i - 1][j - weights[i]] + costs[i]) : 0;

        if (withoutItem == 0 && withItem == 0)
        {
            i--;
            continue;
        }

        if (withoutItem > withItem)
        {
            i--;
        }
        else
        {
            optimalSet.push_back(i + 1);
            j = j - weights[i];
            i--;
        }
    }

    if (dp[i][j] > 0)
        optimalSet.push_back(i + 1);

    std::cout << optimalSet.size() << std::endl;
    
    for (const auto& it : optimalSet)
        std::cout << it << " ";

    return 0;
}