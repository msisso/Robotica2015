/*
 * Map.h
 *
 *  Created on: Nov 20, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
using namespace std;

class Map {
private:
	unsigned int mapWidth;
	unsigned int mapHeight;
	vector<unsigned char> image;
	vector<vector<bool> > map;
	float mapResolution;
	float robotSize;
	int robotSizeInCells;
	int inflationRaduis;

	void converImageToGrid();
	void loadMap();
	bool checkIfCellIsOccupied(int i, int j);
public:
	Map(float mapResolution, float robotSize);
	void loadMapFromFile(const char* flePath);
	void printMap(vector<vector<bool> > map) const;
	void inflateObstacles();

	virtual ~Map();
};

#endif /* MAP_H_ */
