#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <ostream>
#include <sstream>
#include <string>

const int MIN_ASCII_VALUE = 32;
const int MAX_ASCII_VALUE = 126;
#define DISPLAY_AS_DOUBLE true
#define DISPLAY_AS_FLOAT false

class ScalarConverter {
private:
	bool _isDigit;
	int  _type;
	ScalarConverter();

public:
	~ScalarConverter();
	ScalarConverter(ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& other);

	void displayChar(std::string to_convert) const;
	void displayInt(std::string to_convert) const;
	void displayFloat(std::string to_convert) const;
	void displayDouble(std::string to_convert) const;

	static void convert(std::string to_convert);

	float getFloat() const;
	void  setType(std::string to_convert);
	void  checkIfDigit(std::string to_convert);
	bool  specialCases(std::string to_convert);
	bool  checkFloatNanInff(std::string to_convert) const;
	bool  checkDoubleNanInf(std::string to_convert) const;
	int   getType() const;
};

std::ostream& operator<<(std::ostream&          out,
						 const ScalarConverter& foo);

#endif