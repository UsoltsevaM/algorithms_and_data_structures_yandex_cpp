#include <iostream>
#include <string>

// Report - https://contest.yandex.ru/contest/22450/run-report/54319623/

static const int sTrainerKeySize = 4;
static const int sTrainerMaxNum = 9;

int main()
{
	int k = 0;
	std::cin >> k;
	const int totalKeys = k * 2;

	int keys[sTrainerMaxNum + 1] = { 0 }; // O(N) memory complexity, N = sTrainerMaxNum - max key value
	// O(sTrainerKeySize * sTrainerKeySize)
	for (int i = 0; i < sTrainerKeySize * sTrainerKeySize; ++i) // read key number in trainer
	{
		char ch;
		std::cin >> ch;
		if (ch == '.') // skip insignificant key symbol
			continue;

		keys[ch - '0']++; // count the number of each of the encountered key
	}

	int totalScore = 0;
	for (int t = 1; t <= sTrainerMaxNum; ++t) // O(N) time complexity
		if (keys[t] > 0 && totalKeys >= keys[t])
			totalScore++;

	std::cout << totalScore;

	return 0;
}
