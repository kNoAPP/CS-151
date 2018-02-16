/*
 * Lab06C.cpp
 *
 *  Created on: Feb 15, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program comes directly from the book (13-22). I've changed the program to use the colors red and green over
 *    black and blue.
 */

#include "Lab.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Format correct HTML encoding
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
	ColorCodedStream outputFile; //Open our color utility encoder
	fstream redFile, greenFile;
	openFile(redFile, "red"); //Open "red" file
	openFile(greenFile, "green"); //Open "green" file
	openFile(outputFile, "output"); //Open output file

	string redInput, greenInput;
	getline(redFile, redInput); //Open first line in "red" file
	getline(greenFile, greenInput); //Open first line in "green" file

	while(redFile || greenFile) { //Make sure at least one has additional lines to go through
		if(redFile && greenFile) { //If both do, compare the string for alphabetical order. Output higher one first
			if(redInput <= greenInput) {
				outputFile.writeInColor(redInput, "red");
				getline(redFile, redInput);
			} else {
				outputFile.writeInColor(greenInput, "green");
				getline(greenFile, greenInput);
			}
		}
		if(redFile && !greenFile) { //If "red" file is the last with content, outprint it
			outputFile.writeInColor(redInput, "red");
			getline(redFile, redInput);
		}
		if(greenFile && !redFile) { //If "green" file is the last with content, outprint it
			outputFile.writeInColor(greenInput, "green");
			getline(greenFile, greenInput);
		}
	}

	//By this point, the html file has been encoded in a merger of the two txt files
	return 0;
}

void openFile(fstream &file, string descr) {
	string fileName;
	cout << "Enter the name of the " << descr << " file: "; //Prompt for file name
	cin >> fileName;

	if(descr == "output") //Is this the output file? If it is, we want to be able to write to it.
		file.open(fileName.data(), ios::out);
	else
		file.open(fileName.data(), ios::in);

	if(!file) { //Was the file successfully opened? If not, exit
		cout << "Cannot open the file " << fileName;
		exit(1);
	}
}
