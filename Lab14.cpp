/*
 * Lab14.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include "Lab14.h"
#include <iostream>

using namespace std;

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

