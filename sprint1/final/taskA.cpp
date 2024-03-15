#include <iostream>
#include <vector>

// Report - https://contest.yandex.ru/contest/22450/run-report/54315699/
static const int sMaxDistance = 1000000;

// fill the array with the distances to the nearest zero from left to right
void fillForward(std::vector<int>& nums)
{
	int counter = sMaxDistance;
	// set counter to max possible distance not to overwrite the beginning of array (left part before first zero - x x x 0)
	for (auto& num : nums) // O(N) 
	{
		if (num == 0)
		{
			counter = 0; // when zero occurs set counter to 0
			continue;
		}
		num = ++counter; // incrementng distances from each zero to the right
	}
}

// fill the array with the distances to the nearest zero from right to left
void fillBackward(std::vector<int>& nums)
{
	int counter = sMaxDistance;
	size_t lastIdx = nums.size() - 1;
	// set counter to max possible distance not to overwrite the end of array (right part after last zero - 0 x x x)
	for (size_t i = 0; i < nums.size(); ++i) // O(N)
	{
		if (nums[lastIdx - i] == 0)
		{
			counter = 0; // when zero occurs set counter to 0
			continue;
		}
		// set distance to counter only if counter is less than current distance, otherwise it spoils the distance from previsous zero
		if (++counter < nums[lastIdx - i])
			nums[lastIdx - i] = counter;
	}
}

void fillWithDistanceToNearestZero(std::vector<int>& nums)
{
	fillForward(nums);
	fillBackward(nums);
	// In total ~ O(N) + O(N)
}

int main()
{
	size_t length = 0;
	std::cin >> length;

	std::vector<int> nums(length);
	for (size_t i = 0; i < length; ++i)
		std::cin >> nums[i];

	fillWithDistanceToNearestZero(nums);

	for (const auto& num : nums)
		std::cout << num << " ";

	return 0;
}
