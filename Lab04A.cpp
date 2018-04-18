/*
 * Lab04A.cpp
 *
 *  Created on: Feb 1, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program starts by getting a sentence from the user. The size of the sentence
 *    does not matter. It then runs the captalize(string) function to run through each
 *    character of the sentence and captalize if needed. Lastly, the output is displayed to
 *    the user.
 */

#include "Lab.h"
#include <iostream>
#include <string>
#include <locale>
#include <stdexcept>

using namespace std;

string captalize(string s);

int Lab04A() {
	string s = ""; //Prevent null string
	do {
		try { //LAB10 error checking
			cout << "Enter a sentence: ";
			getline(cin, s); //Set s to input
			if(s == "") throw invalid_argument("Please enter a valid sentence!");
		} catch(const std::invalid_argument& e) {
			cout << e.what() << endl;
		}
	} while(s == "");

	cout << captalize(s) << endl; //Captalize and display output
	return 0;
}

string captalize(string s) {
	bool cap = true; //Should the next alphanumeric be capital? (To start, yes)
	for(unsigned int i=0; i<s.length(); i++) { //Run through each char in the string
		if(cap && isalpha(s[i])) { //If we need a cap and the char is an alphanumeric, proceed
			cap = false; //Tell the function the next char doesn't need to be cap'd
			s[i] = toupper(s[i]); //Capitalize the char
		} else if(!cap && s[i] == '.') cap = true; //When there's no need for a cap, check for a '.' If found, enable the cap.
	}
	return s; //Return the string
}
