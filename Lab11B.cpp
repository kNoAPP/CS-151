/*
 * Lab11B.cpp
 *
 *  Created on: Mar 22, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *
 */

#include "Lab.h"
#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class ImageMap:list<COORD> {
public:
	void add(COORD coordArray[]);
	void add(short *coordAsShorts);
	void displayAt(char ch, int col, int row);
	void displayAt(int col, int row) { displayAt('*', col, row); }
	void eraseAt(int col, int row) { displayAt(' ', col, row); }
};

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

int Lab11B() {
	ImageMap figure1;
	short int p1lowerLeg1[] = {1, 10, 2, 10, 3, 10, -1, -1};
	short int p1thigh1[] = {4, 9, 5, 8, 6, 7, 7, 6, -1, -1};
	short int p1thigh2[] = {6, 7, 7, 8, 8, 9, -1, -1};
	short int p1lowerLeg2[] = {8, 10, 8, 11, -1, -1};
	short int p1torso[] = {8, 5, 9, 4, 10, 3, 11, 2, -1, -1};
	short int p1upperArms[] = {7, 2, 8, 3, 9, 4, 10, 5, 11, 6, -1, -1};
	short int p1foreArm1[] = {12, 5, 13, 4, -1, -1};
	short int p1foreArm2[] = {6, 3, 5, 4, -1, -1};
	short int *figure1AllParts[] = {p1lowerLeg1, p1thigh1, p1thigh2, p1lowerLeg2, p1torso, p1upperArms, p1foreArm1, p1foreArm2, 0};

	int k = 0;
	for(int k=0; figure1AllParts[k] != 0; k++) figure1.add(figure1AllParts[k]);

	ImageMap figure2;
	short int p2LowerLeg1[] = {1, 11, 2, 10, 3, 9, -1, -1};
	short int p2thigh1[] = {3, 9, 3, 8, 3, 7, -1, -1};
	short int p2thigh2[] = {4, 7, 5, 7, 6, 7, -1, -1};
	short int p2LowerLeg2[] = {6, 8, 6, 9, -1, -1};
	short int p2torso[] = {3, 6, 3, 5, 3, 4, 3, 3, 3, 2, 3, 1, -1, -1};
	short int p2UpperArms[] = {1, 3, 2, 3, 4, 3, 5, 3, -1, -1};
	short int p2foreArm1[] = {1, 4, 1, 5, -1, -1};
	short int p2foreArm2[] = {5, 2, 5, 1, -1, -1};
	short int *figure2AllParts[] = {p2LowerLeg1, p2thigh1, p2thigh2, p2LowerLeg2, p2torso, p2UpperArms, p2foreArm1, p2foreArm2, 0};

	for(int k=0; figure2AllParts[k] != 0; k++) figure2.add(figure2AllParts[k]);

	ImageMap figure3;
	short int p3torso[] = {4, 7, 4, 6, 4, 5, 4, 4, 4, 3, 4, 2, 4, 1, -1, -1};
	short int p3thigh1[] = {5, 8, 6, 9, -1, -1};
	short int p3thigh2[] = {3, 8, 2, 9, -1, -1};
	short int p3LowerLeg1[] = {6, 10, 6, 11, -1, -1};
	short int p3LowerLeg2[] = {1, 8, 0, 7, -1, -1};
	short int p3UpperArm1[] = {3, 4, 2, 5, -1, -1};
	short int p3UpperArm2[] = {5, 4, 6, 5, -1, -1};
	short int p3foreArm1[] = {3, 6, 4, 7, -1, -1};
	short int p3foreArm2[] = {7, 4, 8, 3, -1, -1};
	short int *figure3AllParts[] = {p3torso, p3thigh1, p3thigh2, p3LowerLeg1, p3LowerLeg2, p3UpperArm1, p3UpperArm2, p3foreArm1, p3foreArm2, 0};

	for(int k=0; figure3AllParts[k] != 0; k++) figure3.add(figure3AllParts[k]);

	system("cls");
	ImageMap *sequence[3] = {&figure1, &figure2, &figure3};

	k = 0;
	int pos = 0;
	while(pos <= 60) {
		sequence[k]->displayAt(pos, 3);
		sequence[k]->displayAt(pos*2, 12);
		Sleep(400);
		sequence[k]->eraseAt(pos, 3);
		sequence[k]->eraseAt(pos*2, 12);

		k = (k+1) % 3;
		pos += 8;
	}

	while(pos > 0) {
		sequence[k]->displayAt(pos, 3);
		sequence[k]->displayAt(pos*2, 12);
		Sleep(400);
		sequence[k]->eraseAt(pos, 3);
		sequence[k]->eraseAt(pos*2, 12);

		k = (k+1) % 3;
		pos -= 8;
	}
	sequence[k]->displayAt(pos, 3);
	system("cls");
	return 0;
}


