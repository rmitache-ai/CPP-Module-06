#include "Serialization.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	Data data   = {};
	data.random = rand();

	// Serialize data to uintptr_t
	uintptr_t test = Serializer::serialize(&data);

	std::cout << "Serialized: " << test << std::endl;

	// Deserialize data to Data*
	Data* restore = Serializer::deserialize(test);
	std::cout << "Deserialized: " << restore << std::endl;

	// Check if data is successfully restored
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