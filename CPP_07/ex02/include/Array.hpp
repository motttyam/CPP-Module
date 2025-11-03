#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
    private:
        T  *_data;
        unsigned int _size;
    public:
        Array(): _data(new T[0]), _size(0){}

        Array(unsigned int n): _data(new T[n]()), _size(n){}

        Array(const Array& other): _data(new T[other._size]()), _size(other._size){
            for (unsigned int i = 0; i < _size; ++i){
                this->_data[i] = other._data[i];
            }
        }

        T& operator[](unsigned int i) {
            if (i >= _size){
                throw std::out_of_range("Index out of range");
            }
            return _data[i];
        }
        const T& operator[](unsigned int i) const {
            if (i >= _size){
                throw std::out_of_range("Index out of range");
            }
            return _data[i];
        }

        Array& operator=(const Array& other){
            if (this != &other) {
                T *tmp = new T[other._size]();
                for (unsigned int i = 0; i < other._size; ++i){
                    tmp[i] = other._data[i];
                }
                delete [] _data;
                this->_data = tmp;
                this->_size = other._size;
            }
            return (*this);
        }

        ~Array(){
            delete [] _data;
        }

        unsigned int size() const {
            return (this->_size);
        }
};

#endif
