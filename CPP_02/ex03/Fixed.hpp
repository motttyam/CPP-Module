#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
    private:
        int _value;
        static const int _fractional_bits = 8;

    public:
        // Constructor & Destructor
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed();

        // General func
        int getRawBits() const ;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // Copy assignment operator
        Fixed &operator=(const Fixed &other);

        // Comparison operator
        bool operator>(Fixed const &other);
        bool operator<(Fixed const &other);
        bool operator>=(Fixed const &other);
        bool operator<=(Fixed const &other);
        bool operator==(Fixed const &other);
        bool operator!=(Fixed const &other);

        // Arithmetic operator
        Fixed operator+(Fixed const &other) const;
        Fixed operator-(Fixed const &other) const;
        Fixed operator*(Fixed const &other) const;
        Fixed operator/(Fixed const &other) const;

        // incrments / decrements
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        // overloaded
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed const& min(Fixed const& a, Fixed const& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed const& max(Fixed const& a, Fixed const& b);
    };
    
// Insertion Operator
std::ostream& operator<<(std::ostream &os, const Fixed &value);
    
#endif