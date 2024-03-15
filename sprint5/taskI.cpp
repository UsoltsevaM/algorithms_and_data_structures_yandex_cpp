#include <vector>
#include <iostream>

int countTrees(int start, int end)
{
    if (start > end)
    {
        return 1;
    }

    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        int leftSubtrees = countTrees(start, i - 1);

        int rightSubtrees = countTrees(i + 1, end);

        for (int j = 0; j < leftSubtrees; j++)
        {
            for (int k = 0; k < rightSubtrees; k++)
            {
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    int n = 1;
    std::cin >> n;

    int res = countTrees(1, n);
    std::cout << res;

    return 0;
}