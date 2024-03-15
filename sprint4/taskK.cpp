#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

static const int sGridSize = 20;
static const int sDist = 20;

struct Coord
{
	int x;
	int y;
};

bool isNear(Coord a, Coord b)
{
	int x = a.x - b.x;
	int y = a.y - b.y;

	return x * x + y * y <= sDist * sDist;
}

int getSector(int x)
{
	if (x >= 0)
		return x / sGridSize;
	return -(-x / sGridSize + 1);
}

int getBestMetro(const std::vector<Coord>& metro, const std::vector<Coord>& buses)
{
	std::unordered_map<int, std::unordered_map<int, std::vector<Coord>>> stations;
	for (const auto& bus : buses)
		stations[getSector(bus.x)][getSector(bus.y)].push_back(bus);

	int maxCount = 0;
	int bestMetro = -1;
	for (int i = 0; i < metro.size(); ++i)
	{
		int xSector = getSector(metro[i].x);
		int ySector = getSector(metro[i].y);
		int count = 0;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				for (const auto& station : stations[xSector + dx][ySector + dy])
					if (isNear(station, metro[i]))
						count++;
		if (count > maxCount)
		{
			maxCount = count;
			bestMetro = i + 1;
		}
	}
	return bestMetro;
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<Coord> metro(n);
	for (int i = 0; i < n; i++)
		std::cin >> metro[i].x >> metro[i].y;

	int m = 0;
	std::cin >> m;

	std::vector<Coord> buses(m);
	for (int i = 0; i < m; i++)
		std::cin >> buses[i].x >> buses[i].y;

	std::cout << getBestMetro(metro, buses);

	return 0;
}