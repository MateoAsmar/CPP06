#include <iostream>
#include<cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(NULL));
	int r = std::rand() % 3;
	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base & p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
		return ;
	} catch (...) { }
	try {
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
		return ;
	} catch (...) { }
	try {
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
		return ;
	} catch (...) { }
	std::cout << "Unknown" << std::endl;
}