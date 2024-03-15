#include <iostream>
#include <vector>
#include <string>

void genBracketSeq(int n, int open, int close, std::string seq)
{
	if (open + close == 2 * n)
	{
		std::cout << seq << std::endl;
		return;
	}

	if (open < n)
		genBracketSeq(n, open + 1, close, seq + "(");
	if (open > close)
		genBracketSeq(n, open, close + 1, seq + +")");
}

int main()
{
	int n = 0;
	std::cin >> n;

	genBracketSeq(n, 0, 0, "");

	return 0;
}