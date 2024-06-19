#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    return std::find(container.begin(), container.end(), value);    
}

template <typename T>
void easyfindTest(T& container, int value) {
    typename T::iterator it = easyfind(container, value);
    std::cout << "Value " << value;
    if (it == container.end()) 
        std::cout << " not found" << std::endl;
    else
        std::cout << " found" << std::endl;
}

int main() {

    std::list<int> myList;

    for (int i = 0; i < 10; ++i) {
        myList.push_back(i * 3);
    }
    std::cout << "myList: ";

    for (std::list<int>::iterator i = myList.begin(); i != myList.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    easyfindTest(myList, -1);
    easyfindTest(myList, 9);
    easyfindTest(myList, 15);
    easyfindTest(myList, 22);
    easyfindTest(myList, 0);
    easyfindTest(myList, 27);
}