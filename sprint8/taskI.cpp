#include<iostream>
#include<string>
#include <vector>

//https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/

// A utility function to fill lps[] or compute prefix function
// used in KMP string matching algorithm. Refer
// https://www.geeksforgeeks.org/archives/11902 for details


void computeLPSArray(const std::string& str, std::vector<int>& lps)
{
    int len = 0; //length of the previous longest prefix suffix
    int i;

    lps[0] = 0; //lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < str.length())
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                // This is tricky. Consider the example AAACAAAA
                // and i = 7.
                len = lps[len - 1];

                // Also, note that we do not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int isRepeat(const std::string& str)
{
    // Find length of string and create an array to
    // store lps values used in KMP
    std::vector<int> lps(str.length());

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(str, lps);

    // Find length of longest suffix which is also
    // prefix of str.
    int len = lps[str.length() - 1];

    // If there exist a suffix which is also prefix AND
    // Length of the remaining substring divides total
    // length, then str[0..n-len-1] is the substring that
    // repeats n/(n-len) times (Readers can print substring
    // and value of n/(n-len) for more clarity.

    int n = str.length();

    if (len > 0 && n % (n - len) == 0)
        return n / (n - len);

    return 1;
}

// Driver program to test above function
int main()
{
    std::string str;
    std::cin >> str;

    auto res = isRepeat(str);
    std::cout << res;

    return 0;
}