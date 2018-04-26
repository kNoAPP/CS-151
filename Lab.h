/*
 * sub.h
 *
 *  Created on: Feb 6, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    Just a header file to bring all previous labs together.
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

#ifndef LAB_H
#define LAB_H

int Lab01();
int Lab02();
int Lab03();
int Lab04A();
int Lab04B();
int Lab05A();
int Lab05B();
int Lab06A();
int Lab06B();
int Lab06C();
int Lab07A();
int Lab07B();
int Lab08A();
int Lab08B();
int Lab09AB();
int Lab10A();
int Lab10B();
int Lab10C();
int Lab11A();
int Lab11B();
int Lab13();
int Lab14();

class Lab { //Lab Class, proving a storage unit for names, desc, functions, and flushes for each lab.
private:
	string name, desc;
	int id; //Yuck
	bool flush;

	static const int VERSIONS = 22; //Indicator of how many labs have been completed.
		//To restore functional, add in function declarations to the array below. Remove ids.
	static const Lab labs[VERSIONS];
public:
	Lab(string name, int id, string desc, bool flush = false) {
		this->name = name;
		this->id = id;
		this->desc = desc;
		this->flush = flush;
	}

	string getName() { return name; }
	int getId() { return id; }
	string getDesc() { return desc; }
	bool shouldFlush() { return flush; }
	void runFunction() {
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
			Lab13();
			break;
		case 22:
			Lab14();
			break;
		}
		if(flush) { //Sometimes the cin buffer is not cleared before returning here
			cin.clear(); //This clears the buffer
			cin.ignore(100, '\n'); //This ignores any loaded input
		}
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
			Lab("Lab10C", 18, "Proof of Concept for Lab10A", false),
			Lab("Lab11A", 19, "Linked Lists", false),
			Lab("Lab11B", 20, "Animation", false),
			Lab("Lab13", 21, "Create a Program Queue", true),
			Lab("Lab14", 22, "Binary Trees", true)};

int Lab13() {
	list<Lab> queue;
	string result = "OK.";
	string arg0 = "";
	int arg1 = 0;

	while(arg0 != "RUN" && arg0 != "QUIT") {
		system("CLS");
		Lab::displayMenu(false);
		cout << endl << "-=-=Guide=-=-" << endl
			 << "ADD <# program> - Add a program to the queue." << endl
			 << "DEL - Remove last program." << endl
			 << "RUN - Run the queue." << endl
			 << "QUIT - Quit without running the queue." << endl

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
			if(1 <= arg1 && arg1 <= Lab::getVersions()) {
				Lab l = Lab::getLab(arg1);
				queue.push_back(l);  //This line gets a compilation error if not included in the "Lab.h" file.
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
				cout << "\n==============FINISH==============\n\n";
			}
		} else if(arg0 == "QUIT") result = "OK.";
		else result = "Invalid command!";
	}

	queue.clear();
	return 0;
}

#endif

