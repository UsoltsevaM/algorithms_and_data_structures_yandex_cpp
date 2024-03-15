#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const std::vector<std::string>& strs) 
{
    if (strs.size() == 0)
        return {};

    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j][i] != ch || strs[j].length() == i)
                return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<std::string> strs(n);
    for (int i = 0; i < n; i++)
        std::cin >> strs[i];

    auto res = longestCommonPrefix(strs);

    std::cout << res.size();

	return 0;
}