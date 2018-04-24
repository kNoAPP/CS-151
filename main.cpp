/*
 * main.cpp
 *
 *  Created on: Feb 6, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This is the Hub program containing all projects we've done so far in CS-151. Each program
 *    has an object Lab written into a labs array. These labs are listed for the user and can
 *    be run by selecting the number appearing next to them.
 *  Rants:
 *    Honestly, NIC should update their compiler. Teaching C++ with something two years out of
 *    date is a hassle. This version does not utilize the functional library. As such, way
 *    more code has been written than needs to be.
 */

#include "Lab.h" //Header File
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
//#include <functional> //Allows me to store function names
#include <string>
#include <stdexcept>
#include <list>
#include <locale>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

int bubbleSort(int[], int);
int selectionSort01(int[], int);

void selectionSort02(double *array, int size);
double mean(double *array, int size);
double median(double *array, int size);
double mode(double *array, int size);

string captalize(string s);

bool verifyPassword(string pass);

void sign(int);

int multiply(int, int);

template<class T>
void reverseArray(T arr[], int size);

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
			Lab("Lab13", 21, "Create a Program Queue", false),
			Lab("Lab14", 22, "Binary Trees", true)};

int main() {
	string rinput = "";
	int cinput = -1;

	while(true) {
		Lab::displayMenu(true);

		//Input Validation
		do {
			try { //LAB10 error checking
				cout << " -> ";
				cinput = -1;
				getline(cin, rinput);
				stringstream parse(rinput);
				parse >> cinput;

				if(cinput < 0 || cinput > Lab::getVersions()) throw invalid_argument("No program found under that selection!");
			} catch(const std::invalid_argument& e) { cout << e.what() << endl; }
		} while(cinput < 0 || cinput > Lab::getVersions());

		if(cinput == 0) break; //Escaping when input = 0

		cout << "\n==============OUTPUT==============\n";
		Lab::getLab(cinput).runFunction(); //Running a program
		cout << "\n==============FINISH==============\n\n";
	}

	return 0;
}

int Lab01() {
	const int SIZE = 20;

	int bubble[SIZE] = {20, 18, 19, 17, 16, 14, 15, 13, 11, 12, 10, 8, 9, 7, 5, 6, 4, 2, 3, 1};
	cout << "Bubble: " << bubbleSort(bubble, SIZE) << " swaps \n";

	int selection[SIZE] = {20, 18, 19, 17, 16, 14, 15, 13, 11, 12, 10, 8, 9, 7, 5, 6, 4, 2, 3, 1};
	cout << "Selection: " << selectionSort01(selection, SIZE) << " swaps \n";
	return 0;
}

int bubbleSort(int array[], int size) {
	int swaps = 0, hold;
	bool perfect;

	do {
		perfect = true;
		for(int i=0; i<(size - 1); i++) {
			if(array[i] > array[i+1]) {
				hold = array[i];
				array[i] = array[i+1];
				array[i+1] = hold;
				perfect = false;
				swaps++;
			}
		}
	} while(!perfect);
	return swaps;
}

int selectionSort01(int array[], int size) {
	int swaps = 0, start, mIndex, mValue;

	for(start=0; start<(size - 1); start++) {
		mIndex = start;
		mValue = array[start];
		for(int index=start + 1; index<size; index++) {
			if(array[index] < mValue) {
				mValue = array[index];
				mIndex = index;
			}
		}
		array[mIndex] = array[start];
		array[start] = mValue;
		swaps++;
	}
	return swaps;
}

int Lab02() {
	int SIZE;
	do {
		try { //LAB10 error checking
			cout << "How many people are your surveying? : ";
			cin >> SIZE;
			if(SIZE < 1) throw invalid_argument("Selection must be greater than 0!");
		} catch(const std::invalid_argument& e) {
			cout << e.what() << endl;
		}
	} while(SIZE < 1); //Input validation

	double movies[SIZE];
	double *movies_b = movies;

	for(int i=0; i<SIZE; i++) {
		do {
			try { //LAB10 error checking
				cout << "How many movies has #" << (i+1) << " seen? : ";
				cin >> *(movies+i);
				if(*(movies+i) < 0) throw invalid_argument("Selection must be greater than 0!");
			} catch(const std::invalid_argument& e) {
				cout << e.what() << endl;
			}
		} while(*(movies+i) < 0); //Input validation
	}

	selectionSort02(movies_b, SIZE); //Sort the list in ascending order

	cout << endl;
	cout << "Mean: " << mean(movies_b, SIZE) << endl //Display Mean
			<< "Median: " << median(movies_b, SIZE) << endl; //Display Median

	double m = mode(movies_b, SIZE);
	if(m >= 0) cout << "Mode: " << m << endl; //Display Mode
	else cout << "Mode: No Mode"; //Display no Mode
	return 0;
}

