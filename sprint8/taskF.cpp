#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    std::unordered_map<std::string, int> map;
    for (int i = 0; i < n; i++)
    {
        std::string str;
        std::cin >> str;
        auto it = map.find(str);
        if (it != map.end())
        {
            map[str]++;
        }
        else
            map[str] = 1;
    }

    int maxFreq = 0;
    std::string minStr;
    for (const auto& it : map)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            minStr = it.first;
        }
        else if (it.second == maxFreq)
        {
            if (it.first < minStr)
                minStr = it.first;
        }
    }

    std::cout << minStr;

	return 0;
}