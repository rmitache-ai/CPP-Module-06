#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base::~Base() {
	std::cout << "Base Destructor called" << std::endl;
}

Base* Base::generate(void) {

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

void Base::identify(Base* p) {
	A* a_class = dynamic_cast<A*>(p);
	if (a_class != NULL) {
		std::cout << "\033[32m"; // Set color to green
		std::cout
			<< "A is the actual type of object pointed by P\n";
		std::cout << "\033[0m"; // Reset color
	}

	B* b_class = dynamic_cast<B*>(p);
	if (b_class != NULL) {
		std::cout << "\033[32m"; // Set color to green
		std::cout
			<< "B is the actual type of object pointed by P\n";
		std::cout << "\033[0m"; // Reset color
	}

	C* c_class = dynamic_cast<C*>(p);
	if (c_class != NULL) {
		std::cout << "\033[32m"; // Set color to green
		std::cout
			<< "C is the actual type of object pointed by P\n";
		std::cout << "\033[0m"; // Reset color
	}
}

void Base::identify(Base& p) {
	try {
		A& a_class = dynamic_cast<A&>(p);
		std::cout << "\033[32m"; // Set color to green
		std::cout
			<< "A is the actual type of object pointed by P\n";
		std::cout << "\033[0m"; // Reset color
		return;
	} catch (std::bad_cast&) {
		std::cout << "\033[91m"; // Set color to light red
		std::cout << "A is not the actual type of the object "
					 "pointed by P\n";
		std::cout << "\033[0m"; // Reset color
	}
	try {
		B& b_class = dynamic_cast<B&>(p);
		std::cout << "\033[32m"; // Set color to green
		std::cout
			<< "B is the actual type of object pointed by P\n";
		std::cout << "\033[0m"; // Reset color
		return;
	} catch (std::bad_cast&) {
		std::cout << "\033[91m"; // Set color to light red
		std::cout << "B is not the actual type of the object "
					 "pointed by P\n";
		std::cout << "\033[0m"; // Reset color
	}
	try {
		C& c_class = dynamic_cast<C&>(p);
		std::cout << "\033[32m"; // Set color to green
		std::cout
			<< "C is the actual type of object pointed by P\n";
		std::cout << "\033[0m"; // Reset color
		return;
	} catch (std::bad_cast&) {
		std::cout << "\033[91m"; // Set color to light red
		std::cout << "C is not the actual type of the object "
					 "pointed by P\n";
		std::cout << "\033[0m"; // Reset color
	}
}