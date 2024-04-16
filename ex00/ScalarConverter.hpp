#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <math.h>

const int MIN_ASCII_VALUE = 32;
const int MAX_ASCII_VALUE = 126;

class ScalarConverter {
private:
	char  _char;
	int   _int;
	float _float;
	// double _double;
	bool _isDigit;

public:
	ScalarConverter();
	~ScalarConverter();

	void        display_char(std::string to_convert);
	void        display_int(std::string to_convert);
	void        display_float(std::string to_convert);
	static void convert(std::string to_convert);
};

#endif