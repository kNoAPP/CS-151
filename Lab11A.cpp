/*
 * Lab11A.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include "Lab11A.h"
#include <iostream>

using namespace std;

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

