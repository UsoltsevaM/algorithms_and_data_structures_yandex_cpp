#include <iostream>
#include <string>
#include <unordered_map>

const std::unordered_map<char, std::string> keys = { { '2', "abc" },{ '3', "def" },{ '4', "ghi" },{ '5', "jkl" },
{ '6', "mno" },{ '7', "pqrs" },{ '8', "tuv" },{ '9', "wxyz" } };

void genSeq(const std::string& nums, int numIdx, std::string seq)
{
	if (numIdx >= nums.size())
	{
		std::cout << seq << " ";
		return;
	}

	std::string letters = keys.at(nums[numIdx]);
	for (unsigned int i = 0; i < letters.size(); ++i)
		genSeq(nums, numIdx + 1, seq + letters[i]);
}

int main()
{
	std::string line;
	std::getline(std::cin, line);

	genSeq(line, 0, "");

	return 0;
}