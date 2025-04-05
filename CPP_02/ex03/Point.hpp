#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
        
        public:
        // Constructor    
        Point();
        Point(Fixed const &x, Fixed const &y);
        Point(const Point &other);
        
        // Destructor
        ~Point();
        
        // useful func
        Fixed const& getX() const;
        Fixed const& getY() const;
        
        // bsq
        static bool bsq(Point const &a, Point const &b, Point const &c, Point const &point);

        // Insertion operator
        friend std::ostream& operator<<(std::ostream &os, const Point &value);

};

#endif