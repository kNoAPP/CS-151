/*
 * AldenBansemer_LabXX.cpp
 *
 *  Created on: Feb 6, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This is the Hub program containing all projects we've done so far in CS-151. Each program
 *    has an object Lab written into a labs array. These labs are listed for the user and can
 *    be run by selecting the number appearing next to them.
 *
 *  Rants:
 *    Honestly, NIC should update their compiler. Teaching C++ with something two years out of
 *    date is a hassle. This version does not utilize the functional library. As such, way
 *    more code has been written than needs to be.
 */

#include "Lab.h" //Header File
#include <iostream>
#include <string>
#include <sstream>
//#include <functional> //Allows me to store function names
#include <string>

using namespace std;

class Lab { //Lab Class, proving a storage unit for names, desc, functions, and flushes for each lab.
private:
	string name, desc;
	int id; //Yuck
	//function<int()> f;
	bool flush;
public:
	Lab(string name, int id, string desc, /*function<int()> f,*/ bool flush = false) { //function<[return_type]([args])> f
		this->name = name;
		this->id = id; //Yuck
		this->desc = desc;
		//this->f = f;
		this->flush = flush;
	}

	string getName() { return name; }
	int getId() { return id; } //Yuck
	string getDesc() { return desc; }
	//function<int()> getFunction() { return f; }
	bool shouldFlush() { return flush; }
	void /*int*/ runFunction() {
		//int out = f();
		switch(id) {
		case 1:
			Lab01();
			break;
		case 2:
			Lab02();
			break;
		case 3:
			Lab03();
			break;
		case 4:
			Lab04A();
			break;
		case 5:
			Lab04B();
			break;
		case 6:
			Lab04A();
			break;
		case 7:
			Lab04B();
			break;
		case 8:
			Lab06A();
			break;
		case 9:
			Lab06B();
			break;
		case 10:
			Lab06C();
			break;
		case 11:
			Lab07A();
			break;
		case 12:
			Lab07B();
			break;
		case 13:
			Lab08A();
			break;
		case 14:
			Lab08B();
			break;
		case 15:
			Lab09AB();
			break;
		}
		if(flush) { //Sometimes the cin buffer is not cleared before returning here
			cin.clear(); //This clears the buffer
			cin.ignore(100, '\n'); //This ignores any loaded input
		}
		//return out;
	}
};

int main() {
	const int VERSIONS = 15; //Indicator of how many labs have been completed.
	//To restore functional, add in function declarations to the array below. Remove ids.
	Lab labs[VERSIONS] = { //Declaring all known labs
			Lab("Lab01", 1, "Sorting Arrays", false),
			Lab("Lab02", 2, "Manipulating Movie Data", true),
			Lab("Lab03", 3, "ASCII Encryption", true),
			Lab("Lab04A", 4, "Capitalizer", false),
			Lab("Lab04B", 5, "Password Verification", false),
			Lab("Lab05A", 6, "File Encryption Filter", true),
			Lab("Lab05B", 7, "File Decryption Filter", true),
			Lab("Lab06A", 8, "Joke with Punchline", false),
			Lab("Lab06B", 9, "Recording Sales", true),
			Lab("Lab06C", 10, "Colored HTML", true),
			Lab("Lab07A", 11, "Recursive Conversion", false),
			Lab("Lab07B", 12, "Multiplying using Recursion", true),
			Lab("Lab08A", 13, "Polymorphism", false),
			Lab("Lab08B", 14, "Virtual Encryption", true),
			Lab("Lab09AB", 15, "File Filter and Line Breaks", true)};
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
				stringstream parse(rinput);
				parse >> cinput;
			} catch(...) { //Bad programing, I'm aware.
				cout << "Please enter a valid number!\n";
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
