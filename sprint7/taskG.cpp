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

    std::vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (const auto& c : coins)
    {
        for (int i = 0; i <= sum; i++)
        {
            if (i - c >= 0)
                dp[i] += dp[(i - c)];
        }
    }

    std::cout << dp[sum];

    return 0;
}