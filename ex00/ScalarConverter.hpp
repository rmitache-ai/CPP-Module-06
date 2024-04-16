#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <sstream>
#include <string>

const int MIN_ASCII_VALUE = 32;
const int MAX_ASCII_VALUE = 126;
#define DISPLAY_AS_DOUBLE true
#define DISPLAY_AS_FLOAT false

class ScalarConverter {
private:
	bool _isDigit;
	ScalarConverter();

public:
	~ScalarConverter();

	void displayChar(std::string to_convert) const;
	void displayInt(std::string to_convert) const;
	void displayFloat(std::string to_convert) const;
	void displayDouble(std::string to_convert) const;

	static void convert(std::string to_convert);

	float getFloat() const;
};

#endif