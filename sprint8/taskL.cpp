#include <iostream>
#include <vector>
#include <string>


std::vector<int> prefixFunction(const std::string& str)
{
    auto pi = std::vector<int>(str.length(), 0);
    for (int i = 1; i < str.length(); i++)
    {
        int k = pi[i - 1]; // //текущая длина префикса, который мы хотим продолжить
                            //гарантируется, что s[0..k-1] = s[i-k..i-1].

        while (k > 0 && str[i] != str[k])
        {                               //пока мы не можем продолжить текущий префикс
            k = pi[k - 1];              //уменьшаем его длину до следующей возможной
        }

        //Теперь k - максимальная длина префикса, который мы можем продолжить,
       //или 0, если такового не существует.

        if (str[i] == str[k])
            pi[i] = k + 1;
        else
            pi[i] = k; //такое может произойти только при k = 0
    }

    return pi;
}

int main()
{
	std::string str;
	std::getline(std::cin, str);

    auto res = prefixFunction(str);
    for (auto& it : res)
        std::cout << it << " ";

	return 0;
}