/**
 * The selectionSort function has been modified to use pointers
 * to access members of a given array.
 */
void selectionSort02(double *array, int size) {
	int start, mIndex;
	double mValue;

	for(start=0; start<(size - 1); start++) {
		mIndex = start;
		mValue = *(array+start); //This is equivalent to array[start]
		for(int index=start + 1; index<size; index++) {
			if(*(array+index) < mValue) {
				mValue = *(array+index); //Same concept here
				mIndex = index;
			}
		}
		*(array+mIndex) = *(array+start); //And here
		*(array+start) = mValue; //And elsewhere in the code
	}
}

/**
 * Function mean is probably the simplest to understand. First add all values in an
 * array together, then divide by size. The double it returns is an average.
 * No order requirement.
 */
double mean(double *array, int size) {
	double value = 0;
	for(int i=0; i<size; i++) value += *(array + i);
	return value/size;
}

/**
 * The median function is slightly harder to understand. First, we need to see if the
 * size of the array is even or odd. Requires ordered array.
 *
 * Case Odd:
 *   Find the middle value in the array and return it. To do this, take one less than
 *   the array size to account for arrays starting at 0, then divide by two. Return
 *   the value found at that location.
 * Case Even:
 *   Find the middle two values in the array, average them, and return the value. Since
 *   this array is even, dividing an array by 1 minus its size may return an unwanted
 *   location. To compensate, divide off the bat to get the first value, then subtract
 *   one position to get the second. Average these and return the median.
 */
double median(double *array, int size) {
	int midIndex = 0;
	double median = 0;

	if((size % 2) != 0) {
		midIndex = ((size - 1) / 2);
		median = *(array+midIndex);
		return median; //Returning middle value
	} else {
		midIndex = size / 2;
		median = ((*(array+midIndex) + *(array+midIndex - 1)) / 2); //Returning middle two values averaged.
		return median;
	}
}

/**
 * Mode is extremely difficult to understand. We first need to create an array to track frequency. This
 * array must be the same size as the original array in case every value is different. Then, loop through
 * the array adding to the frequency array when a known value is hit. Say I have 10 0s in my array, frequency
 * would store the value 10.
 *
 * Next, we need to scan the frequency array for the highest value (should it exist). If no values are
 * repeated, there is no mode and a -1 is returned. Otherwise, the lowest valued mode with highest
 * frequency is returned. While multiple modes are possible, this function is only capable of returning
 * one.
 */
double mode(double *array, int size) {
	double mode = -1;
	int pos = 0, highest;
	int frequency[size];

	for(int i=0; i<size; i++) *(frequency + i) = 0; //Set all frequencies to 0.
	for(int k=0; k<size; k++)
		for(int i=1; i<size; i++)
			if(*(array + k) == *(array + i) && &*(array + k) != &*(array + i)) //Check if a known value has been recorded. (Also prevents checking itself)
				*(frequency + k) += 1; //If so, increment frequency of that value by 1.


	highest = *frequency; //Default highest frequency,

	for(int count=1; count<size; count++) { //Locate the position of the highest number
		if(*(frequency + count) > highest) {
			highest = *(frequency + count); //Triggered if a new highest is found
			pos =+ count; //Find the position in frequency array to insert into numbers array
		}
	}

	for(int i=0; i<size; i++) {
		if(*(frequency + i) != *(frequency + (i + 1)) && (i + 1) < size) { //Check if frequency is larger than one
			mode = *(array + pos);
			return mode; //Return the frequency's coresponding value.
		}
	}
	return mode; //Return the default -1 to say no mode was found.

}

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

int Lab03() {
	string msg;
	cout << "Message: ";
	getline(cin, msg); //Get message to use.

	int key;
	cout << "Key: ";
	cin >> key; //Get key to use

	EncryptString03 es(msg, key); //Initialize EncryptString object
	es.encrypt(); //Encrypt the string
	cout << "\nEncyrpted: " << es.getMessage() << endl; //Output result
	es.decrypt(); //Decrypt the string
	cout << "Decrypted: " << es.getMessage() << endl; //Output result
	return 0;
}

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
	try { //LAB10 error checking
		if(!is8) throw invalid_argument("Error: Password must be 8+ characters!");
		if(!hasU) throw invalid_argument("Error: Password must contain an uppercase letter!");
		if(!hasL) throw invalid_argument("Error: Password must contain an lowercase letter!");
		if(!hasN) throw invalid_argument("Error: Password must contain a number!");
	} catch(const std::invalid_argument& e) {
		cout << e.what() << endl;
	}

	//Return a boolean telling if the password fits the bounds
	return is8 && hasU && hasL && hasN;
}

