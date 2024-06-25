#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>

template<typename Container>
void printContainer(Container c) {
    size_t counter = 0;
    for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
        counter++;
        if (counter == 10)
            break;
    }
    if (counter < c.size())
        std::cout << " [...]";
    std::cout << std::endl;
}

template<typename Container>
double runSorter(std::vector<int>& elements, Container& c) {
    
    typedef std::vector<int>::iterator v_it;
    clock_t start, end;
    PmergeMe<Container> sorter;

    start = clock();
    for (v_it it = elements.begin(); it != elements.end(); ++it) {
        c.push_back(*it);
    }
    sorter.fordJohnsonSort(c);
    end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cerr << "Empty argument list" << std::endl;
        return 1;
    }

    std::vector<int> elements;
    int val;
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        ss >> val;
        if (ss.fail() || !ss.eof() || val < 0) {
            std::cerr << "Bad argument: " << argv[i] << std::endl;
            return 1;
        }
        elements.push_back(val);
    }
    std::cout << "Before: ";
    printContainer(elements);

    std::vector<int> vec;
    std::list<int> lst;
    double vec_time = runSorter(elements, vec);
    double lst_time = runSorter(elements, lst);

    std::cout << "After: ";
    printContainer(vec);
    std::cout << "Time to process a range of "
    << vec.size() << " elements with std::vector : " 
    << vec_time << " us" << std::endl;
    std::cout << "Time to process a range of "
    << lst.size() << " elements with std::list : " 
    << lst_time << " us" << std::endl;

    return 0;
}