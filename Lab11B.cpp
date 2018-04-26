/*
 * Lab11B.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include "Lab11B.h"
#include <list>
#include <iostream>

using namespace std;

const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void ImageMap::add(COORD coordArray[]) {
	for(int k=0; coordArray[k].X != -1; k++) push_back(coordArray[k]);
}

void ImageMap::add(short *coordAsShorts) {
	COORD *pCoord = reinterpret_cast<COORD *>(coordAsShorts);
	add(pCoord);
}

void ImageMap::displayAt(char ch, int col, int row) {
	list<COORD>::iterator iter = this->begin();
	for(; iter != this->end(); iter++) {
		COORD currentPos;
		currentPos.Y = row + iter->Y;
		currentPos.X = col + iter->X;
		SetConsoleCursorPosition(console, currentPos);
		cout << ch << endl;
	}
}


