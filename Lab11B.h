/*
 * Lab11B.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <vector>
#include <list>
#include <windows.h>

using namespace std;

#ifndef LAB11B_H
#define LAB11B_H

class ImageMap:list<COORD> {
public:
	void add(COORD coordArray[]);
	void add(short *coordAsShorts);
	void displayAt(char ch, int col, int row);
	void displayAt(int col, int row) { displayAt('*', col, row); }
	void eraseAt(int col, int row) { displayAt(' ', col, row); }
};

#endif /* LAB11B_H */
