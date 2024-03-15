#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int sum = 0;
    std::cin >> sum;

    int n = 0;
    std::cin >> n;

    std::vector<int> coins(n);
    for (int i = 0; i < n; i++)
        std::cin >> coins[i];

    std::vector<int> dp(sum + 1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        for (const auto& c : coins)
            if (i - c >= 0 && dp[i - c] != std::numeric_limits<int>::max())
                dp[i] = std::min(dp[i], dp[i - c] + 1);
    }

    if (dp[sum] == std::numeric_limits<int>::max())
        std::cout << -1;
    else
        std::cout << dp[sum];

    return 0;
}