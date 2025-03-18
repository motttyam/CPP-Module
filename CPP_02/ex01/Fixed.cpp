#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

// floatの値を固定少数点数として持つ
Fixed::Fixed(const float value) : _value (static_cast<int>(roundf(value * (1 << Fixed::_fractional_bits)))) {
    std::cout << "Float constructor called" << std::endl;
}
// 受け取った浮動小数点数値 (value) に 2 の Fixed::_fractional_bits 乗 (2^8 = 256) を掛けます。
// これは、浮動小数点数を固定小数点数のスケールに合わせる操作です。
// 例えば、value が 5.75 の場合、5.75 * 256 = 1472 となります。

// roundf 関数は、結果を最も近い整数に丸めます。
// これは、浮動小数点数を整数型の固定小数点数表現に変換する際の精度を保つために重要です。

// static_cast<int>(...) は、丸められた浮動小数点数値を整数型に明示的にキャストします。
// この整数値が、固定小数点数の内部表現として _value に格納されます。

Fixed::Fixed(const Fixed &other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other.getRawBits();
    return (*this);
}

// 内部の生のビット表現 (整数値) を取得する
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

// 内部の生のビット表現 (整数値) を設定する
void Fixed::setRawBits(int const row) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = row;    
}

int Fixed::toInt(void) const {
    return (this->_value >> Fixed::_fractional_bits);
}

// 固定少数点数を浮動小数点数に変換する
float Fixed::toFloat(void) const {
    return (static_cast<float>(this->_value) / (1 << Fixed::_fractional_bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &value){
    os << value.toFloat();
    return (os);
}