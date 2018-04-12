/*
 * main.cpp
 *
 *  Created on: Feb 6, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This is the Hub program containing all projects we've done so far in CS-151. Each program
 *    has an object Lab written into a labs array. These labs are listed for the user and can
 *    be run by selecting the number appearing next to them.
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
#include <stdexcept>
#include <list>
#include <windows.h>

using namespace std;

class Lab { //Lab Class, proving a storage unit for names, desc, functions, and flushes for each lab.
private:
	string name, desc;
	int id; //Yuck
	//function<int()> f;
	bool flush;

	static const int VERSIONS = 21; //Indicator of how many labs have been completed.
		//To restore functional, add in function declarations to the array below. Remove ids.
	static const Lab labs[VERSIONS];
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
		case 16:
			Lab10A();
			break;
		case 17:
			Lab10B();
			break;
		case 18:
			Lab10C();
			break;
		case 19:
			Lab11A();
			break;
		case 20:
			Lab11B();
			break;
		case 21:
			list<Lab> queue;
			string result = "OK.";
			string arg0 = "";
			int arg1 = 0;

			while(arg0 != "RUN" && arg0 != "QUIT") {
				system("CLS");
				displayMenu(false);
				cout << endl << "-=-=Guide=-=-" << endl
					 << "ADD <# program> - Add a program to the queue." << endl
					 << "DEL - Remove last program." << endl
					 << "RUN - Run the queue." << endl
					 << "QUIT - Quit without running the queue."

					 << endl << "-=-=-Queue=-=-" << endl;
				if(queue.size() == 0) cout << "<Empty>" << endl;
				else {
					int a = 0;
					for(Lab l : queue) {
						a++;
						cout << "[" << a << "] " << l.getName() << ": " << l.getDesc() << endl; //Displaying programs' information
					}
				}

				cout << endl << result;
				cout << endl << " -> ";
				cin >> arg0;
				if(arg0 == "ADD") {
					cin >> arg1;
					if(1 <= arg1 && arg1 <= VERSIONS) {
						Lab l = Lab::getLab(arg1);
						queue.push_back(l);
						result = "OK.";
					} else result = "Invalid selection!";
				} else if(arg0 == "DEL") {
					if(queue.size() > 0) {
						queue.pop_back();
						result = "OK.";
					} else result = "Queue empty already!";
				} else if(arg0 == "RUN") {
					system("CLS");

					cin.clear(); //This clears the buffer
					cin.ignore(100, '\n'); //This ignores any loaded input

					for(Lab l : queue) {
						cout << "\n==============OUTPUT==============\n";
						l.runFunction();
						cout << "\n==================================\n\n";
					}
				} else if(arg0 == "QUIT") result = "OK.";
				else result = "Invalid command!";
			}

			queue.clear();
			break;
		}
		if(flush) { //Sometimes the cin buffer is not cleared before returning here
			cin.clear(); //This clears the buffer
			cin.ignore(100, '\n'); //This ignores any loaded input
		}
		//return out;
	}

	static Lab getLab(int id) { return labs[id - 1]; }
	static int getVersions() { return VERSIONS; }
	static void displayMenu(bool withQuit) {
		cout << "ALDEN BANSEMER CS-151 PROGRAM MENU" << endl
			 << "==================================" << endl;
		if(withQuit) cout << "0) Quit: Leave this library" << endl;
		for(int i=0; i<Lab::getVersions(); i++) {
			Lab l = labs[i];
			cout << l.getId() << ") " << l.getName() << ": " << l.getDesc() << endl; //Displaying programs' information
		}
	}
};

const Lab Lab::labs[VERSIONS] = { //Declaring all known labs
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
			Lab("Lab09AB", 15, "File Filter and Line Breaks", true),
			Lab("Lab10A", 16, "Templates and Swapping", false),
			Lab("Lab10B", 17, "Program 16-14 w/Mods", false),
			Lab("Lab10C", 18, "Proof of Concept for Lab10A", true),
			Lab("Lab11A", 19, "Linked Lists", false),
			Lab("Lab11B", 20, "Animation", false),
			Lab("Lab13", 21, "Create a Program Queue", false)};

int main() {
	string rinput = "";
	int cinput = -1;

	while(true) {
		Lab::displayMenu(true);

		//Input Validation
		do {
			try { //LAB10 error checking
				cout << " -> ";
				cinput = -1;
				getline(cin, rinput);
				stringstream parse(rinput);
				parse >> cinput;

				if(cinput < 0 || cinput > Lab::getVersions()) throw invalid_argument("No program found under that selection!");
			} catch(const std::invalid_argument& e) { cout << e.what() << endl; }
		} while(cinput < 0 || cinput > Lab::getVersions());

		if(cinput == 0) break; //Escaping when input = 0

		cout << "\n==============OUTPUT==============\n";
		Lab::getLab(cinput).runFunction(); //Running a program
		cout << "\n==============FINISH==============\n\n";
	}

	return 0;
}
