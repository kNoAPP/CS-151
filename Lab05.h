/*
 * Lab05.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <string>

using namespace std;

#ifndef LAB05_H
#define LAB05_H

class EncryptString05 {
private:
	string msg; //Private value may only be accessed by the EncryptString class.
	int key; //Ditto
public:
	EncryptString05(int key) { //Constructor saves the msg and key within the object
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


#endif /* LAB05_H */
