#include "identify.hpp"

Base *generate(void) {
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<> dist(0, 2);

	int random = dist(gen);
	switch (random) {
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void identify(Base &p) {
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A\n";
	} catch (std::bad_cast &e) {}
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "B\n";
	} catch (std::bad_cast &e) {}
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "C\n";
	} catch (std::bad_cast &e) {}
}
