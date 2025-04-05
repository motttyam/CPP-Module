#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y) {};

Point::Point(Point const &value) : _x(value._x), _y(value._y) {};

Point::~Point(){};

// private member func
Fixed const& Point::getX() const {
    return (this->_x);
}

Fixed const& Point::getY() const {
    return (this->_y);
}

// public member func
bool bsq(Point const &a, Point const &b, Point const &c, Point const &point) {

    Fixed ab_x, ab_y, bc_x, bc_y, ca_x, ca_y;
    ab_x = b.getX() - a.getX();
    ab_x = b.getY() - a.getY();
    // ここから続きをやる
}


// Insertion operator
std::ostream &operator<<(std::ostream &os, Point const &value) {
    os << "(" << value.getX().toFloat() << " " << value.getY().toFloat() << ")";
    return (os);
}