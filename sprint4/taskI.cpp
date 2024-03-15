#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

static const int primes[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };

using V = std::vector<std::string>;

unsigned long long anagramHash(const std::string& str)
{
	unsigned long long h = 1;
	for (const auto& c : str)
	{
		int offset = c - 'a';
		h *= primes[offset];
	}
	return h;
}

int main()
{
	int n;
	std::cin >> n;

	std::unordered_map<long long unsigned, std::vector<int>> anagrams;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		long long unsigned hash = anagramHash(str);

		auto it = anagrams.find(hash);
		if (it == anagrams.end())
		{
			anagrams.emplace(hash, std::vector<int>{i});
		}
		else
		{
			it->second.push_back(i);
		}
	}

	std::vector<std::vector<int>> vec(anagrams.size());

	std::transform(anagrams.begin(), anagrams.end(), vec.begin(), [](auto pair) {return pair.second; });

	std::sort(vec.begin(), vec.end(),
		[](const auto& a, const auto& b) -> bool
		{
			return a[0] < b[0];
		});

	for (const auto& v1 : vec)
	{
		for (const auto& v2 : v1)
		{
			std::cout << v2 << " ";
		}
		std::cout << "\n";
	}

	return 0;
}