/*
 * Lab09A.cpp
 *
 *  Created on: Mar 9, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *	  Working with file filters and transformation. Labs 9A and 9B have been combined into this program.
 */

#include "Lab.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class FileFilter {
private:
	int key;
public:
	FileFilter(int key=2) {
		this->key = key;
	}
	virtual ~FileFilter() {}
	char transform(char ch) const {
		if(ch >= 'a' && ch <= 'z') return ((ch - 'a') + key) % 26 + 'a';
		else if(ch >= 'A' && ch <= 'Z') return ((ch - 'A') + key) % 26 + 'A';
		return '?';
	}
	virtual void doFilter(ifstream &in, ofstream &out) const=0;
};

class NewEncryption: public FileFilter {
public:
	NewEncryption() {}
	NewEncryption(int key) : FileFilter(key) {}
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			string encrypted = "";
			getline(in, line);
			for(char c : line) {
				if(isalpha(c)) encrypted += transform(c);
				else encrypted += transform(c);
			}
			out << encrypted << endl;
		}
	}
};


class UpperCase: public FileFilter {
public:
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			string capped = "";
			getline(in, line);
			for(char c : line) {
				if(isalpha(c)) capped += static_cast<char>(toupper(c));
				else capped += c;
			}
			out << capped << endl;
		}
	}
};

class Copy: public FileFilter {
public:
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			getline(in, line);
			out << line << endl;
		}
	}
};

class BreakSpace: public FileFilter {
public:
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			getline(in, line);
			out << line << " ";
		}
	}
};

int Lab09AB() {
	string inName, outName;
	ifstream inFile;
	ofstream outFile;

	cout << "Enter input file name: ";
	cin >> inName;

	inFile.open(inName);

	if(!inFile) {
		cout << "Cannot open the file " << inName;
		return 0;
	}

	cout << "Enter output file name: ";
	cin >> outName;
	outFile.open(outName);

	if(!outFile) {
		cout << "Cannot create the file " << outName << endl;
		inFile.close();
		return 0;
	}

	int choice;
	NewEncryption e;
	UpperCase uc;
	Copy copy;
	BreakSpace bs;

	cout << "1) Encryption" << endl;
	cout << "2) Transform uppercase" << endl;
	cout << "3) Copy file" << endl;
	cout << "4) Remove line breaks" << endl;
	cout << "  -> ";

	choice = 0;
	cin >> choice;
	switch (choice) {
	case 1:
		int key;
		cout << "Enter Key (2-25): ";
		cin >> key;

		e = NewEncryption(key);
		e.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		outFile.close();
		break;
	case 2:
		uc.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		outFile.close();
		break;
	case 3:
		copy.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		outFile.close();
		break;
	case 4:
		bs.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		break;
	default:
		cout << "Unknown Selection!" << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}

