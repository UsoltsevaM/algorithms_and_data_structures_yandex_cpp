#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

long long getHash(const std::string& str, long long base, long long mod)
{
    long long hash = 0;
    for (int i = 0; i < str.size(); i++)
        hash = ((hash * base) % mod + str[i]) % mod;
    return hash;
}

long long getPower(int n, long long base, long long mod)
{
    long long power = 1;
    for (int i = 1; i < n; i++)
        power = (power * base) % mod;
    return power;
}

std::vector<int> getPositions(const std::string& str, int n, int k, long long base, long long mod)
{
    std::unordered_map<long long, int> counter;
    std::unordered_map<long long, int> hashToPos;

    long long hash = getHash(str.substr(0, n), base, mod);
    long long power = getPower(n, base, mod);
    counter[hash]++;
    hashToPos[hash] = 0;

    std::vector<int> result;
    for (int i = 1; i + n - 1 < str.size(); i++)
    {
        hash = (hash + mod - (str[i - 1] * power) % mod) % mod;
        hash = ((hash * base) % mod + str[i + n - 1]) % mod;
        counter[hash]++;

        if (counter[hash] == 1)
            hashToPos[hash] = i;

        if (counter[hash] == k)
            result.push_back(hashToPos[hash]);
    }

    return result;
}

int main()
{
    unsigned int patLength = 0;
    unsigned int k = 0;
    std::cin >> patLength >> k;
    std::cin.ignore();

    std::string str;
    std::getline(std::cin, str);

    auto res = getPositions(str, patLength, k, 123, (1LL << 55) - 1);
    for (const auto& it : res)
        std::cout << it << " ";

    return 0;
}
