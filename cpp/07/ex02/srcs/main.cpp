#include "Array.hpp"

typedef struct person {
    std::string name;
    int age;
} Person;

void testEpilogue() {
    std::cout << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& obj) {
    os << "Name: " << obj.name << ", Age: " << obj.age << std::endl;
    return os;
}

int main () {
    std::cout << "Test 1: Creating arrays of different types" << std::endl;
    std::cout << std::endl;

    Array<int> myArray1;
    myArray1.print();
    Array<double> myArray2(5);
    myArray2.print();
    Array<std::string> myArray3(3);
    myArray3.print();
    testEpilogue();

    std::cout << "Test 2: Filling arrays" << std::endl;
    std::cout << std::endl;

    Array<int> myArray4(5);
    try {
        myArray4[0] = 5;
        myArray4[1] = 4;
        myArray4[2] = 3;
        myArray4[3] = 2;
        myArray4[4] = 1;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    myArray4.print();

    Array<std::string> myArray5(3);
    try {
        myArray5[0] = "hello";
        myArray5[1] = "array";
        myArray5[2] = "test";
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    myArray5.print();
    testEpilogue();

    std::cout << "Test 3: Accesing array out of bounds" << std::endl;
    std::cout << std::endl;

    Array<float> myArray6(3);
    try {
        myArray6[0] = 1.5;
        myArray6[7] = 3.4;
        myArray6[1] = 2.3;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    myArray6.print();
    testEpilogue();

    std::cout << "Test4: Testing copy constructor" << std::endl;
    std::cout << std::endl;

    Array<std::string> myArray7(5);
    try {
        myArray7[0] = "zero";
        myArray7[1] = "one";
        myArray7[2] = "two";
        myArray7[3] = "three";
        myArray7[4] = "four";
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Original array => ";
    myArray7.print();
    Array<std::string> myArray8(myArray7);
    std::cout << "Copied array => ";
    myArray8.print();

    std::cout << std::endl;
    std::cout << "Modyfing copied array to test deep copy" << std::endl;
    myArray8[3] = "modified three";

    std::cout << "Original array => ";
    myArray7.print();
    std::cout << "Copied array => ";
    myArray8.print();
    testEpilogue();

    std::cout << "Test5: Creating array of structs" << std::endl;
    std::cout << std::endl;

    Person laura = {"Laura", 20};
    Person maria = {"Maria", 18};
    Person andres = {"Andres", 25};

    Array<Person> myArray9(3);
    try {
        myArray9[0] = laura;
        myArray9[1] = maria;
        myArray9[2] = andres;

        std::cout << myArray9[0] << myArray9[1] << myArray9[2];
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}