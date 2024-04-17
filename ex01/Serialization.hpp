#ifndef SERIALIZATION_HPP

#define SERIALIZATION_HPP
#include <stdint.h>

struct Data {
	int random;
};

class Serializer {

private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& other);

public:
	static uintptr_t serialize(Data* ptr);
	static Data*     deserialize(uintptr_t raw);
};

#endif