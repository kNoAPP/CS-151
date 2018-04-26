/*
 * Lab08B.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <fstream>
#include <string>

using namespace std;

#ifndef LAB08B_H
#define LAB08B_H

class Encryption08B {
protected:
	ifstream inFile;
	ofstream outFile;
	int keyshift;
public:
	Encryption08B(const string& inFileName, const string& outFileName);
	virtual ~Encryption08B();
	virtual void setKey(int& keyshift) { this->keyshift = keyshift; }
	// Pure virtual function
	virtual string transform(string line) const = 0;
	// Do the actual work.
	virtual void encrypt() final;
};

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption: public Encryption08B {
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
			Encryption08B(inFileName, outFileName) {}
};

#endif /* LAB08B_H */
