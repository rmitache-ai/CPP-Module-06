#include "ScalarConverter.hpp"

#include <limits>
#include <math.h>
#include <string>

ScalarConverter::ScalarConverter()
	: _char(0), _int(0), _float(0), _isDigit(false) {
	std::cout << "ScalarConverter Constructor called"
			  << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called"
			  << std::endl;
}

void ScalarConverter::displayChar(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "char: impossible" << std::endl;
		return;
	}
	int int_value = 0;
	if (!_isDigit && to_convert.length() == 1) {
		int_value = to_convert[0];
	} else {
		int_value = std::atoi(to_convert.c_str());
		if (int_value < MIN_ASCII_VALUE
			|| int_value > MAX_ASCII_VALUE) {
			_char = -1;
			std::cout << "char: Non displayable" << std::endl;
			return;
		}
	}
	_char = static_cast<char>(int_value);
	std::cout << "char: '" << _char << "'" << std::endl;
}

void ScalarConverter::displayInt(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "int: impossible" << std::endl;
		return;
	}
	int new_int = std::atoi((to_convert).c_str());
	if (new_int >= std::numeric_limits<int>::max()
		|| new_int <= std::numeric_limits<int>::min()) {
		std::cout
			<< "int: Number to convert is too big or too small"
			<< std::endl;
		return;
	}
	if (!_isDigit && to_convert.length() == 1) {
		new_int = static_cast<int>(to_convert[0]);
	} else if (!_isDigit && to_convert.length() > 1) {
		std::cout << "int: Non displayable" << std::endl;
		return;
	}
	_int = new_int;
	std::cout << "int: " << _int << std::endl;
}

static void outputWithDecimal(std::string input) {
	float              f = NAN;
	std::istringstream from_str;
	from_str.str(input);
	from_str >> f;
	size_t      dotIndex = input.find('.');
	std::string afterDot
		= input.substr(dotIndex + 1, std::string::npos);
	size_t length = afterDot.length();

	std::cout << std::fixed
			  << std::setprecision(static_cast<int>(--length))
			  << "float: " << f << 'f' << std::endl;
}

void ScalarConverter::displayFloat(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "float: nanf" << std::endl;
		return;
	}
	float new_float = std::atof((to_convert).c_str());
	if (new_float >= std::numeric_limits<float>::max()
		|| new_float <= std::numeric_limits<float>::min()) {
		std::cout
			<< "float: Number to convert is too big or too small"
			<< std::endl;
		return;
	}
	if (!_isDigit && to_convert.length() == 1) {
		new_float = static_cast<float>(to_convert[0]);
	} else if (!_isDigit && to_convert.length() > 1) {
		std::cout << "float: Non displayable" << std::endl;
		return;
	}
	_float = new_float;
	outputWithDecimal(to_convert);
}

void ScalarConverter::displayDouble(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "double: nan" << std::endl;
		return;
	}
	double new_double = std::atof((to_convert).c_str());
	if (new_double >= std::numeric_limits<double>::max()
		|| new_double <= std::numeric_limits<double>::min()) {
		std::cout << "double: Number to convert is too big or "
					 "too small"
				  << std::endl;
		return;
	}
	if (!_isDigit && to_convert.length() == 1) {
		new_double = static_cast<double>(to_convert[0]);
	} else if (!_isDigit && to_convert.length() > 1) {
		std::cout << "double: Non displayable" << std::endl;
		return;
	}
	_double = new_double;
	outputWithDecimal(to_convert);
}

void ScalarConverter::convert(std::string to_convert) {
	ScalarConverter converter;

	if ((isdigit(to_convert[0]) != 0)) {
		converter._isDigit = true;
	}

	converter.displayChar(to_convert);
	converter.displayInt(to_convert);
	converter.displayFloat(to_convert);
	converter.displayDouble(to_convert);
}