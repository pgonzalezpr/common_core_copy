#include "iter.hpp"

template<typename T>
void iter(T *arr, int size, void (*fun)(T&)) {
    for (int i = 0; i < size; i++) {
        fun(arr[i]);
    }
}

template<typename T>
void printArr(T *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void triple(T& a) { a *= 3; }

void upper(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
}


int main() {

    std::cout << "Test 1: Multiply elements of array by 3" << std::endl;
    std::cout << std::endl;

    int int_arr[5] = {3, 5, 1, 4, 2};
    std::cout << "before arr: ";
    printArr(int_arr, 5);
    std::cout << std::endl;
    iter(int_arr, 5, &triple);
    std::cout << "after arr: ";
    printArr(int_arr, 5);

    std::cout << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Test 2: Convert string array elements to uppercase" << std::endl;
    std::cout << std::endl;

    std::string str_arr[5] = {"VayNE", "Jin34X", "caiTLYn", "ORian##na", "mAoKaI"};
    std::cout << "before arr: ";
    printArr(str_arr, 5);
    std::cout << std::endl;
    iter(str_arr, 5, &upper);
    std::cout << "after arr: ";
    printArr(str_arr, 5);
}