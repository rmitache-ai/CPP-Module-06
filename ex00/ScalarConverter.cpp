#include "ScalarConverter.hpp"
#include <cstddef>

ScalarConverter::ScalarConverter()
	: _isDigit(false), _type() {
	std::cout << "ScalarConverter Constructor called"
			  << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called"
			  << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter& copy)
	: _isDigit(copy._isDigit), _type(copy._type) {

	std::cout << "Copy constructor called of Animal"
			  << std::endl;
}

ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& other) {
	_type = other._type;
	return *this;
}

int ScalarConverter::getType(void) const { return _type; }

std::ostream& operator<<(std::ostream&          out,
						 const ScalarConverter& foo) {
	return out << foo.getType();
}

void ScalarConverter::displayChar(std::string to_convert) const {
	if (to_convert == "nan") {
		std::cout << "char: impossible" << std::endl;
		return;
	}
	int char_value = 0;
	if (!_isDigit && to_convert.length() == 1) {
		char_value = to_convert[0];
	} else if (!_isDigit && to_convert.length() != 1) {
		std::cout << "char: Non displayable" << std::endl;
		return;
	} else {
		char_value = std::atoi(to_convert.c_str());
		if (char_value < MIN_ASCII_VALUE
			|| char_value > MAX_ASCII_VALUE) {
			std::cout << "char: Non displayable" << std::endl;
			return;
		}
	}
	std::cout << "char: '" << static_cast<char>(char_value)
			  << "'" << std::endl;
	int    castedToInt    = static_cast<int>(char_value);
	float  castedToFloat  = static_cast<float>(castedToInt);
	double castedToDouble = static_cast<double>(castedToFloat);
	std::cout << "char: "
			  << "'" << char_value << "'" << std::endl;
	std::cout << "int: " << castedToInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << castedToFloat << 'f' << std::endl;
	std::cout << "double: " << castedToDouble << std::endl;
}

void ScalarConverter::displayInt(std::string to_convert) const {
	if (to_convert == "nan") {
		std::cout << "int: impossible" << std::endl;
		return;
	}
	long new_int = std::atol(to_convert.c_str());
	if (new_int >= std::numeric_limits<int>::max()
		|| new_int <= std::numeric_limits<int>::min()) {
		std::cout << "int: Number out of Range" << std::endl;
		return;
	}
	if (!_isDigit && to_convert.length() == 1) {
		new_int = static_cast<int>(to_convert[0]);
	} else if (!_isDigit && to_convert.length() > 1) {
		std::cout << "int: Non displayable" << std::endl;
		return;
	}
	if (new_int < MIN_ASCII_VALUE || new_int > MAX_ASCII_VALUE) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(new_int)
				  << "'" << std::endl;
	}
	float  castedToFloat  = static_cast<float>(new_int);
	double castedToDouble = static_cast<double>(new_int);
	std::cout << "int: " << static_cast<int>(new_int)
			  << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << castedToFloat << "f" << std::endl;
	std::cout << "double: " << castedToDouble << std::endl;
}

void ScalarConverter::displayFloat(
	std::string to_convert) const {
	if (to_convert == "nan") {
		std::cout << "float: nanf" << std::endl;
		return;
	}
	float new_float = std::atof((to_convert).c_str());
	if (new_float >= MAXFLOAT || new_float <= -MAXFLOAT) {
		std::cout << "float: Number to convert is too big "
					 "or too small"
				  << std::endl;
		return;
	}
	double             result = NAN;
	std::istringstream from_str(to_convert);
	from_str >> result;
	size_t      dotIndex = to_convert.find('.');
	std::string afterDot;
	size_t      length = 1;
	afterDot           = to_convert.substr(dotIndex + 1);
	length             = afterDot.length();
	if (afterDot[length - 1] == 'f') {
		length--;
	}
	int    castedToInt    = static_cast<int>(result);
	char   castedToChar   = static_cast<char>(castedToInt);
	double castedToDouble = static_cast<double>(result);
	printCahr(castedToInt, castedToChar);
	printInt(static_cast<long>(f), castedToInt);
	std::cout << std::fixed
			  << std::setprecision(static_cast<int>(length))
			  << "float: " << result << 'f' << std::endl;
	std::cout << "double: " << castedToDouble << std::endl;
}

void ScalarConverter::displayDouble(
	std::string to_convert) const {
	if (to_convert == "nan") {
		std::cout << "double: nan" << std::endl;
		return;
	}
	double new_double = std::atof((to_convert).c_str());
	if (new_double >= std::numeric_limits<double>::max()
		|| new_double <= -std::numeric_limits<double>::max()) {
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
}

size_t decimalCount(std::string to_convert) {
	size_t d_count
		= std::count(to_convert.begin(), to_convert.end(), '.');
	return d_count;
}

void ScalarConverter::setType(std::string to_convert) {

	if (decimalCount(to_convert) > 1) {
		std::cout << "Multiple decimal points found\n";
		_type = -1;
		return;
	}
	if (!_isDigit && to_convert.length() == 1) {
		_type = 0;
		std::cout << "Calling char\n";
		return;
	}
	if (_isDigit
		&& (to_convert.find(".") == std::string::npos)) {
		_type = 1;
		std::cout << "Calling int\n";
		return;
	}
	if (to_convert.find("f") != std::string::npos) {
		_type = 2;
		std::cout << "float found\n";
		return;
	}
	if (to_convert.find(".") != std::string::npos
		&& to_convert.find("f") == std::string::npos) {
		_type = 3;
		std::cout << "Calling double\n";
		return;
	}
	std::cout << to_convert
			  << ", cannot be converted since is neither "
				 "char, int, float or double! "
			  << std::endl;
	_type = -1;
}

// TODO: inf, detect which type is passed, then call the others inside those. CHECK SUBJECT FILE
void ScalarConverter::convert(std::string to_convert) {
	ScalarConverter converter;

	int count = 0;
	if (to_convert[count] == '-') {
		count++;
	}
	if ((isdigit(to_convert[count]) != 0)) {
		converter._isDigit = true;
	}
	converter.setType(to_convert);
	std::cout << converter.getType() << std::endl;
	switch (converter._type) {
	case 0:
		converter.displayChar(to_convert);
		break;
	case 1:
		converter.displayInt(to_convert);
		break;
	case 2:
		converter.displayFloat(to_convert);
		break;
	case 3:
		converter.displayDouble(to_convert);
		break;
	default:
		break;
	}
}
