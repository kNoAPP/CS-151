/*
 * Lab08B.cpp
 *
 *  Created on: Mar 1, 2018
 *  Author: Alden Bansemer
 *  Notes:
 */

// This program demonstrates an application
// of pure virtual functions.
#include "Lab.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Encryption {
protected:
	ifstream inFile;
	ofstream outFile;
	int keyshift;
public:
	Encryption(const string& inFileName, const string& outFileName);
	virtual ~Encryption();
	virtual void setKey(int& keyshift) { this->keyshift = keyshift; }
	// Pure virtual function
	virtual string transform(string line) const = 0;
	// Do the actual work.
	virtual void encrypt() final;
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(const string& inFileName, const string& outFileName) {
	this->keyshift = 0;
	inFile.open(inFileName);
	outFile.open(outFileName);
	if(!inFile) {
		cout << "The file " << inFileName << " cannot be opened.";
		exit(1);
	}
	if(!outFile) {
		cout << "The file " << outFileName << " cannot be opened.";
		exit(1);
	}
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption() {
	inFile.close();
	outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//*****************************************************
void Encryption::encrypt() {
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

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption: public Encryption {
public:
	string transform(string msg) const override {
		string encrypted = "";
		for(char c : msg) {
			c += keyshift;
			while(c > 126) c -= 94; //Let's not have problems with bounds
			while(c < 32) c += 94; //Shall we?
			encrypted += c;
		}
		return encrypted;
	}
	SimpleEncryption(const string& inFileName, const string& outFileName) :
			Encryption(inFileName, outFileName) {}
};

int Lab08B() {
	string inFileName, outFileName;
	int keyshift = 0;
	cout << "Enter name of file to encrypt (Lab08B-Input.txt): ";
	cin >> inFileName;
	cout << "Enter name of file to receive the encrypted text (Lab08B-Output.txt): ";
	cin >> outFileName;
	cout << "Enter a key shift: ";
	cin >> keyshift;
	SimpleEncryption obfuscate(inFileName, outFileName);
	obfuscate.setKey(keyshift);
	obfuscate.encrypt();
	return 0;
}
