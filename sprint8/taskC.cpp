#include <iostream>
#include <vector>
#include <string>

std::string findLongestPalindrome(const std::string& str)
{
    int count[256] = {0};

    for (int i = 0; i < str.size(); i++)
        count[str[i]]++;

    std::string left;
    std::string mid;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (count[ch] & 1)
        {
            if (mid.empty())
                mid = ch;
            else if (ch < mid.at(0))
                mid = ch;

            count[ch--]--;
        }
        else
        {
            for (int i = 0; i < count[ch] / 2; i++)
                left.push_back(ch);
        }
    }

    std::string right(left.rbegin(), left.rend());

    return left + mid + right;
}

int main()
{
    std::string str;
    std::cin >> str;

    auto res = findLongestPalindrome(str);

    std::cout << res;

    return 0;
}