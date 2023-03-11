#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void){
	std::srand((unsigned)time(NULL));
	int nu = std::rand() % 3;
	Base *ret;

	if (nu == 0){
		return (ret = new A());
	} else if (nu == 1){
		return (ret = new B());
	} else {
		return (ret = new C());
	}
}

void	identify(Base* p){
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
}

void	identify(Base& p){
	try {
		const A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e) {}

	try {
		const B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception & e) {}

	try {
		const C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception & e) {}
}

int main (void){
	Base * ret = generate();
	std::cout << "Random base between A, B and C was generated." << std::endl;
	std::cout << "Base generated: " << std::endl;
	identify(ret);
	identify(ret);
}
