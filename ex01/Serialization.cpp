#include "Serialization.hpp"
#include <iostream>

Serializer::Serializer() {
	std::cout << "Serializer Constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& copy) {
	if (this != &copy) {
		*this = copy;
	}
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other) {
		return *this;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t newData = reinterpret_cast<uintptr_t>(ptr);
	return (newData);
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* newData = reinterpret_cast<Data*>(raw);
	return (newData);
}