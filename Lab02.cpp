/*
 * Lab02.cpp
 *
 *  Created on: Jan 18, 2018
 *  For: CS-151
 *  Author: Alden Bansemer
 *
 *  Notes:
 *    This program was created to show the relation between pointers and arrays. This
 *    example starts by asking for an amount of people to survey. It makes sure this
 *    number is greater than 0. It then loops through each person and asks for how
 *    many movies that person has seen. These values are stored in an array and accessed
 *    with pointers.
 *
 *    Lastly, this program calculates the mean, median, and mode for each person's
 *    movie count. Each calculation has its own function listed below.
 */

#include "Lab.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void selectionSort(double *array, int size);
double mean(double *array, int size);
double median(double *array, int size);
double mode(double *array, int size);

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

	selectionSort(movies_b, SIZE); //Sort the list in ascending order

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
void selectionSort(double *array, int size) {
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
