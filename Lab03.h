/*
 * Lab03.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <string>

using namespace std;

#ifndef LAB03_H
#define LAB03_H

class EncryptString03 {
private:
	string msg; //Private value may only be accessed by the EncryptString class.
	int key; //Ditto
public:
	EncryptString03(string msg, int key) { //Constructor saves the msg and key within the object
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

#endif /* LAB03_H */
