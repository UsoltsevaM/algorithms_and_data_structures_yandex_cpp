//https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

double median(const std::vector<int>& arrA, const std::vector<int>& arrB)
{
    int n = arrA.size();
    int m = arrB.size();
    if (n > m)
        return median(arrB, arrA);

    int start = 0;
    int end = n;
    int mergedMedian = (n + m + 1) / 2;

    while (start <= end) 
    {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = mergedMedian - mid;

        int leftA = (leftAsize > 0) ? arrA[leftAsize - 1] : std::numeric_limits<int>::min();
        int leftB = (leftBsize > 0) ? arrB[leftBsize - 1] : std::numeric_limits<int>::min();
        int rightA = (leftAsize < n) ? arrA[leftAsize] : std::numeric_limits<int>::max();
        int rightB = (leftBsize < m) ? arrB[leftBsize] : std::numeric_limits<int>::max();

        if (leftA <= rightB and leftB <= rightA) 
        {
            if ((m + n) % 2 == 0)
                return (std::max(leftA, leftB) + std::min(rightA, rightB)) / 2.0;

            return std::max(leftA, leftB);
        }
        else if (leftA > rightB) 
            end = mid - 1;
        else
            start = mid + 1;
    }

    return 0.0;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int m = 0;
    std::cin >> m;

    std::vector<int> arr1(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr1[i];

    std::vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        std::cin >> arr2[i];
        
    std::cout << median(arr1, arr2);

    return 0;
}