/*
 * Lab04B.cpp
 *
 *  Created on: Feb 1, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program asks a user to enter a password. The program then checks for
 *    8 characters, an upper/lowercase letter, and a number. If it finds all three,
 *    the program should accept the password. If not, it should tell the user
 *    what they forgot.
 */

#include "Lab.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

bool verifyPassword(string pass);

int Lab04B() {
	string pass = "";
	do {
		cout << "Please enter an 8+ character password with an upper/lowercase letter and a number. \n  -> "; //Prompt
		getline(cin, pass); //Get input
		cout << endl; //Make things look pretty
	} while(!verifyPassword(pass)); //Verify the password. true, exit loop. false, reprompt and try again
	cout << "Password accepted!";
	return 0;
}

bool verifyPassword(string pass) {
	bool is8 = false, hasU = false, hasL = false, hasN = false; //Define bounds
	if(pass.length() >= 8) is8 = true; //Examine string for 8+ chars
	for(char c : pass) { //Loop through all existing chars
		if(isupper(c)) hasU = true; //Examine for uppercase
		if(islower(c)) hasL = true; //Examine for lowercase
		if(isdigit(c)) hasN = true; //Examine for number
	}

	//Error messages
	if(!is8) cout << "Error: Password must be 8+ characters!" << endl;
	if(!hasU) cout << "Error: Password must contain an uppercase letter!" << endl;
	if(!hasL) cout << "Error: Password must contain an lowercase letter!" << endl;
	if(!hasN) cout << "Error: Password must contain a number!" << endl;

	//Return a boolean telling if the password fits the bounds
	return is8 && hasU && hasL && hasN;
}



