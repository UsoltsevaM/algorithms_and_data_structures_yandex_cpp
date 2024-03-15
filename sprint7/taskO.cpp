    #include <iostream>
    #include <vector>
    #include <unordered_map>

    const static long long mod = 1000000007;

    void dfs(int from, int finish, const std::vector<std::vector<int>>& graph, std::vector<int>& colors, std::vector<long long>& dp)
    {
        if (from == finish)
            dp[from] = 1;

        colors[from] = 0;

        auto adjacents = graph[from];
        for (const auto& to : adjacents)
            if (colors[to] == -1)
                dfs(to, finish, graph, colors, dp);

        for (const auto& to : adjacents)
        {
            dp[from] += dp[to];
            dp[from] %= mod;
        }
    }

    int main()
    {
        int n = 0;
        std::cin >> n;

        int m = 0;
        std::cin >> m;

        std::vector<int> colors(n);
        for (int i = 0; i < n; ++i)
            colors[i] = -1;

        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m; ++i)
        {
            int u = 0;
            int v = 0;
            std::cin >> u >> v;

            graph[u - 1].push_back(v - 1);
        }

        int a = 0;
        int b = 0;
        std::cin >> a >> b;

        std::vector<long long> dp(n, 0);
        dfs(a - 1, b - 1, graph, colors, dp);

        std::cout << dp[a - 1];

        return 0;
    }