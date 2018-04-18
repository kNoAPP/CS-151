/*
 * Lab01.cpp
 *
 *  Created on: Jan 11, 2018
 *  For: CS-151
 *  Author: Alden Bansemer
 *
 *  Notes:
 *    Bubble Sort
 *    A bubble sort is a sorting algorithm that compares two values
 *    and swaps them if one value compares (> or <) the other.
 *
 *    Swaps:
 *      Best Case: 0 swaps
 *      Av. Case: 1/4 (n-1)n
 *      Worst Case: 1/2 (n-1)n
 *
 *    Complexity:
 *      Best Case: O(n)
 *      Av. Case: O(n^2)
 *      Worst Case: O(n^2)
 *
 *    Selection Sort
 *    A selection sort is a sorting algorithm that compares a value
 *    to the (lowest/highest) known index value. If the value is
 *    (lower/higher), it is moved to the front of the array
 *
 *    Swaps:
 *      Best Case: 0 swaps
 *      Av. Case: (n-1)/2
 *      Worst Case: n-1
 *
 *    Complexity:
 *      Best Case: O(n)
 *      Av. Case: O(n)
 *      Worst Case: O(n)
 *
 *    Big "O" Notation
 *    Big O Notation refers to the complexity or performance of an
 *    algorithm when run. There are several standard growth models.
 *    Here are just five basic ones:
 *
 *    O(1) -   An algorithm will always take the same amount of time to
 *               complete.
 *    O(n) -   An algorithm that decays linearly in performance. The
 *               performance is usually directly proportional to the number
 *               of iterations.
 *    O(n^2) - An algorithm that decays on a bell-curve in performance. The
 *               performance is usually directly proportional to the squared
 *               number of iterations, a likely cause being nested for loops.
 *    O(2^n) - An algorithm that decays exponentially in performance. The
 *               performance is usually directly proportional to two to the
 *               power of iterations, a likely cause being recursive algorithms.
 *    O(n!) -  An algorithm that decays factorially in performance. One example
 *               is the traveling salesman problem. As the number of cities
 *               increases, the number of possible outcomes increases on a
 *               factorial.
 */

#include "Lab.h"
#include <iostream>

using namespace std;

int bubbleSort(int[], int);
int selectionSort(int[], int);

int Lab01() {
	const int SIZE = 20;

	int bubble[SIZE] = {20, 18, 19, 17, 16, 14, 15, 13, 11, 12, 10, 8, 9, 7, 5, 6, 4, 2, 3, 1};
	cout << "Bubble: " << bubbleSort(bubble, SIZE) << " swaps \n";

	int selection[SIZE] = {20, 18, 19, 17, 16, 14, 15, 13, 11, 12, 10, 8, 9, 7, 5, 6, 4, 2, 3, 1};
	cout << "Selection: " << selectionSort(selection, SIZE) << " swaps \n";
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

int selectionSort(int array[], int size) {
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
