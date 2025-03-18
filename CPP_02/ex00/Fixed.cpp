#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_fractional_bits) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const row) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = row;    
}

// 学び
// Fixed & Fixed::operator=(const Fixed &other)は、参照のため、利用するgetRawBits関数もconstである必要がある