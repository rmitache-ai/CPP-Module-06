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

class ScalarConverter {
private:
	char   _char;
	int    _int;
	float  _float;
	double _double;
	bool   _isDigit;

public:
	ScalarConverter();
	~ScalarConverter();

	void displayChar(std::string to_convert);
	void displayInt(std::string to_convert);
	void displayFloat(std::string to_convert);
	void displayDouble(std::string to_convert);

	static void convert(std::string to_convert);

	float getFloat() const;
};

#endif