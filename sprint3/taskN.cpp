#include <iostream>
#include <vector>
#include <string>

struct Interval
{
	Interval() {}
	Interval(int min, int max) : min(min), max(max) {}
	int min = 0;
	int max = 0;
};

int max(int a, int b)
{
	return a > b ? a : b;
}

std::vector<Interval> mergeSort(const std::vector<Interval>& arr)
{
	unsigned int size = arr.size();
	if (size == 1)
		return arr;

	std::vector<Interval> leftPart(arr.begin(), arr.begin() + size / 2);
	auto leftRes = mergeSort(leftPart);

	std::vector<Interval> rightPart(arr.begin() + size / 2, arr.end());
	auto rightRes = mergeSort(rightPart);

	std::vector<Interval> res;
	int l = 0;
	int r = 0;
	while (l < leftRes.size() && r < rightRes.size())
	{
		Interval& leftVal = leftRes[l];
		Interval& rightVal = rightRes[r];

		//find most left
		Interval& mostLeft = leftVal.min < rightVal.min ? leftVal : rightVal;
		Interval& leastLeft = leftVal.min >= rightVal.min ? leftVal : rightVal;

		Interval merged;
		// merge
		if (leastLeft.min <= mostLeft.max)
		{
			merged = Interval(mostLeft.min, max(mostLeft.max, leastLeft.max));
			l++;
			r++;
		}
		else
		{
			if (leftVal.min < rightVal.min)
			{
				merged = leftVal;
				l++;
			}
			else
			{
				merged = rightVal;
				r++;
			}
		}

		if (!res.empty() && merged.min <= res.back().max)
		{
			Interval newMerged(res.back().min, max(res.back().max, merged.max));
			res.pop_back();
			res.emplace_back(newMerged);
		}
		else
		{
			res.push_back(merged);
		}
	}

	if (l < leftRes.size())
	{
		if (!res.empty() && leftRes[l].min <= res.back().max)
		{
			Interval newMerged(res.back().min, max(res.back().max, leftRes[l].max));
			res.pop_back();
			res.emplace_back(newMerged);
			l++;
		}
	}

	if (r < rightRes.size())
	{
		if (!res.empty() && rightRes[r].min <= res.back().max)
		{
			Interval newMerged(res.back().min, max(res.back().max, rightRes[r].max));
			res.pop_back();
			res.emplace_back(newMerged);
			r++;
		}
	}

	while (l < leftRes.size())
	{
		res.push_back(leftRes[l]);
		l++;
	}

	while (r < rightRes.size())
	{
		res.push_back(rightRes[r]);
		r++;
	}

	return res;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<Interval> arr;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int min = 0;
		int max = 0;
		std::cin >> min >> max;
		arr[i] = Interval(min, max);
	}

	auto res = mergeSort(arr);
	for (int i = 0; i < res.size(); ++i)
	{
		std::cout << res[i].min << " " << res[i].max << std::endl;
	}

	return 0;
}