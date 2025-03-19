#include <iostream>
#include "Base.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	Base *ptr = generate();
	std::cout << "Identifying via pointer: ";
	identify(ptr);
	std::cout << "Identifying via reference: ";
	identify(*ptr);
	delete ptr;
	return (0);
}