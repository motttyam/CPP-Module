#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << Fixed::_fractional_bits)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return (this->_value);
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(this->_value) / (1 << Fixed::_fractional_bits));
}

int Fixed::toInt(void) const {
    return (this->_value >> Fixed::_fractional_bits);
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other.getRawBits();
    return (*this);
}

// Comparison operator
bool Fixed::operator>(Fixed const &other) {
    return (this->_value > other._value);
}

bool Fixed::operator<(Fixed const &other) {
    return (this->_value < other._value);
}

bool Fixed::operator>=(Fixed const &other) {
    return (this->_value >= other._value);
}

bool Fixed::operator<=(Fixed const &other) {
    return (this->_value <= other._value);
}

bool Fixed::operator==(Fixed const &other) {
    return (this->_value == other._value);
}

bool Fixed::operator!=(Fixed const &other) {
    return (this->_value != other._value);
}

// Arithmetic opeator
// memo: long で キャストしてから計算してオーバーフロー対策をした方が良い？
Fixed Fixed::operator+(Fixed const &other) {
    Fixed result;
    result._value = this->getRawBits() + other.getRawBits();
    return (result);
}

// memo: long で キャストしてから計算してオーバーフロー対策をした方が良い？
Fixed Fixed::operator-(Fixed const &other) {
    Fixed result;
    result._value = this->getRawBits() - other.getRawBits();
    return (result);
}

// memo: long で キャストしてから計算してオーバーフロー対策をした方が良い？
Fixed Fixed::operator*(Fixed const &other) {
    Fixed result;
    result._value = this->getRawBits() * other.getRawBits();
    return (result);
}

// memo: long で キャストしてから計算してオーバーフロー対策をした方が良い？
Fixed Fixed::operator/(Fixed const &other) {
    Fixed result;
    if (other.getRawBits())
    result._value = this->getRawBits() / other.getRawBits();
    return (result);
}

// Insertion operator
std::ostream &operator<<(std::ostream os, const Fixed &value) {
    os << value.toFloat();
    return (os);
}
