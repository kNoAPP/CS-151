/*
 * Lab14.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: alldo
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree {
private:
	struct Branch {
		Branch* left;
		Branch* right;
		double value;
	};
	Branch* head;

	void inorder(Branch* p) {
		if(p != NULL) {
			if(p->left) inorder(p->left);
			cout << " " << p->value << " ";
			if(p->right) inorder(p->right);
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
	void print_inorder() { inorder(head); }
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
			bst.print_inorder();
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
