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
	void converImageToGrid();
	void loadMap();
	bool checkIfCellIsOccupied(int i, int j);
public:
	Map();
	void loadMapFromFile(const char* flePath);

	void printMap() const;
	virtual ~Map();
};

#endif /* MAP_H_ */
