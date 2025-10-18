#include <iostream>
#include <cassert>
#include "Serializer.hpp"
#include "Data.hpp"

void test_basic_conversion() {
    std::cout << "[TEST] Basic serialize/deserialize" << std::endl;

    Data data;
    data.a = 10;
    data.b = 2.5f;
    data.c = 5.5;
    data.d = "hello";

    uintptr_t raw = Serializer::serialize(&data);
    Data* restored = Serializer::deserialize(raw);

    assert(restored == &data);
    assert(restored->a == 10);
    assert(restored->b == 2.5f);
    assert(restored->c == 5.5);
    assert(restored->d == "hello");

    std::cout << "  -> Passed" << std::endl;
}

void test_multiple_objects() {
    std::cout << "[TEST] Multiple Data objects" << std::endl;

    Data x, y;
    x.a = 1; x.b = 1.0f; x.c = 1.0; x.d = "x";
    y.a = 2; y.b = 2.0f; y.c = 2.0; y.d = "y";

    uintptr_t raw_x = Serializer::serialize(&x);
    uintptr_t raw_y = Serializer::serialize(&y);

    Data* px = Serializer::deserialize(raw_x);
    Data* py = Serializer::deserialize(raw_y);

    assert(px == &x);
    assert(py == &y);
    assert(px != py);

    std::cout << "  -> Passed" << std::endl;
}

void test_address_integrity() {
    std::cout << "[TEST] Address integrity" << std::endl;

    Data data;
    data.a = 99;
    data.b = 0.9f;
    data.c = 9.9;
    data.d = "check";

    uintptr_t raw = Serializer::serialize(&data);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "  Original address: " << &data << std::endl;
    std::cout << "  Restored address: " << restored << std::endl;

    assert(restored == &data);
    std::cout << "  -> Passed" << std::endl;
}

int main() {
    std::cout << "===== Serializer Spec =====" << std::endl;

    test_basic_conversion();
    test_multiple_objects();
    test_address_integrity();

    std::cout << "All tests passed successfully 🎉" << std::endl;
    return 0;
}
