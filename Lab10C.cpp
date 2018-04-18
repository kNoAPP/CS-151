/*
 * Lab10C.cpp
 *
 *  Created on: Mar 15, 2018
 *  Author: Aldeb Bansemer
 *  Notes:
 *    Proving my function works...
 */

#include "Lab.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

template<class T>
void reverseArray(T arr[], int size);

int Lab10C() {
	char cArr[5] = {'A', 'B', 'C', 'D', 'E'};
	cout << cArr << endl;
	reverseArray(cArr, 5);
	cout << cArr << endl;

	string sArr[] = {"This ", "Better ", "Work "};
	for(string s : sArr) cout << s;
	reverseArray(sArr, 3);
	cout << endl;
	for(string s : sArr) cout << s;
	return 0;
}

template<class T>
void reverseArray(T arr[], int size) {
	if(size >= 2) {
		swap(arr[0], arr[size-1]);
		reverseArray(arr+1, size-2);
	}
}



