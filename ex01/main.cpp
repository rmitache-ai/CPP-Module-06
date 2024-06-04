#include "Serialization.hpp"
#include <cstdlib>
#include <iostream>

int main() {
	Data data         = {};
	data.random       = rand();

	uintptr_t test    = Serializer::serialize(&data);
	Data*     restore = Serializer::deserialize(test);

	std::cout << "Original random value: " << data.random
			  << std::endl;
	std::cout << "Deserialized random value: " << restore->random
			  << std::endl;

	if (restore != NULL && restore->random == data.random) {
		std::cout
			<< "Serialization and deserialization successful!"
			<< std::endl;
	} else {
		std::cout << "Serialization and deserialization failed!"
				  << std::endl;
	}

	return 0;
}