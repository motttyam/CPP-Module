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
    // std::cout << "Copy assignment operator called" << std::endl;
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
Fixed Fixed::operator+(Fixed const &other) {
    Fixed result;
    long resultValue;
    resultValue = static_cast<long>(this->getRawBits()) + other.getRawBits();
    result.setRawBits(static_cast<int>(resultValue));
    return (result);
}

Fixed Fixed::operator-(Fixed const &other) {
    Fixed result;
    long resultValue;
    resultValue = static_cast<long>(this->getRawBits()) - other.getRawBits();
    result.setRawBits(static_cast<int>(resultValue));
    return (result);
}

Fixed Fixed::operator*(Fixed const &other) {
    Fixed result;
    long resultValue;
    resultValue = static_cast<long>(this->getRawBits()) * other._value;
    result.setRawBits(static_cast<int>(roundf(static_cast<float>(resultValue) / (1 << this->_fractional_bits))));
    return (result);
}

Fixed Fixed::operator/(Fixed const &other) {
    Fixed result;
    
    // 0除算をハンドリングして0を返す
    if (!other.getRawBits())
        return (result);

    // scaleした状態で計算する
    long long numerator = static_cast<long long>(this->getRawBits()) ;
    long long denominator = static_cast<long long>(other.getRawBits()); 
    long long quotient_scaled = (numerator << Fixed::_fractional_bits) / denominator;
    result.setRawBits(static_cast<int>(quotient_scaled));
    return (result);
}

// Prefix increment
Fixed Fixed::operator++() {
    this->_value++;
    return (*this);
}

Fixed Fixed::operator--() {
    this->_value--;
    return (*this);
}

// Postfix increment
Fixed Fixed::operator++(int) {
    Fixed original = *this;
    ++(*this);
    return (original);
}

Fixed Fixed::operator--(int) {
    Fixed original = *this;
    --(*this);
    return (original);
}

// overloaded
Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a.getRawBits() <= b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() <= b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a.getRawBits() >= b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() >= b.getRawBits())
        return (a);
    else
        return (b);
}

// Insertion operator
std::ostream &operator<<(std::ostream &os, const Fixed &value) {
    os << value.toFloat();
    return (os);
}
