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
       https://www.notion.so/familyalbum/1bb2f9df7cab809693e7ddc8fa1d6409?pvs=4 ~Fixed();

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

        // Arithmetic operator　明日やる
        Fixed operator+(Fixed const &other);
        Fixed operator-(Fixed const &other);
        Fixed operator*(Fixed const &other);
        Fixed operator/(Fixed const &other);

        // Insertion Operator
        friend std::ostream& operator<<(std::ostream &os, const Fixed &value);
    };
    
    
#endif