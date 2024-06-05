#include "ScalarConverter.hpp"

#include <cmath>
#include <limits>
#include <math.h>
#include <string>

ScalarConverter::ScalarConverter()
	: _isDigit(false), _type() {
	std::cout << "ScalarConverter Constructor called"
			  << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called"
			  << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
	: _isDigit(copy._isDigit), _type(copy._type) {
	std::cout << "Copy constructor called of ScalarConverter"
			  << std::endl;
}

ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		_isDigit = other._isDigit;
		_type    = other._type;
	}
	return *this;
}

int ScalarConverter::getType(void) const { return _type; }

std::ostream& operator<<(std::ostream&          out,
						 const ScalarConverter& foo) {
	return out << foo.getType();
}

void ScalarConverter::displayChar(std::string to_convert) const {
	int char_value = 0;
	if (!_isDigit && to_convert.length() == 1) {
		char_value = to_convert[0];
	} else if (!_isDigit && to_convert.length() != 1
			   && (to_convert.find_first_of('+', 1) == 0U)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		char_value = std::atoi(to_convert.c_str());
	}
	if (char_value > MIN_ASCII_VALUE
		&& char_value < MAX_ASCII_VALUE) {
		std::cout << "char: '" << static_cast<char>(char_value)
				  << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	int    castedToInt    = static_cast<int>(char_value);
	float  castedToFloat  = static_cast<float>(castedToInt);
	double castedToDouble = static_cast<double>(castedToFloat);
	std::cout << "int: " << castedToInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << castedToFloat << 'f' << std::endl;
	std::cout << "double: " << castedToDouble << std::endl;
}

void ScalarConverter::displayInt(std::string to_convert) const {
	long new_int = std::atol(to_convert.c_str());
	if (new_int > std::numeric_limits<int>::max()
		|| new_int < -std::numeric_limits<int>::max()) {
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

bool ScalarConverter::checkFloatNanInff(
	std::string to_convert) const {

	float result = 0;
	if (to_convert == "nanf") {
		result = nanf("");
		std::cout << "char: "
				  << "impossible" << std::endl;
		std::cout << "int: "
				  << "impossible" << std::endl;
		std::cout << "float: " << result << 'f' << std::endl;
		std::cout << "double: " << static_cast<double>(result)
				  << std::endl;
		return true;
	}
	if (to_convert == "-inff" || to_convert == "+inff"
		|| to_convert == "inff") {
		result = std::numeric_limits<float>::infinity();
		std::cout << "char: "
				  << "impossible" << std::endl;
		std::cout << "int: "
				  << "impossible" << std::endl;
		std::cout << "float: " << result << 'f' << std::endl;
		std::cout << "double: " << static_cast<double>(result)
				  << std::endl;
		return true;
	}
	return false;
}

bool ScalarConverter::checkDoubleNanInf(
	std::string to_convert) const {

	double result = 0;
	if (to_convert == "nan") {
		result = nanf("");
		std::cout << "char: "
				  << "impossible" << std::endl;
		std::cout << "int: "
				  << "impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(result)
				  << 'f' << std::endl;
		std::cout << "double: " << result << std::endl;
		return true;
	}
	if (to_convert == "-inf" || to_convert == "+inf"
		|| to_convert == "inf") {
		result = std::numeric_limits<float>::infinity();
		std::cout << "char: "
				  << "impossible" << std::endl;
		std::cout << "int: "
				  << "impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(result)
				  << 'f' << std::endl;
		std::cout << "double: " << result << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::displayFloat(
    std::string to_convert) const {
    if (checkFloatNanInff(to_convert)) {
        return;
    }

    // Strip the 'f' suffix if present
    if (to_convert.back() == 'f' || to_convert.back() == 'F') {
        to_convert.pop_back();
    }

    float new_float = std::atof(to_convert.c_str());
    if (new_float >= MAXFLOAT || new_float <= -MAXFLOAT) {
        std::cout << "float: Out of Range" << std::endl;
        return;
    }

    double result = NAN;
    std::istringstream from_str(to_convert);
    from_str >> result;

    size_t dotIndex = to_convert.find('.');
    std::string afterDot;
    size_t length = 1;
    if (dotIndex != std::string::npos) {
        afterDot = to_convert.substr(dotIndex + 1);
        length = afterDot.length();
    }

    int castedToInt = static_cast<int>(result);
    char castedToChar = static_cast<char>(castedToInt);
    double castedToDouble = static_cast<double>(result);

    if (castedToInt > MIN_ASCII_VALUE && castedToInt < MAX_ASCII_VALUE) {
        std::cout << "char: '" << castedToChar << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    if (result > INT_MIN && result < INT_MAX) {
        std::cout << "int: '" << castedToInt << "'" << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    std::cout << std::fixed
              << std::setprecision(static_cast<int>(length))
              << "float: " << result << 'f' << std::endl;
    std::cout << "double: " << castedToDouble << std::endl;
}

void ScalarConverter::displayDouble(
	std::string to_convert) const {
	if (static_cast<bool>(checkDoubleNanInf(to_convert))) {
		return;
	}
	double new_double = strtod(to_convert.c_str(), NULL);
	std::cout << new_double << std::endl;
	if (new_double >= std::numeric_limits<double>::max()
		|| new_double <= -std::numeric_limits<double>::max()) {
		std::cout << "double: Out of Range" << std::endl;
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
	int  castedToInt  = static_cast<int>(result);
	char castedToChar = static_cast<char>(castedToInt);
	if (castedToInt > MIN_ASCII_VALUE
		&& castedToInt < MAX_ASCII_VALUE) {
		std::cout << "char: '" << castedToChar << "'"
				  << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
	if (result > INT_MIN && result < INT_MAX) {
		std::cout << "int: '" << castedToInt << "'" << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
	if (result < std::numeric_limits<float>::max()
		&& result > -std::numeric_limits<float>::min()) {
		std::cout << std::fixed
				  << std::setprecision(static_cast<int>(length))
				  << "float: " << new_double << 'f' << std::endl;
	} else {
		std::cout << "float: impossible" << std::endl;
	}
	std::cout << std::fixed
			  << std::setprecision(static_cast<int>(length))
			  << "double: " << new_double << std::endl;
}

size_t countValue(std::string to_convert, char value) {
	size_t d_count = std::count(to_convert.begin(),
								to_convert.end(), value);
	return d_count;
}

bool ScalarConverter::specialCases(std::string to_convert) {
	if (countValue(to_convert, '.') > 1) {
		std::cout << "Multiple decimal points found\n";
		_type = -1;
		return true;
	}
	if (countValue(to_convert, 'f') > 1) {
		if (to_convert != "-inff" && to_convert != "+inff" && to_convert != "inff"){
			std::cout << "Multiple floating points found\n";
			_type = -1;
			return true;
		}
	}
	if (to_convert[to_convert.length() - 1] == '.') {
		std::cout << "Error: Double needs to have a number "
					 "after dot."
				  << std::endl;
		_type = -1;
		return true;
	}
	return false;
}

void ScalarConverter::setType(std::string to_convert) {
const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string FALPHABET = "abcdeghijklmnopqrstuvwxyzABCDEGHIJKLMNOPQRSTUVWXYZ";



	if (specialCases(to_convert)) {
		_type = -1;
		return;
	}
	if (!_isDigit && to_convert.length() == 1) {
		_type = 0;
		return;
	}
if (_isDigit && 
    (to_convert.find('.') == std::string::npos) && 
    (to_convert.find_first_of(ALPHABET) == std::string::npos)) {
    _type = 1;
    return;
}
	if ((to_convert.find(".") != std::string::npos
		 && to_convert.find("f") == std::string::npos)
		|| to_convert == "nan" || to_convert == "inf"
		|| to_convert == "-inf" || to_convert == "+inf") {
		_type = 3;
		return;
	}
if ((to_convert.find("f") != std::string::npos ||
	 to_convert.find("F") != std::string::npos) &&
    (to_convert.back() == 'f' || to_convert.back() == 'F') &&
    (to_convert.find_first_of(FALPHABET) == std::string::npos) &&
	 to_convert[to_convert.length() - 2] != '.') {
    _type = 2;
    return;
}
if (to_convert == "-inff" || to_convert == "+inff" || to_convert == "inff"
   || to_convert == "nanf"){
	_type = 2;
	return;
}
	_type = -1;
}

void ScalarConverter::checkIfDigit(std::string to_convert) {
	int count = 0;
	if (to_convert[count] == '-' || to_convert[count] == '+') {
		count++;
	}
	if ((isdigit(to_convert[count]) != 0)) {
		ScalarConverter::_isDigit = true;	
	}
}

void ScalarConverter::convert(std::string to_convert) {
	ScalarConverter converter;

	converter.checkIfDigit(to_convert);
	converter.setType(to_convert);
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
		std::cout << to_convert
				  << ", cannot be converted since is neither "
					 "char, int, float or double! "
				  << std::endl;
	}
}