
#include "Map.h"
#include "lodepng.h"
#include "iostream"
#include "fstream"

using namespace lodepng;

Map::Map() {
	// TODO Auto-generated constructor stub
	map = {};
}

void Map::loadMapFromFile(const char* filePath)
{
	decode(image, mapWidth, mapHeight, filePath);
	cout << "Map size: " << mapWidth << ", " << mapHeight << endl;

	loadMap();
	printMap();
}

void Map::converImageToGrid()
{
	map.resize(mapHeight);
	for (unsigned int i = 0; i<mapHeight; i++)
	{
		map[i].resize(mapWidth);
	}
}

void Map::loadMap()
{
	converImageToGrid();
	unsigned int j = 0;
	unsigned int k = 0;

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			/*cout << "this is i: "<< i<< "and this is j: " << j << endl;*/
			map[i][j] = checkIfCellIsOccupied(i, j);
		}
	}

}

bool Map::checkIfCellIsOccupied(int i, int j) {
	int c = (i * mapWidth + j) * 4;
	int r = image[c];
	int g = image[c + 1];
	int b = image[c + 2];

	if (r == 0 && g == 0 && b == 0)
		return true;
	return false;
}

void Map::printMap() const
{
	ofstream myRoboticLab;
	myRoboticLab.open("myRoboticLab.txt");
	cout << mapHeight << endl;
	cout << mapWidth << endl;

	for (unsigned int i = 0; i < mapHeight; i++)
	{
		for (unsigned int k = 0; k < mapWidth; k++)
		{
			if (map[i][k])
			{
				myRoboticLab << "*";
			}
			else
			{
				myRoboticLab << " ";
			}
		}
		myRoboticLab << endl;


	}
	myRoboticLab.close();

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}
