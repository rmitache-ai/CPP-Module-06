#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>

class Base;

Base* generate(void) {

	switch (rand() % 3) {
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		std::cout << "Failed to randomize" << std::endl;
		return (NULL);
	}
}

void identify(Base* p) {
	A* a_class = dynamic_cast<A*>(p);
	if (a_class != NULL) {
		std::cout << "\033[32m";
		std::cout
			<< "A is the actual type of object pointed by P\n";
		std::cout << "\033[0m";
	}

	B* b_class = dynamic_cast<B*>(p);
	if (b_class != NULL) {
		std::cout << "\033[32m";
		std::cout
			<< "B is the actual type of object pointed by P\n";
		std::cout << "\033[0m";
	}

	C* c_class = dynamic_cast<C*>(p);
	if (c_class != NULL) {
		std::cout << "\033[32m";
		std::cout
			<< "C is the actual type of object pointed by P\n";
		std::cout << "\033[0m";
	}
}

void identify(Base& p) {
	try {
		A& a_class = dynamic_cast<A&>(p);
		(void)a_class;
		std::cout << "\033[32m";
		std::cout
			<< "A is the actual type of object pointed by P\n";
		std::cout << "\033[0m";
		return;
	} catch (std::exception&) {
		try {
			B& b_class = dynamic_cast<B&>(p);
			(void)b_class;
			std::cout << "\033[32m";
			std::cout << "B is the actual type of object "
						 "pointed by P\n";
			std::cout << "\033[0m";
		} catch (std::exception&) {
			try {
				C& c_class = dynamic_cast<C&>(p);
				(void)c_class;
				std::cout << "\033[32m";
				std::cout << "C is the actual type of object "
							 "pointed by P\n";
				std::cout << "\033[0m";
				return;
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
}

int main() {
	srand(time(NULL));
	for (int j = 0; j < 5; j++) {
		Base* Test = generate();
		if (Test == NULL) {
			return (1);
		}
		identify(Test);
		std::cout << "XXXXXXXXXXXXXXXXXXXXXXXX\n";
		identify(*Test);
		std::cout << "XXXXXXXXXXXXXXXXXXXXXXXX\n";

		delete (Test);

		std::cout << std::endl;
	}
	return (0);
}