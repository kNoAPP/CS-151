/*
 * Lab06A.cpp
 *
 *  Created on: Feb 15, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program takes two input files (a joke and a punchline) and uses both to deliever a pun. First,
 *    the first file's contents are shown to the user as the "joke."
 */


#include "Lab.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;


int Lab06A() {
	ifstream inputFile1("Lab06A-Joke.txt"); //Input file
	ifstream inputFile2("Lab06A-Punchline.txt"); //Input file

	if(inputFile1 && inputFile2) {
		string line = "";
		while(!inputFile1.eof()) { //Tick through each line in file
			getline(inputFile1, line); //Read the line (with spaces)
			cout << line << endl;
		}

		int lines = 0;
		while(getline(inputFile2, line)) lines++;
		inputFile2.close();

		ifstream inputFile2("Lab06A-Punchline.txt"); //Input file
		for(int i=0; i<lines; i++) getline(inputFile2, line);

		Sleep(2000);
		cout << line << endl;
		Sleep(1000);

		inputFile1.close();
		inputFile2.close();
	} else cout << "An error occurred while opening one of the Lab06A txt files!" << endl; //Error opening input file
	return 0;
}

