#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    int k = 0;
    std::cin >> k;

    int mod = 1000000007;

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (i - j > 0)
            {
                dp[i] += dp[i - j];
                dp[i] = dp[i] % mod;
            }

    std::cout << dp[n];

    return 0;
}