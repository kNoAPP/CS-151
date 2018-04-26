/*
 * Lab11A.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#ifndef LAB11A_H
#define LAB11A_H

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

#endif /* LAB11A_H */
