#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
	: _char(-1) {
	std::cout << "ScalarConverter Constructor called"
			  << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called"
			  << std::endl;
}

void ScalarConverter::display_char(std::string to_convert) {
	int new_char = std::atoi((to_convert).c_str());

	// From A -> 65
	if (new_char >= MIN_ASCII_VALUE
		&& new_char <= MAX_ASCII_VALUE) {
		_char = static_cast<char>(new_char);
		std::cout << "char: " << _char << std::endl;
		return;
	}
	// From 65 -> A
	std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convert(std::string to_convert) {
	ScalarConverter converter;

	converter.display_char(to_convert);
	// std::cout << display_int(to_convert) << std::endl;
	// std::cout << display_float(to_convert) << std::endl;
	// std::cout << display_double(to_convert) << std::endl;
}
