/*
 * Lab07B.cpp
 *
 *  Created on: Feb 22, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program does multiplication through recursion and addition.
 *    7*3 can be written as 7+7+7, so why not call it recursively?
 *    In my function, 7*3 actually adds like 7+7+7+0.
 */

#include "Lab.h"
#include <iostream>
#include <string>

using namespace std;

int multiply(int, int);

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





