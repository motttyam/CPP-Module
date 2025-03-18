#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
    private:
        int _value;
        static const int _fractional_bits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed & operator=(const Fixed &other);
        int getRawBits() const ;
        void setRawBits(int const row);
        float toFloat(void) const;
        int toInt(void) const;
        friend std::ostream& operator<<(std::ostream &os, const Fixed &value);
    };
    
    
#endif