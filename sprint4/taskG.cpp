#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

struct Hash
{
	size_t operator() (const std::vector<long long>& vec) const
	{
		size_t hash = 0;
		for (const auto& v : vec)
		{
			std::size_t h1 = std::hash<int>{}(v);
			hash ^= h1;
		}

		return hash;
	}
};

int main()
{
	int n = 0;
	std::cin >> n;

	long long s = 0;
	std::cin >> s;

	std::vector<long long> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	std::unordered_set<std::vector<long long>, Hash> res;

	std::unordered_map<long long, std::vector<std::pair<int, int>>> sumToIdxs;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			long long target = s - arr[i] - arr[j];
			auto it = sumToIdxs.find(target);
			if (it != sumToIdxs.end())
			{
				for (auto& idxs : it->second)
				{
					int x = idxs.first;
					int y = idxs.second;

					if ((x != i && x != j) && (y != i && y != j))
					{
						std::vector<long long> resVec = { arr[x], arr[y], arr[i], arr[j] };
						std::sort(resVec.begin(), resVec.end());
						res.emplace(resVec);
					}
				}
			}
			else
			{
				sumToIdxs[arr[i] + arr[j]].push_back({ i, j });
			}
		}
	}

	std::vector<std::vector<long long>> vecRes(res.begin(), res.end());
	std::sort(vecRes.begin(), vecRes.end(), [](const auto& a, const auto& b) -> bool
		{
			return a < b;
		});

	std::cout << vecRes.size() << "\n";
	for (auto& it : vecRes)
	{
		for (auto& it1 : it)
			std::cout << it1 << " ";
		std::cout << "\n";
	}

	return 0;
}