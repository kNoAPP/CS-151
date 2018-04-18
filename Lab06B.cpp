/*
 * Lab06B.cpp
 *
 *  Created on: Feb 15, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program takes the sales of four quarters at four divisions of a company, records them, and
 *    outputs a sheet containing the data to a .txt file.
 */

#include "Lab.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct Sales {
	string name;
	int sale[4];
};

int Lab06B() {
	//Register divisions
	Sales no;
	no.name = "North";

	Sales so;
	so.name = "South";

	Sales ea;
	ea.name = "East";

	Sales we;
	we.name = "West";

	Sales sales[4] = {no, so, ea, we};

	//Get input from the user
	for(int i=0; i<4; i++) {
		for(int q=0; q<4; q++) {
			double c = -1;
			do {
				cout << "Please enter sales for the " << sales[i].name << " quarter #" << q + 1 << ": ";
				cin >> c;
			} while(c < 0); //Input validation
			sales[i].sale[q] = c; //Record the input
		}
	}

	ofstream outputFile("Lab06B-Sales.txt", ofstream::out | ofstream::trunc); //Purge existing data
	if(outputFile) {
		for(int i=0; i<4; i++) {
			//Format each line with the data
			string line = sales[i].name + ":";
			for(int q=0; q<4; q++) {
				stringstream s1;
				stringstream s2;
				s1 << (q+1);
				s2 << sales[i].sale[q];

				line += " Q" + s1.str() + ": " + s2.str();
				if(q != 3) line += ",";
			}
			outputFile << line << endl; //Output the record for the division
		}
	}
	else cout << "There was an error logging to Lab06B-Sales.txt!"; //Error with file
	return 0;
}
