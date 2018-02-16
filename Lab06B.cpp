/*
 * Lab06B.cpp
 *
 *  Created on: Feb 15, 2018
 *  Author: Alden Bansemer
 */

#include "Lab.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Sales {
	string name;
	int sale[4];
};

int Lab06B() {
	Sales no;
	no.name = "North";

	Sales so;
	so.name = "South";

	Sales ea;
	ea.name = "East";

	Sales we;
	we.name = "West";

	Sales sales[4] = {no, so, ea, we};

	for(int i=0; i<4; i++) {
		for(int q=0; q<4; q++) {
			double c = -1;
			do {
				cout << "Please enter sales for the " << sales[i].name << " quarter #" << to_string(q + 1) << ": ";
				cin >> c;
			} while(c < 0);
			sales[i].sale[q] = c;
		}
	}

	ofstream outputFile("Lab06B-Sales.txt", ofstream::out | ofstream::trunc);
	if(outputFile) {
		for(int i=0; i<4; i++) {
			string line = sales[i].name + ":";
			for(int q=0; q<4; q++) {
				line += " Q" + to_string(q + 1) + ": " + to_string(sales[i].sale[q]);
				if(q != 3) line += ",";
			}
			outputFile << line << endl;
		}
	}
	else cout << "There was an error logging to Lab06B-Sales.txt!";
	return 0;
}
