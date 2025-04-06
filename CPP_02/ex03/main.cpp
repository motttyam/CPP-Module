#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    bool result;
    
    // 内側1
    Point a(Fixed(0), Fixed(0)), b(Fixed(0), Fixed(100)), c(Fixed(100), Fixed(0));
    Point p(Fixed(2), Fixed(3));
    result = Point::bsp(a, b, c, p);
    std::cout << "Inside: " << (result ? "PASS" : "FAIL") << std::endl;

    // 内側2
    Point p_inside(Fixed(2), Fixed(3));
    result = Point::bsp(a, b, c, p_inside);
    std::cout << "Inside: " << (result ? "PASS" : "FAIL") << std::endl;

    // 外側
    Point p_outside(Fixed(-10), Fixed(-10));
    result = Point::bsp(a, b, c, p_outside);
    std::cout << "Outside: " << (result ? "FAIL" : "PASS") << std::endl;

    // 辺上
    Point p_on_edge(Fixed(0), Fixed(50));
    result = Point::bsp(a, b, c, p_on_edge);
    std::cout << "On Edge: " << (result ? "FAIL" : "PASS") << std::endl;

    // 頂点上
    Point p_on_vertex(Fixed(0), Fixed(0));
    result = Point::bsp(a, b, c, p_on_vertex);
    std::cout << "On Vertex: " << (result ? "FAIL" : "PASS") << std::endl;


    return (0);
}