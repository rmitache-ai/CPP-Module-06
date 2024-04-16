#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
	: _char(0), _int(0), _float(0), _isDigit(false) {
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

void ScalarConverter::display_int(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "int: impossible" << std::endl;
		return;
	}
	int new_int = std::atoi((to_convert).c_str());
	if (new_int >= std::numeric_limits<int>::max()) {
		std::cout << "int: Number to convert is too big"
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

void ScalarConverter::display_float(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "float: nanf" << std::endl;
		return;
	}
	if (_isDigit) {
		_float = to_convert[0];
		std::cout << "float: " << (float)_float << "f"
				  << std::endl;
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

	if ((isdigit(to_convert[0]) != 0)) {
		converter._isDigit = true;
	}

	converter.display_char(to_convert);
	converter.display_int(to_convert);
	converter.display_float(to_convert);
	// std::cout << display_double(to_convert) << std::endl;
}
