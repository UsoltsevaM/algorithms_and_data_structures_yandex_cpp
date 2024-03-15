#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr, int n)
{
	bool totalSwaps = false;
	for (int j = 0; j < n - 1; ++j)
	{
		bool isSwapped = false;
		for (int i = 0; i < n - 1 - j; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				isSwapped = true;
				totalSwaps = isSwapped;
			}
		}
		if (!isSwapped)
			break;

		for (int i = 0; i < n; ++i)
			std::cout << arr[i] << " ";

		std::cout << std::endl;
	}

	if (!totalSwaps)
		for (int i = 0; i < n; ++i)
			std::cout << arr[i] << " ";
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	bubbleSort(arr, n);

	return 0;
}