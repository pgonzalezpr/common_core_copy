#ifndef SERIALIZER_HPP
#define SERALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct data_s {
    std::string type;
    int size;
} Data;

class Serializer {
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#endif