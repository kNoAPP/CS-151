/*
 * Lab08B.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include "Lab08B.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption08B::Encryption08B(const string& inFileName, const string& outFileName) {
	this->keyshift = 0;
	inFile.open(inFileName);
	outFile.open(outFileName);
	if(!inFile) cout << "The file " << inFileName << " cannot be opened.";
	if(!outFile) cout << "The file " << outFileName << " cannot be opened.";
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption08B::~Encryption08B() {
	inFile.close();
	outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//*****************************************************
void Encryption08B::encrypt() {
	/*
	char ch;
	char transCh;
	inFile.get(ch);
	while(!inFile.fail()) {
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}
	*/

	//Why write gross, under-performing code when you can have clean, cool code

	string line = "";
	while(!inFile.eof()) { //Tick through each line in file
		getline(inFile, line); //Read the line (with spaces)
		outFile << transform(line) << endl; //Output the result
	}
}


