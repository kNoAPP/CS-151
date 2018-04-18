/*
 * Lab10B.cpp
 *
 *  Created on: Mar 15, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program provides a simple demonstration of the STL
 *    algorithms
 */

#include "Lab.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int Lab10B() {
	ifstream inFile;
	vector<string> vect;

	inFile.open("Lab10B-Input.txt");
	if(inFile) {
		for(int x=0; x<25; x++) {
			string line = "";
			if(!inFile.eof()) { //Tick through each line in file
				getline(inFile, line); //Read the line (with spaces)
				vect.push_back(line);
			} else break;
		}

		cout << "The collection has " << vect.size()
				<< " elements. Here they are:\n";
		for(unsigned int x=0; x<vect.size(); x++) cout << vect[x] << " " << endl;

		random_shuffle(vect.begin(), vect.end());
		cout << "The elements have been shuffled:\n";
		for(unsigned int x=0; x<vect.size(); x++) cout << vect[x] << " " << endl;

		sort(vect.begin(), vect.end());
		cout << "The elements have been sorted:\n";
		for(unsigned int x=0; x<vect.size(); x++) cout << vect[x] << " " << endl;

		string val = "int main()";
		if(binary_search(vect.begin(), vect.end(), val))
			cout << "The value '" << val << "' was found in the vector.\n";
		else
			cout << "The value '" << val << "' was not found in the vector.\n";
	} else cout << "Could not locate Lab10B-Input.txt!";
	return 0;
}


