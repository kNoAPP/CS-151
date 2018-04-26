/*
 * Lab08A.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <iostream>

using namespace std;

#ifndef LAB08A_H
#define LAB08A_H

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

#endif /* LAB08A_H */
