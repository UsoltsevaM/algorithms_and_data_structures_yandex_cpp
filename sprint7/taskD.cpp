#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;

    int mod = 1000000007;
    int f_0 = 0;
    int f_1 = 1;

    int f_n = 0;
    for (int i = 0; i < n; i++)
    {
        f_n = (f_0 + f_1) % mod;
        f_0 = f_1;
        f_1 = f_n;
    }

    std::cout << f_n;

    return 0;
}