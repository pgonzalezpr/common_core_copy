#include "Span.hpp"

void testEpilogue() {
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << std::endl;
}

int main() {

    std::cout << "Test 1: Subject" << std::endl;
    std::cout << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "sp => ";
    sp.print();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    testEpilogue();

    std::cout << "Test 2: Adding elements beyond capacity" << std::endl;
    std::cout << std::endl;

    Span sp2 = Span(3);
    try {
        sp2.addNumber(6);
        sp2.addNumber(-2);
        sp2.addNumber(11);
        sp2.addNumber(8);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "sp2 => ";
    sp2.print();
    testEpilogue();

    std::cout << "Test 3: Adding number range" << std::endl;
    std::cout << std::endl;

    std::vector<int> v1;
    v1.push_back(5);
    v1.push_back(-7);
    v1.push_back(15);
    v1.push_back(33);
    v1.push_back(-4);

    Span sp3 = Span(10);
    try {
        sp3.addNumber(6);
        sp3.addNumber(-2);
        sp3.addNumber(11);
        sp3.addNumber(8);
        sp3.addNumberRange(v1.begin(), v1.end());
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    sp3.print();
    testEpilogue();

    std::cout << "Test 4: Adding number range beyond capacity" << std::endl;
    std::cout << std::endl;

    try {
        sp3.addNumberRange(v1.begin(), v1.end());
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    sp3.print();
    testEpilogue();

    std::cout << "Test 5: Testing shortest and longest span in a large collection" << std::endl;
    std::cout << std::endl;

    unsigned int size = 10000;
    Span sp4 = Span(size);
    std::srand(std::time(0));
    for (unsigned int i = 0; i < size; i++) {
        sp4.addNumber(std::rand());
    }

    std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
    testEpilogue();
    return 0;
}