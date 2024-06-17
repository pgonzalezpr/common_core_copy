#include "Base.hpp"

Base::~Base() {}

Base* generate() {
	std::srand(time(NULL));

	int n = rand() % 3;
	switch (n) {
		case 0:
			std::cout << "Returning an A instance" << std::endl;
			return new A();
		case 1:
			std::cout << "Returning a B instance" << std::endl;
			return new B();
		case 2:
			std::cout << "Returning a C instance" << std::endl;
			return new C();
	}
	return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type: 'A'" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: 'B'" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: 'C'" << std::endl;
    else
        std::cerr << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        A& aref = dynamic_cast<A&>(p);
        (void) aref;
        std::cout << "Type: 'A'" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        B& bref = dynamic_cast<B&>(p);
        (void) bref;
        std::cout << "Type: 'B'" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        C& cref = dynamic_cast<C&>(p);
        (void) cref;
        std::cout << "Type: 'C'" << std::endl;
        return;
    } catch (std::exception& e) {}

    std::cerr << "Unknown type" << std::endl;

}