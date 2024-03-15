#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> seq1(n);
    for (int i = 0; i < n; i++)
        std::cin >> seq1[i];

    std::vector<int> seq2(seq1);
    std::sort(seq2.begin(), seq2.end());
    auto last = std::unique(seq2.begin(), seq2.end());
    seq2.erase(last, seq2.end());

    int m = seq2.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (seq1[i - 1] == seq2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }

    std::cout << dp[n][m] << std::endl;

    if (dp[n][m] == 0)
        return 0;

    int i = n;
    int j = m;

    std::vector<int> optimalSet1;
    std::vector<int> optimalSet2;

    while (i > 0 && j > 0)
    {
        if (seq1[i - 1] == seq2[j - 1])
        {
            optimalSet1.push_back(i);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j] == dp[i - 1][j])
                i--;
            else
                j--;
        }
    }
    
    for (auto it = optimalSet1.rbegin(); it != optimalSet1.rend(); it++)
        std::cout << *it << " ";

    return 0;
}