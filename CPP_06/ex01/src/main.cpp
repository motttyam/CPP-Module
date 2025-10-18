#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <cstdint>

int main() {
    Data data = {42, 42.0f, 42.0, "hello"};
    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Serialized pointer: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Same pointer? " << std::boolalpha << (&data == ptr) << std::endl;
    return (0);
}