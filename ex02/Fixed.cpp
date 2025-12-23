#include "Fixed.h"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
} 

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}


//converting from int into fixedPointFloat
//_fractionalBits is 8, so we push this numeber (as bits) to the left as much as 8
Fixed::Fixed(const int intVal) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intVal << _fractionalBits;
}

//converting from float into fixedPointFloat
//roundf:반올림  
Fixed::Fixed(const float floatVal) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(floatVal * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// std::ostream& out은 std::cout을 의미합니다.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