class EncryptString05A {
private:
	string msg; //Private value may only be accessed by the EncryptString class.
	int key; //Ditto
public:
	EncryptString05A(int key) { //Constructor saves the msg and key within the object
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

			EncryptString05A es(key); //Prepare the EncryptString object
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

class EncryptString05B {
private:
	string msg; //Private value may only be accessed by the EncryptString class.
	int key; //Ditto
public:
	EncryptString05B(int key) { //Constructor saves the msg and key within the object
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

int Lab05B() {
	ifstream inputFile("Lab05B-Input.txt"); //Input file
	ofstream outputFile("Lab05B-Output.txt", ofstream::out | ofstream::trunc); //Output file with automatic clearing

	if(inputFile) {
		if(outputFile) {
			int key = -21;
			do {
				cout << "Please enter a decryption key (-20 to 20): ";
				cin >> key; //Getting a key

				if(!(-20 <= key && key <= 20)) cout << "That is not a valid key!\n\n";
			} while(!(-20 <= key && key <= 20)); //Input validation

			cout << "Decrypting to Lab05B-Output.txt..." << endl;

			EncryptString05B es(key); //Prepare the EncryptString object
			string line = "";
			while(!inputFile.eof()) { //Tick through each line in file
				getline(inputFile, line); //Read the line (with spaces)
				es.setMessage(line); //Set input
				es.decrypt(); //Decrypt input
				outputFile << es.getMessage() << endl; //Output the result
			}

			cout << "Decryption complete.";
			outputFile.close();
		} else cout << "An error occurred while opening the Lab05B-Output.txt file!" << endl; //Error opening output file
		inputFile.close();
	} else cout << "An error occurred while opening the Lab05B-Input.txt file!" << endl; //Error opening input file
	return 0;
}

int Lab06A() {
	ifstream inputFile1("Lab06A-Joke.txt"); //Input file
	ifstream inputFile2("Lab06A-Punchline.txt"); //Input file

	if(inputFile1 && inputFile2) {
		string line = "";
		while(!inputFile1.eof()) { //Tick through each line in file
			getline(inputFile1, line); //Read the line (with spaces)
			cout << line << endl;
		}

		//Determine line count
		int lines = 0;
		while(getline(inputFile2, line)) lines++;
		inputFile2.close();

		//Refresh buffer and get to last line
		ifstream inputFile2("Lab06A-Punchline.txt"); //Input file
		for(int i=0; i<lines; i++) getline(inputFile2, line);

		//Display last line
		Sleep(2000);
		cout << line << endl;
		Sleep(1000);

		//Close streams
		inputFile1.close();
		inputFile2.close();
	} else cout << "An error occurred while opening one of the Lab06A txt files!" << endl; //Error opening input file
	return 0;
}

struct Sales {
	string name;
	int sale[4];
};

int Lab06B() {
	//Register divisions
	Sales no;
	no.name = "North";

	Sales so;
	so.name = "South";

	Sales ea;
	ea.name = "East";

	Sales we;
	we.name = "West";

	Sales sales[4] = {no, so, ea, we};

	//Get input from the user
	for(int i=0; i<4; i++) {
		for(int q=0; q<4; q++) {
			double c = -1;
			do {
				cout << "Please enter sales for the " << sales[i].name << " quarter #" << q + 1 << ": ";
				cin >> c;
			} while(c < 0); //Input validation
			sales[i].sale[q] = c; //Record the input
		}
	}

	ofstream outputFile("Lab06B-Sales.txt", ofstream::out | ofstream::trunc); //Purge existing data
	if(outputFile) {
		for(int i=0; i<4; i++) {
			//Format each line with the data
			string line = sales[i].name + ":";
			for(int q=0; q<4; q++) {
				stringstream s1;
				stringstream s2;
				s1 << (q+1);
				s2 << sales[i].sale[q];

				line += " Q" + s1.str() + ": " + s2.str();
				if(q != 3) line += ",";
			}
			outputFile << line << endl; //Output the record for the division
		}
	}
	else cout << "There was an error logging to Lab06B-Sales.txt!"; //Error with file
	return 0;
}

//Format correct HTML encoding
class ColorCodedStream : public fstream {
public:
	void writeInColor(string str, string aColor) {
		*this << "<span style=\"color:" + aColor + "\"> ";
		*this << str << "<br /> ";
		*this << "</span>\n";
	}
};

void openFile(fstream &file, string descr);

int Lab06C() {
	ColorCodedStream outputFile; //Open our color utility encoder
	fstream redFile, greenFile;
	openFile(redFile, "red"); //Open "red" file
	openFile(greenFile, "green"); //Open "green" file
	openFile(outputFile, "output"); //Open output file

	string redInput, greenInput;
	getline(redFile, redInput); //Open first line in "red" file
	getline(greenFile, greenInput); //Open first line in "green" file

	while(redFile || greenFile) { //Make sure at least one has additional lines to go through
		if(redFile && greenFile) { //If both do, compare the string for alphabetical order. Output higher one first
			if(redInput <= greenInput) {
				outputFile.writeInColor(redInput, "red");
				getline(redFile, redInput);
			} else {
				outputFile.writeInColor(greenInput, "green");
				getline(greenFile, greenInput);
			}
		}
		if(redFile && !greenFile) { //If "red" file is the last with content, outprint it
			outputFile.writeInColor(redInput, "red");
			getline(redFile, redInput);
		}
		if(greenFile && !redFile) { //If "green" file is the last with content, outprint it
			outputFile.writeInColor(greenInput, "green");
			getline(greenFile, greenInput);
		}
	}

	//By this point, the html file has been encoded in a merger of the two txt files
	return 0;
}

void openFile(fstream &file, string descr) {
	string fileName;
	cout << "Enter the name of the " << descr << " file: "; //Prompt for file name
	cin >> fileName;

	if(descr == "output") //Is this the output file? If it is, we want to be able to write to it.
		file.open(fileName.data(), ios::out);
	else
		file.open(fileName.data(), ios::in);

	if(!file) { //Was the file successfully opened? If not, exit
		cout << "Cannot open the file " << fileName;
		exit(1);
	}
}

int Lab07A() {
	sign(5); //Call sign function
	return 0;
}

void sign(int n) {
	if(n > 0) { //When n is bigger than 0
		cout << "No Parking\n"; //Output No Parking
		sign(--n); //Call itself but with n-1
	}
}

int Lab07B() {
	int x = 0, y = 0; //Default values
	cout << "Enter two integers (x y): "; //Prompt for input
	cin >> x >> y; //Get two inputs like 5 and 10.
	cout << x << "*" << y << "=" << multiply(x, y); //Multiply and display result
	return 0;
}

int multiply(int x, int y) {
	if(y < 0) return multiply(x*-1, y*-1);
	else if(y != 0) return x + multiply(x, --y); //Use recursion to add
	else return 0; //Return 0 if y hits 0.
}

class Animal {
public:
	Animal() { cout << "Animal constructor...\n"; }
	virtual ~Animal() { cout << "Animal destructor...\n"; }
	virtual void showSpecies() { cout << "What AM I?!?\n"; }
	virtual void makeSound() { cout << "Coughs\n"; }
};

class Dog: public Animal {
public:
	Dog() { cout << "Dog constructor...\n"; }
	~Dog() { cout << "Dog destructor...\n"; }
	void showSpecies() { cout << "I'm a dog.\n"; }
	void makeSound() { cout << "Woof!\n"; }
};

class Cat: public Animal {
public:
	Cat() { cout << "Cat constructor...\n"; }
	~Cat() { cout << "Cat destructor...\n"; }
	void showSpecies() { cout << "I'm a cat.\n"; }
	void makeSound() { cout << "Meow!\n"; }
};

int Lab08A() {

	Animal *animal = new Animal();
	animal->showSpecies();
	animal->makeSound();

	Dog scout;
	scout.showSpecies();
	scout.makeSound();

	Cat squirt;
	animal = &squirt;
	animal->showSpecies();
	animal->makeSound();
	return 0;
}

class Encryption08B {
protected:
	ifstream inFile;
	ofstream outFile;
	int keyshift;
public:
	Encryption08B(const string& inFileName, const string& outFileName);
	virtual ~Encryption08B();
	virtual void setKey(int& keyshift) { this->keyshift = keyshift; }
	// Pure virtual function
	virtual string transform(string line) const = 0;
	// Do the actual work.
	virtual void encrypt() final;
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption08B::Encryption08B(const string& inFileName, const string& outFileName) {
	this->keyshift = 0;
	inFile.open(inFileName);
	outFile.open(outFileName);
	if(!inFile) {
		cout << "The file " << inFileName << " cannot be opened.";
		exit(1);
	}
	if(!outFile) {
		cout << "The file " << outFileName << " cannot be opened.";
		exit(1);
	}
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption08B::~Encryption08B() {
	inFile.close();
	outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//*****************************************************
void Encryption08B::encrypt() {
	/*
	char ch;
	char transCh;
	inFile.get(ch);
	while(!inFile.fail()) {
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}
	*/

	//Why write gross, under-performing code when you can have clean, cool code

	string line = "";
	while(!inFile.eof()) { //Tick through each line in file
		getline(inFile, line); //Read the line (with spaces)
		outFile << transform(line) << endl; //Output the result
	}
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption: public Encryption08B {
public:
	string transform(string msg) const override {
		string encrypted = "";
		for(char c : msg) {
			c += keyshift;
			while(c > 126) c -= 94; //Let's not have problems with bounds
			while(c < 32) c += 94; //Shall we?
			encrypted += c;
		}
		return encrypted;
	}
	SimpleEncryption(const string& inFileName, const string& outFileName) :
			Encryption08B(inFileName, outFileName) {}
};

int Lab08B() {
	string inFileName, outFileName;
	int keyshift = 0;
	cout << "Enter name of file to encrypt (Lab08B-Input.txt): ";
	cin >> inFileName;
	cout << "Enter name of file to receive the encrypted text (Lab08B-Output.txt): ";
	cin >> outFileName;
	cout << "Enter a key shift: ";
	cin >> keyshift;
	SimpleEncryption obfuscate(inFileName, outFileName);
	obfuscate.setKey(keyshift);
	obfuscate.encrypt();
	return 0;
}

class FileFilter {
private:
	int key;
public:
	FileFilter(int key=2) {
		this->key = key;
	}
	virtual ~FileFilter() {}
	char transform(char ch) const {
		if(ch >= 'a' && ch <= 'z') return ((ch - 'a') + key) % 26 + 'a';
		else if(ch >= 'A' && ch <= 'Z') return ((ch - 'A') + key) % 26 + 'A';
		return '?';
	}
	virtual void doFilter(ifstream &in, ofstream &out) const=0;
};

class NewEncryption: public FileFilter {
public:
	NewEncryption() {}
	NewEncryption(int key) : FileFilter(key) {}
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			string encrypted = "";
			getline(in, line);
			for(char c : line) {
				if(isalpha(c)) encrypted += transform(c);
				else encrypted += transform(c);
			}
			out << encrypted << endl;
		}
	}
};


class UpperCase: public FileFilter {
public:
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			string capped = "";
			getline(in, line);
			for(char c : line) {
				if(isalpha(c)) capped += static_cast<char>(toupper(c));
				else capped += c;
			}
			out << capped << endl;
		}
	}
};

class Copy: public FileFilter {
public:
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			getline(in, line);
			out << line << endl;
		}
	}
};

class BreakSpace: public FileFilter {
public:
	void doFilter(ifstream &in, ofstream &out) const {
		string line = "";
		while(!in.eof()) {
			getline(in, line);
			out << line << " ";
		}
	}
};

int Lab09AB() {
	string inName, outName;
	ifstream inFile;
	ofstream outFile;

	cout << "Enter input file name: ";
	cin >> inName;

	inFile.open(inName);

	if(!inFile) {
		cout << "Cannot open the file " << inName;
		return 0;
	}

	cout << "Enter output file name: ";
	cin >> outName;
	outFile.open(outName);

	if(!outFile) {
		cout << "Cannot create the file " << outName << endl;
		inFile.close();
		return 0;
	}

	int choice;
	NewEncryption e;
	UpperCase uc;
	Copy copy;
	BreakSpace bs;

	cout << "1) Encryption" << endl;
	cout << "2) Transform uppercase" << endl;
	cout << "3) Copy file" << endl;
	cout << "4) Remove line breaks" << endl;
	cout << "  -> ";

	choice = 0;
	cin >> choice;
	switch (choice) {
	case 1:
		int key;
		cout << "Enter Key (2-25): ";
		cin >> key;

		e = NewEncryption(key);
		e.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		outFile.close();
		break;
	case 2:
		uc.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		outFile.close();
		break;
	case 3:
		copy.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		outFile.close();
		break;
	case 4:
		bs.doFilter(inFile, outFile);
		cout << "Success!" << endl;
		break;
	default:
		cout << "Unknown Selection!" << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}

int Lab10A() {
	string sentence = "";
	cout << "Please enter a sentence (pt. 1): ";
	getline(cin, sentence);
	char str[sentence.length() + 1];
	strcpy(str, sentence.c_str());
	reverseArray(str, sentence.length());
	cout << "Reverse! Reverse!" << endl << str << endl;
	return 0;
}

int Lab10B() {
	ifstream inFile;
	vector<string> vect;

	inFile.open("Lab10B-Input.txt");
	if(inFile) {
		for(int x=0; x<25; x++) {
			string line = "";
			if(!inFile.eof()) { //Tick through each line in file
				getline(inFile, line); //Read the line (with spaces)
				vect.push_back(line);
			} else break;
		}

		cout << "The collection has " << vect.size()
				<< " elements. Here they are:\n";
		for(unsigned int x=0; x<vect.size(); x++) cout << vect[x] << " " << endl;

		random_shuffle(vect.begin(), vect.end());
		cout << "The elements have been shuffled:\n";
		for(unsigned int x=0; x<vect.size(); x++) cout << vect[x] << " " << endl;

		sort(vect.begin(), vect.end());
		cout << "The elements have been sorted:\n";
		for(unsigned int x=0; x<vect.size(); x++) cout << vect[x] << " " << endl;

		string val = "int main()";
		if(binary_search(vect.begin(), vect.end(), val))
			cout << "The value '" << val << "' was found in the vector.\n";
		else
			cout << "The value '" << val << "' was not found in the vector.\n";
	} else cout << "Could not locate Lab10B-Input.txt!";
	return 0;
}

int Lab10C() {
	char cArr[5] = {'A', 'B', 'C', 'D', 'E'};
	cout << cArr << endl;
	reverseArray(cArr, 5);
	cout << cArr << endl;

	string sArr[] = {"This ", "Better ", "Work "};
	for(string s : sArr) cout << s;
	reverseArray(sArr, 3);
	cout << endl;
	for(string s : sArr) cout << s;
	return 0;
}

template<class T>
void reverseArray(T arr[], int size) {
	if(size >= 2) {
		swap(arr[0], arr[size-1]);
		reverseArray(arr+1, size-2);
	}
}

struct ListNode {
	double value;
	ListNode *next;

	ListNode(double value, ListNode *next = nullptr) {
		this->value = value;
		this ->next = next;
	}
};

class LinkedList {
private:
	ListNode *head;
public:
	LinkedList() { head = nullptr; }
		~LinkedList();
	void add(double x, bool beginning = false);
	void insert(double x, int pos = 0);
	void remove(double x);
	int search(double x);
	bool isMember(double x);
	void print();
	void reverse();
};

LinkedList::~LinkedList() {
	ListNode *p = head;
	ListNode *n;
	while(p != nullptr) {
		n = p->next;
		delete p;
		p = n;
	}
}

void LinkedList::add(double x, bool beginning) {
	if(!beginning && head != nullptr) {
		ListNode *p = head;
		while(p->next != nullptr) p = p->next;
		p->next = new ListNode(x);
	} else if(head != nullptr) head = new ListNode(x, head);
	else head = new ListNode(x);
}

void LinkedList::insert(double x, int pos) {
	if(head != nullptr && pos > 0) {
		ListNode *p = head;
		while(pos != 1 && p->next != nullptr) {
			p = p->next;
			pos--;
		}
		p->next = new ListNode(x, p->next);
	} else if(head != nullptr) head = new ListNode(x, head);
	else head = new ListNode(x);
}

void LinkedList::remove(double x) {
	if(head != nullptr) {
		ListNode *r;
		if(head->value == x) {
			r = head;
			head = head->next;
			delete r;
		} else {
			ListNode *p = head;
			while(p->next != nullptr && p->next->value != x) p = p->next;

			if(p->next != nullptr) {
				r = p->next;
				p->next = r->next;
				delete r;
			}
		}
	}
}

int LinkedList::search(double x) {
	if(head != nullptr) {
		int pos = 0;
		ListNode *p = head;
		while(p != nullptr) {
			if(p->value == x) return pos;
			p = p->next;
			pos++;
		}
	}
	return -1;
}

bool LinkedList::isMember(double x) {
	return search(x) != -1;
}


void LinkedList::print() {
	if(head != nullptr) {
		ListNode *p = head;
		while(p != nullptr) {
			cout << p->value << endl;
			p = p->next;
		}
	}
}

void LinkedList::reverse() {
	if(head != nullptr) {
		ListNode *p = head;
		ListNode *temp;
		ListNode *rev = nullptr;

		while(p) {
			temp = p;
			p = p->next;
			temp->next = rev;
			rev = temp;
		}
		head = rev;
	}
}

int Lab11A() {
	LinkedList ll;
	ll.add(10);
	ll.add(12.4);
	ll.add(18);
	ll.print();
	ll.reverse();
	cout << endl;
	ll.print();
	cout << endl << "Location of 10: " << ll.search(10) << endl;
	cout << "Location of 7.1: " << ll.search(7.1) << endl << endl;
	ll.insert(5, 1);
	ll.print();

	cout << "====" << endl;
	ListNode *p = new ListNode(56.4);
	p = new ListNode(34.2, p);
	cout << (*p).value << endl << p->value;
	return 0;
}

const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class ImageMap:list<COORD> {
public:
	void add(COORD coordArray[]);
	void add(short *coordAsShorts);
	void displayAt(char ch, int col, int row);
	void displayAt(int col, int row) { displayAt('*', col, row); }
	void eraseAt(int col, int row) { displayAt(' ', col, row); }
};

void ImageMap::add(COORD coordArray[]) {
	for(int k=0; coordArray[k].X != -1; k++) push_back(coordArray[k]);
}

void ImageMap::add(short *coordAsShorts) {
	COORD *pCoord = reinterpret_cast<COORD *>(coordAsShorts);
	add(pCoord);
}

void ImageMap::displayAt(char ch, int col, int row) {
	list<COORD>::iterator iter = this->begin();
	for(; iter != this->end(); iter++) {
		COORD currentPos;
		currentPos.Y = row + iter->Y;
		currentPos.X = col + iter->X;
		SetConsoleCursorPosition(console, currentPos);
		cout << ch << endl;
	}
}

int Lab11B() {
	ImageMap figure1;
	short int p1lowerLeg1[] = {1, 10, 2, 10, 3, 10, -1, -1};
	short int p1thigh1[] = {4, 9, 5, 8, 6, 7, 7, 6, -1, -1};
	short int p1thigh2[] = {6, 7, 7, 8, 8, 9, -1, -1};
	short int p1lowerLeg2[] = {8, 10, 8, 11, -1, -1};
	short int p1torso[] = {8, 5, 9, 4, 10, 3, 11, 2, -1, -1};
	short int p1upperArms[] = {7, 2, 8, 3, 9, 4, 10, 5, 11, 6, -1, -1};
	short int p1foreArm1[] = {12, 5, 13, 4, -1, -1};
	short int p1foreArm2[] = {6, 3, 5, 4, -1, -1};
	short int *figure1AllParts[] = {p1lowerLeg1, p1thigh1, p1thigh2, p1lowerLeg2, p1torso, p1upperArms, p1foreArm1, p1foreArm2, 0};

	int k = 0;
	for(int k=0; figure1AllParts[k] != 0; k++) figure1.add(figure1AllParts[k]);

	ImageMap figure2;
	short int p2LowerLeg1[] = {1, 11, 2, 10, 3, 9, -1, -1};
	short int p2thigh1[] = {3, 9, 3, 8, 3, 7, -1, -1};
	short int p2thigh2[] = {4, 7, 5, 7, 6, 7, -1, -1};
	short int p2LowerLeg2[] = {6, 8, 6, 9, -1, -1};
	short int p2torso[] = {3, 6, 3, 5, 3, 4, 3, 3, 3, 2, 3, 1, -1, -1};
	short int p2UpperArms[] = {1, 3, 2, 3, 4, 3, 5, 3, -1, -1};
	short int p2foreArm1[] = {1, 4, 1, 5, -1, -1};
	short int p2foreArm2[] = {5, 2, 5, 1, -1, -1};
	short int *figure2AllParts[] = {p2LowerLeg1, p2thigh1, p2thigh2, p2LowerLeg2, p2torso, p2UpperArms, p2foreArm1, p2foreArm2, 0};

	for(int k=0; figure2AllParts[k] != 0; k++) figure2.add(figure2AllParts[k]);

	ImageMap figure3;
	short int p3torso[] = {4, 7, 4, 6, 4, 5, 4, 4, 4, 3, 4, 2, 4, 1, -1, -1};
	short int p3thigh1[] = {5, 8, 6, 9, -1, -1};
	short int p3thigh2[] = {3, 8, 2, 9, -1, -1};
	short int p3LowerLeg1[] = {6, 10, 6, 11, -1, -1};
	short int p3LowerLeg2[] = {1, 8, 0, 7, -1, -1};
	short int p3UpperArm1[] = {3, 4, 2, 5, -1, -1};
	short int p3UpperArm2[] = {5, 4, 6, 5, -1, -1};
	short int p3foreArm1[] = {3, 6, 4, 7, -1, -1};
	short int p3foreArm2[] = {7, 4, 8, 3, -1, -1};
	short int *figure3AllParts[] = {p3torso, p3thigh1, p3thigh2, p3LowerLeg1, p3LowerLeg2, p3UpperArm1, p3UpperArm2, p3foreArm1, p3foreArm2, 0};

	for(int k=0; figure3AllParts[k] != 0; k++) figure3.add(figure3AllParts[k]);

	system("cls");
	ImageMap *sequence[3] = {&figure1, &figure2, &figure3};

	k = 0;
	int pos = 0;
	while(pos <= 60) {
		sequence[k]->displayAt(pos, 3);
		sequence[k]->displayAt(pos*2, 12);
		Sleep(400);
		sequence[k]->eraseAt(pos, 3);
		sequence[k]->eraseAt(pos*2, 12);

		k = (k+1) % 3;
		pos += 8;
	}

	while(pos > 0) {
		sequence[k]->displayAt(pos, 3);
		sequence[k]->displayAt(pos*2, 12);
		Sleep(400);
		sequence[k]->eraseAt(pos, 3);
		sequence[k]->eraseAt(pos*2, 12);

		k = (k+1) % 3;
		pos -= 8;
	}
	sequence[k]->displayAt(pos, 3);
	system("cls");
	return 0;
}

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
				queue.push_back(l);
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

class BinarySearchTree {
private:
	struct Branch {
		Branch* left;
		Branch* right;
		double value;
	};
	Branch* head;

	void branch_inorder(Branch* p) {
		if(p != NULL) {
			if(p->left) branch_inorder(p->left);
			cout << " " << p->value << " ";
			if(p->right) branch_inorder(p->right);
		} else return;
	}
	int branch_size(Branch* branch) {
		if(branch == NULL) return 0;
		else return branch_size(branch->left) + branch_size(branch->right) + 1;
	}
	int leaf_size(Branch* branch) {
		if(branch == NULL) return 0;
		if(branch->left == NULL && branch->right == NULL) return 1;
		else return leaf_size(branch->left) + leaf_size(branch->right);
	}
	int branch_height(Branch* branch) {
		if(branch == NULL) return 0;
		else {
			int l = branch_height(branch->left);
			int r = branch_height(branch->right);
			return (l > r ? l : r) + 1;
		}
	}
	int branch_width(Branch* branch, int height) {
		if(branch == NULL) return 0;
		else if(height == 1) return 1;
		else return branch_width(branch->left, (height - 1)) + branch_width(branch->right, (height-1));
	}
public:
	BinarySearchTree() { head = NULL; }
	bool isEmpty() { return head == NULL; }
	void inorder() { branch_inorder(head); }
	void insert(double x);
	void search(double x);

	int size() {
		if(!isEmpty()) return branch_size(head);
		else return 0;
	}
	int leafCount() {
		if(!isEmpty()) return leaf_size(head);
		else return 0;
	}
	int height() {
		if(!isEmpty()) return branch_height(head);
		else return 0;
	}
	int width() {
		if(!isEmpty()) return branch_width(head, height());
		else return 0;
	}
};

void BinarySearchTree::insert(double x) {
	Branch* t = new Branch;
	Branch* parent = NULL;
	t->value = x;
	t->left = NULL;
	t->right = NULL;

	if(!isEmpty()) {
		Branch* curr = head;
		while(curr) {
			parent = curr;
			if(t->value > curr->value) curr = curr->right;
			else curr = curr->left;
		}
		if(t->value < parent->value) parent->left = t;
		else parent->right = t;
	} else head = t;

	cout << "Inserted " << x << " into the tree." << endl;
}

void BinarySearchTree::search(double x) {
	if(!isEmpty()) {
		Branch* curr = head;

		while(curr != NULL) {
			if(curr->value != x) {
				if(x > curr->value) curr = curr->right;
				else curr = curr->left;
			} else {
				cout << "Found " << x << " in Binary Tree." << endl;
				return;
			}
		}
		cout << "Could not find value." << endl;
	} else cout << "Binary Tree is empty." << endl;
}

int Lab14() {
	BinarySearchTree bst;
	int ch = 0;
	double e = 0;

	while(true) {
		cout << endl
			 << "Binary Tree Menu " << endl
			 << "================" << endl
			 << "1) Insert" << endl
			 << "2) Search" << endl
			 << "3) Traverse" << endl
			 << "4) Size" << endl
			 << "5) Leafs" << endl
			 << "6) Height" << endl
			 << "7) Width" << endl
			 << "8) Quit" << endl
			 << "  -> ";

		cin >> ch;

		switch(ch) {
		case 1:
			cout << "Enter a number to insert: ";
			cin >> e;
			bst.insert(e);
			break;
		case 2:
			cout << endl << "Enter a number to search: ";
			cin >> e;
			bst.search(e);
			break;
		case 3:
			cout << endl
				 << "Traversal" << endl
				 << "=========" << endl;
			bst.inorder();
			break;
		case 4:
			cout << "Size: " << bst.size() << endl;
			break;
		case 5:
			cout << "Leafs: " << bst.leafCount() << endl;
			break;
		case 6:
			cout << "Height: " << bst.height() << endl;
			break;
		case 7:
			cout << "Width: " << bst.width() << endl;
			break;
		case 8:
			return 0;
		}
	}
}
