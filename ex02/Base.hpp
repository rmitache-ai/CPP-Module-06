#pragma once

class A;
class B;
class C;

class Base {
private:
public:
	virtual ~Base();

	static Base* generate(void);
	static void  identify(Base* p);
	static void  identify(Base& p);
};