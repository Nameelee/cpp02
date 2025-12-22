#include "Fixed.h"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

//same name different input???This is "Constructor Overloading"
//this is confusing. Constructor itself takes its own memory and make new object 
//but in same time, asign the value from its original (other)
//original has value as 8 & 0
Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other.getRawBits();
}

//그 긴 함수 전체가 오직 등호(=) 기호 하나가 Fixed 클래스 사이에서 어떻게 동작할지를 정의하기 위해 존재
Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

//this will called automatically when it meets '}'
//Because 'Fixed' will be called like 'Fixed a' not with 'new'   
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
} 

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" <<std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}
