/*
 * Lab06C.h
 *
 *  Created on: Apr 26, 2018
 *      Author: alldo
 */

#include <fstream>
#include <string>

using namespace std;

#ifndef LAB06C_H
#define LAB06C_H

//Format correct HTML encoding
class ColorCodedStream : public fstream {
public:
	void writeInColor(string str, string aColor) {
		*this << "<span style=\"color:" + aColor + "\"> ";
		*this << str << "<br /> ";
		*this << "</span>\n";
	}
};

#endif /* LAB06C_H */
