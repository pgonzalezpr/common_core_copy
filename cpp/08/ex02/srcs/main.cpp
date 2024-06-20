#include "MutantStack.hpp"
#include <list>

int main() {

    std::cout << "Test1: Subject" << std::endl;
    std::cout << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    std::cout << "------------------------------" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "===========================" << std::endl;
    std::cout << std::endl;
    std::cout << "Test2: Creating mutant stack copy" << std::endl;
    std::cout << std::endl;

    MutantStack<int> s(mstack);
    MutantStack<int>::iterator it1;
    for (it1 = s.begin(); it1 != s.end(); ++it1) {
        std::cout << *it1 << std::endl;
    }

    std::cout << "===========================" << std::endl;
    std::cout << std::endl;
    std::cout << "Test3: Comparing mutant stack with std::list" << std::endl;
    std::cout << std::endl;

    MutantStack<std::string> ms;
    ms.push("testing");
    ms.push("mutant");
    ms.push("stack");
    ms.push("list"); 

    std::list<std::string> list;
    list.push_back("testing");
    list.push_back("mutant");
    list.push_back("stack");
    list.push_back("list");

    std::cout << "Mutant stack:" << std::endl;
    for (MutantStack<std::string>::iterator it1 = ms.begin(); it1 != ms.end(); ++it1) {
        std::cout << *it1 << std::endl;
    }
    std::cout << std::endl;
    std::cout << "List:" << std::endl;
    for (std::list<std::string>::iterator itl = list.begin(); itl != list.end(); ++itl) {
        std::cout << *itl << std::endl;
    }
}