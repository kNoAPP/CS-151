/*
 * Lab08A.cpp
 *
 *  Created on: Mar 1, 2018
 *  Author: Alden Bansemer
 *  Notes:
 */

#include <iostream>
using namespace std;

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

int Lab08A() {

	Animal *animal = new Animal();
	animal->showSpecies();
	animal->makeSound();

	Dog scout;
	scout.showSpecies();
	scout.makeSound();

	Cat squirt;
	animal = &squirt;
	animal->showSpecies();
	animal->makeSound();
	return 0;
}
