#pragma once

#define BASE_HPP

#include <iostream>

class Base {
public:
	virtual ~Base();

	Base* generate(void);
};