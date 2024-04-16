#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter()
	: _char(-1), _int(-1), _float(-1), _isDigit(-1) {
	std::cout << "ScalarConverter Constructor called"
			  << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called"
			  << std::endl;
}

void ScalarConverter::display_char(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "char: impossible" << std::endl;
		return;
	}
	// From 65 -> A
	int new_char = std::atoi((to_convert).c_str());
	if (new_char >= MIN_ASCII_VALUE
		&& new_char <= MAX_ASCII_VALUE) {
		_char = static_cast<char>(new_char);
		std::cout << "char: " << _char << std::endl;
		return;
	}
	// From A -> 65
	if (_isDigit) {
		_char = to_convert[0];
		std::cout << "char: " << (int)_char << std::endl;
		return;
	}
	std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::display_int(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "int: impossible" << std::endl;
		return;
	}
	int new_int = std::atoi((to_convert).c_str());
	if (new_int == INT_MAX) {
		std::cout << "int: Number to convert is too big"
				  << std::endl;
		return;
	}
	_int = new_int;
	std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::display_float(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "float: nanf" << std::endl;
		return;
	}
	float new_float = std::atof((to_convert).c_str());
	if (new_float >= MAXFLOAT) {
		std::cout << "float: Number to convert is too big"
				  << std::endl;
		return;
	}
	_float = new_float;
	std::cout << "float: " << _float << "f" << std::endl;
}

void ScalarConverter::convert(std::string to_convert) {
	ScalarConverter converter;

	if (!(isdigit(std::atoi((to_convert).c_str())) != 0)
		&& to_convert.length() == 1) {
		converter._isDigit = true;
	}

	converter.display_char(to_convert);
	converter.display_int(to_convert);
	converter.display_float(to_convert);
	// std::cout << display_double(to_convert) << std::endl;
}
