/*
 * Lab07A.cpp
 *
 *  Created on: Feb 22, 2018
 *  Author: Alden Bansemer
 *  Notes:
 *    This program converts the following function into a recursive function:
 *    void sign(int n) {
 *    	while(n > 0) {
 *    		cout << "No Parking\n";
 *    		n--;
 *    	}
 *    }
 */

#include "Lab.h"
#include <iostream>
#include <string>

using namespace std;

void sign(int);

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



