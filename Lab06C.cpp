/*
 * Lab06C.cpp
 *
 *  Created on: Feb 15, 2018
 *  Author: Alden Bansemer
 */

#include "Lab.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ColorCodedStream : public fstream {
public:
	void writeInColor(string str, string aColor) {
		*this << "<span style=\"color:" + aColor + "\"> ";
		*this << str << "<br /> ";
		*this << "</span>\n";
	}
};

void openFile(fstream &file, string descr);

int Lab06C() {
	ColorCodedStream outputFile;
	fstream redFile, greenFile;
	openFile(redFile, "red");
	openFile(greenFile, "green");
	openFile(outputFile, "output");

	string redInput, greenInput;
	getline(redFile, redInput);
	getline(greenFile, greenInput);

	while(redFile || greenFile) {
		if(redFile && greenFile) {
			if(redInput <= greenInput) {
				outputFile.writeInColor(redInput, "red");
				getline(redFile, redInput);
			} else {
				outputFile.writeInColor(greenInput, "green");
				getline(greenFile, greenInput);
			}
		}
		if(redFile && !greenFile) {
			outputFile.writeInColor(redInput, "red");
			getline(redFile, redInput);
		}
		if(greenFile && !redFile) {
			outputFile.writeInColor(greenInput, "green");
			getline(greenFile, greenInput);
		}
	}
	return 0;
}

void openFile(fstream &file, string descr) {
	string fileName;
	cout << "Enter the name of the " << descr << " file: ";
	cin >> fileName;

	if(descr == "output")
		file.open(fileName.data(), ios::out);
	else
		file.open(fileName.data(), ios::in);

	if(!file) {
		cout << "Cannot open the file " << fileName;
		exit(1);
	}
}
