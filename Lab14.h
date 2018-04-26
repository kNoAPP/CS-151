/*
 * Lab14.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <iostream>

using namespace std;

#ifndef LAB14_H
#define LAB14_H

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

#endif /* LAB14_H */
