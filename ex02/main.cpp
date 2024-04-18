#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

int main() {
	srand(time(
		NULL)); // enables the randomness of the generate function
	for (int j = 0; j < 5; j++) {
		Base* Test = Base::generate();
		if (Test == NULL) {
			return (1);
		}
		Base::identify(Test);
		std::cout << "XXXXXXXXXXXXXXXXXXXXXXXX\n";
		Base::identify(*Test);
		std::cout << "XXXXXXXXXXXXXXXXXXXXXXXX\n";

		delete (Test);

		std::cout << std::endl;
	}
	return (0);
}