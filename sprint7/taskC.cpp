#include <iostream>
#include <vector>
#include <algorithm>

struct Pile
{
    int cost = 0;
    int mass = 0;
};

bool operator< (const Pile& rhs, const Pile& lhs)
{
    return rhs.cost > lhs.cost;
}

int main()
{
    int capacity = 0;
    std::cin >> capacity;

    int n = 0;
    std::cin >> n;

    std::vector<Pile> piles(n);
    for (int i = 0; i < n; i++)
        std::cin >> piles[i].cost >> piles[i].mass;

    std::sort(piles.begin(), piles.end());

    long long totalCost = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (capacity - piles[i].mass < 0)
        {
            totalCost += static_cast<long long>(capacity) * static_cast<long long>(piles[i].cost);
            break;
        }

        capacity -= piles[i].mass;
        totalCost += static_cast<long long>(piles[i].cost) * static_cast<long long>(piles[i].mass);
    }

    std::cout << totalCost;

    return 0;
}