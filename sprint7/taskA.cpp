#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> cost(n);
    for (int i = 0; i < n; i++)
        std::cin >> cost[i];

    int totalSum = 0;
    int i = 0;
    while (i < n - 1) 
    {
        while ((i < n - 1) && (cost[i + 1] <= cost[i]))
            i++;

        if (i == n - 1)
            break;

        totalSum -= cost[i];

        i++;

        while ((i < n) && (cost[i] >= cost[i - 1]))
            i++;

        totalSum += cost[i - 1];
    }

    std::cout << totalSum;

    return 0;
}