/*

* Main.cpp
 *
 *  Created on: Nov 20, 2015
 *      Author: colman
 */
#include "Map.h"


int main()
{
	Map m = Map(0.02,0.45);
	const char* FILEPATH = "roboticLabMap.png";

	m.loadMapFromFile(FILEPATH);
	return 0;
}



