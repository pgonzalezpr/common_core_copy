#include "Serializer.hpp"

int main() {
    Data data;
    data.type = "myData";
    data.size = 10;

    Data *ptr = Serializer::deserialize(Serializer::serialize(&data));

    std::cout << "Original Data => Type: " << data.type << ", Size: "
    << data.size << std::endl;

    std::cout << "Returned Data => Type: " << ptr->type << ", Size: "
    << ptr->size << std::endl;
}