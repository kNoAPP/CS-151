/*
 * Lab09AB.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <iomanip>
#include <string>

using namespace std;

#ifndef LAB09AB_H
#define LAB09AB_H

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

#endif /* LAB09AB_H */
