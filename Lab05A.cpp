/*
 * Lab05A.cpp
 *
 *  Created on: Feb 8, 2018
 *  Author: Alden Bansemer
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
		for(char c : msg) encrypted += (c + key);
		msg = encrypted;
	}
	void decrypt() { //Decrypt the message by retracting each character backward the key's value.
		string decrypted = "";
		for(char c : msg) decrypted += (c - key);
		msg = decrypted;
	}
};

int Lab05A() {
	ifstream inputFile("Lab05A-Input.txt");
	ofstream outputFile("Lab05A-Output.txt", ofstream::out | ofstream::trunc);

	if(inputFile) {
		if(outputFile) {
			int key = -21;
			do {
				cout << "Please enter an encryption key (-20 to 20): ";
				cin >> key;

				if(!(-20 <= key && key <= 20)) cout << "That is not a valid key!\n\n";
			} while(!(-20 <= key && key <= 20));

			cout << "Encrypting to Lab05A-Output.txt..." << endl;

			EncryptString es(key);
			string line = "";
			while(!inputFile.eof()) {
				getline(inputFile, line);
				es.setMessage(line);
				es.encrypt();
				outputFile << es.getMessage() << endl;
			}

			cout << "Encryption complete.";
			outputFile.close();
		} else cout << "An error occurred while opening the Lab05A-Output.txt file!" << endl;
		inputFile.close();
	} else cout << "An error occurred while opening the Lab05A-Input.txt file!" << endl;
	return 0;
}



