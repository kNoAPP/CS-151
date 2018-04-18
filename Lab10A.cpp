/*
 * Lab10A.cpp
 *
 *  Created on: Mar 15, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program asks the user for some string input. It will then reverse that string and
 *    read it back.
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

int Lab10A() {
	string sentence = "";
	cout << "Please enter a sentence (pt. 1): ";
	getline(cin, sentence);
	char str[sentence.length() + 1];
	strcpy(str, sentence.c_str());
	reverseArray(str, sentence.length());
	cout << "Reverse! Reverse!" << endl << str << endl;
	return 0;
}

template<class T>
void reverseArray(T arr[], int size) {
	if(size >= 2) {
		swap(arr[0], arr[size-1]);
		reverseArray(arr+1, size-2);
	}
}
