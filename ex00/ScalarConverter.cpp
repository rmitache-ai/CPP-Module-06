#include "ScalarConverter.hpp"
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

static void outputWithDecimal(float passedFloat) {
	std::stringstream ss;
	ss << passedFloat;
	std::string floatString = ss.str();
	double      floatArray[2];

	size_t pos = floatString.find('.');
	if (pos != std::string::npos) {
		std::string intPart        = floatString.substr(0, pos);
		std::string fracPart       = floatString.substr(pos + 1);
		double      integerPart    = atof(intPart.c_str());
		double      fractionalPart = atof(fracPart.c_str());
		floatArray[0]              = integerPart;
		floatArray[1]              = fractionalPart;
	} else {
		floatArray[0] = passedFloat;
		floatArray[1] = 0.0;
	}
	std::cout << "float: " << floatArray[0] << "."
			  << floatArray[1] << "f" << std::endl;
}

void ScalarConverter::displayFloat(std::string to_convert) {
	if (to_convert == "nan") {
		std::cout << "float: impossible" << std::endl;
		return;
	}
	float new_float = std::atof((to_convert).c_str());
	if (new_float >= std::numeric_limits<float>::max()) {
		std::cout << "int: Number to convert is too big"
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
	outputWithDecimal(_float);
}

void ScalarConverter::displayDouble(std::string to_convert) {}

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