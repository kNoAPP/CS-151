/*
 * Lab05A.cpp
 *
 *  Created on: Feb 8, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program is related closely to Lab05B. In this version, the program asks for a key, accesses the
 *    Lab05A-Input.txt file, encrypts it with the key, and outputs it to Lab05A-Output.txt.
 */


#include "Lab.h"
#include <iostream>
#include <fstream>

using namespace std;

class EncryptString {
private:
	string msg; //Private value may only be accessed by the EncryptString class.
	int key; //Ditto
public:
	EncryptString(int key) { //Constructor saves the msg and key within the object
		this->msg = "";
		this->key = key;
	}
	string getMessage() { return msg; } //Get the result message
	void setMessage(string msg) { this->msg = msg; } //Set the message
	int getKey() { return key; } //Get the key
	void encrypt() { //Encrypt the message by advancing each character forward the key's value.
		string encrypted = "";
		for(char c : msg) {
			c += key;
			if(c > 126) c -= 94;
			if(c < 32) c += 94;
			encrypted += c;
		}
		msg = encrypted;
	}
	void decrypt() { //Decrypt the message by retracting each character backward the key's value.
		string decrypted = "";
		for(char c : msg) {
			c -= key;
			if(c > 126) c -= 94;
			if(c < 32) c += 94;
			decrypted += c;
		}
		msg = decrypted;
	}
};

int Lab05A() {
	ifstream inputFile("Lab05A-Input.txt"); //Input file
	ofstream outputFile("Lab05A-Output.txt", ofstream::out | ofstream::trunc); //Output file with automatic clearing

	if(inputFile) {
		if(outputFile) {
			int key = -21;
			do {
				cout << "Please enter an encryption key (-20 to 20): ";
				cin >> key; //Getting a key

				if(!(-20 <= key && key <= 20)) cout << "That is not a valid key!\n\n";
			} while(!(-20 <= key && key <= 20)); //Input validation

			cout << "Encrypting to Lab05A-Output.txt..." << endl;

			EncryptString es(key); //Prepare the EncryptString object
			string line = "";
			while(!inputFile.eof()) { //Tick through each line in file
				getline(inputFile, line); //Read the line (with spaces)
				es.setMessage(line); //Set input
				es.encrypt(); //Encrypt input
				outputFile << es.getMessage() << endl; //Output the result
			}

			cout << "Encryption complete.";
			outputFile.close();
		} else cout << "An error occurred while opening the Lab05A-Output.txt file!" << endl; //Error opening output file
		inputFile.close();
	} else cout << "An error occurred while opening the Lab05A-Input.txt file!" << endl; //Error opening input file
	return 0;
}



