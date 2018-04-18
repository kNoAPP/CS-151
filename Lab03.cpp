/*
 * Lab03.cpp
 *
 *  Created on: Jan 25, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program is designed to take a message and a key from the user
 *    and encrypt it by advancing the ASCII code forward the value of
 *    the key. In this example, an object EncryptString is initialized
 *    with the message and key obtained from the user and the message
 *    is encrypted. The result is displaye don screen. The message is
 *    then decypted and the result is again displayed on screen.
 */

#include "Lab.h"
#include <iostream>

using namespace std;

class EncryptString {
private:
	string msg; //Private value may only be accessed by the EncryptString class.
	int key; //Ditto
public:
	EncryptString(string msg, int key) { //Constructor saves the msg and key within the object
		this->msg = msg;
		this->key = key;
	}
	string getMessage() { return msg; } //Get the result message
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

int Lab03() {
	string msg;
	cout << "Message: ";
	getline(cin, msg); //Get message to use.

	int key;
	cout << "Key: ";
	cin >> key; //Get key to use

	EncryptString es(msg, key); //Initialize EncryptString object
	es.encrypt(); //Encrypt the string
	cout << "\nEncyrpted: " << es.getMessage() << endl; //Output result
	es.decrypt(); //Decrypt the string
	cout << "Decrypted: " << es.getMessage() << endl; //Output result
	return 0;
}


