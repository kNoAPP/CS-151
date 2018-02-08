/*
 * Lab05B.cpp
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

int Lab05B() {
	ifstream inputFile("Lab05B-Input.txt");
	ofstream outputFile("Lab05B-Output.txt", ofstream::out | ofstream::trunc);

	if(inputFile) {
		if(outputFile) {
			int key = -21;
			do {
				cout << "Please enter a decryption key (-20 to 20): ";
				cin >> key;

				if(!(-20 <= key && key <= 20)) cout << "That is not a valid key!\n\n";
			} while(!(-20 <= key && key <= 20));

			cout << "Decrypting to Lab05B-Output.txt..." << endl;

			EncryptString es(key);
			string line = "";
			while(!inputFile.eof()) {
				getline(inputFile, line);
				es.setMessage(line);
				es.decrypt();
				outputFile << es.getMessage() << endl;
			}

			cout << "Decryption complete.";
			outputFile.close();
		} else cout << "An error occurred while opening the Lab05B-Output.txt file!" << endl;
		inputFile.close();
	} else cout << "An error occurred while opening the Lab05B-Input.txt file!" << endl;
	return 0;
}



