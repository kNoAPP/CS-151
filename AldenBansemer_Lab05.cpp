/*
 * AldenBansemer_LabXX.cpp
 *
 *  Created on: Feb 6, 2018
 *  Author: alldo
 *  Notes:
 *    This is the Hub program containing all projects we've done so far in CS-151. Each program
 *    has an object Lab written into a labs array. These labs are listed for the user and can
 *    be run by selecting the number appearing next to them.
 */

#include "Lab.h" //Header File
#include <iostream>
#include <string>
#include <sstream>
#include <functional> //Allows me to store function names
#include <string>

using namespace std;

class Lab { //Lab Class, proving a storage unit for names, desc, functions, and flushes for each lab.
private:
	string name, desc;
	function<int()> f;
	bool flush;
public:
	Lab(string name, string desc, function<int()> f, bool flush = false) { //function<[return_type]([args]) f
		this->name = name;
		this->desc = desc;
		this->f = f;
		this->flush = flush;
	}

	string getName() { return name; }
	string getDesc() { return desc; }
	function<int()> getFunction() { return f; }
	bool shouldFlush() { return flush; }
	int runFunction() {
		int out = f();
		if(flush) { //Sometimes the cin buffer is not cleared before returning here
			cin.clear(); //This clears the buffer
			cin.ignore(100, '\n'); //This ignores any loaded input
		}
		return out;
	}
};

int main() {
	const int VERSIONS = 7; //Indicator of how many labs have been completed.
	Lab labs[VERSIONS] = { //Declaring all known labs
			Lab("Lab01", "Sorting Arrays", Lab01, false),
			Lab("Lab02", "Manipulating Movie Data", Lab02, true),
			Lab("Lab03", "ASCII Encryption", Lab03, true),
			Lab("Lab04A", "Capitalizer", Lab04A, false),
			Lab("Lab04B", "Password Verification", Lab04B, false),
			Lab("Lab05A", "File Encryption Filter", Lab05A, true),
			Lab("Lab05B", "File Decryption Filter", Lab05B, true)};
	string rinput = "";
	int cinput = -1;

	while(true) {
		cout << "ALDEN BANSEMER CS-151 PROGRAM MENU" << endl
			 << "==================================" << endl
			 << "0) Quit: Leave this library" << endl;
		for(int i=0; i<VERSIONS; i++) {
			Lab l = labs[i];
			cout << i + 1 << ") " << l.getName() << ": " << l.getDesc() << endl; //Displaying programs' information
		}

		//Input Validation
		do {
			cout << " -> ";
			cinput = -1;
			getline(cin, rinput);
			try {
				cinput = stoi(rinput);
			} catch(const invalid_argument& e) {
				cout << "Please enter a valid number!\n";
				continue;
			} catch(const out_of_range& e) {
				cout << "Out of range, please try again!\n";
				continue;
			}

			if(cinput < 0 || cinput > VERSIONS) cout << "No program found under that selection!\n";
		} while(cinput < 0 || cinput > VERSIONS);

		if(cinput == 0) break; //Escaping when input = 0
		cout << "\n==============OUTPUT==============\n";
		labs[cinput - 1].runFunction(); //Running a program
		cout << "\n==================================\n\n";
	}

	return 0;
}
