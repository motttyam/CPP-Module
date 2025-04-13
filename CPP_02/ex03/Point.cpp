#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y) {}

Point::Point(Point const &value) : _x(value._x), _y(value._y) {}

Point::~Point(){}

// private member func
Fixed const& Point::getX() const {
    return (this->_x);
}

Fixed const& Point::getY() const {
    return (this->_y);
}

// Insertion operator
std::ostream &operator<<(std::ostream &os, Point const &value) {
    os << "(" << value.getX().toFloat() << " " << value.getY().toFloat() << ")";
    return (os);
}