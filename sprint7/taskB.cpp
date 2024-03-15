#include <iostream>
#include <vector>
#include <algorithm>

struct Lesson
{
    double start = 0.;
    double end = 0.;
};

bool operator< (const Lesson& rhs, const Lesson& lhs)
{
    if (rhs.end == lhs.end)
        return rhs.start < lhs.start;

    return rhs.end < lhs.end;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<Lesson> cost(n);
    for (int i = 0; i < n; i++)
        std::cin >> cost[i].start >> cost[i].end;

    std::sort(cost.begin(), cost.end());

    std::vector<Lesson> res;
    res.push_back(cost[0]);

    int j = 0;
    int i = 1;
    while (i < n)
    {
        while (i < n && cost[i].start < cost[j].end)
            i++;

        if (i == n)
            break;

        res.push_back(cost[i]);
        j = i;
        i++;
    }

    std::cout << res.size() << std::endl;
    for (auto& r : res)
        std::cout << r.start << " " << r.end << std::endl;

    return 0;
}