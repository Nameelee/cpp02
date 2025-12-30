#include "Fixed.h"

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const Fixed& other){
    this->_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
    if (this != &other){
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
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
    this->_fixedPointValue = intVal << _fractionalBits;
}

//converting from float into fixedPointFloat
//roundf:반올림  
Fixed::Fixed(const float floatVal) {
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

/**
 * ===========================1.Compare==============================
 * this is just comparing so it is done in the state of 'fixedPointValue'
 */
// a(this) > b(other) 
 bool Fixed::operator>(const Fixed& other) const {
    return (this->getRawBits() > other.getRawBits());
 }

  bool Fixed::operator<(const Fixed& other) const {
    return (this->getRawBits() < other.getRawBits());
 }

 bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

/**
 * ========================2.Arithmetic Operators===========================
 * Calling this function 'Fixed(const float floatVal);' and return
 */
Fixed Fixed::operator+(const Fixed& other) const {
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const {
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const {
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const {
    return (Fixed(this->toFloat() / other.toFloat()));
}

/**
 * ========================3.Incremental Operators===========================
 * Calling this function 'Fixed(const float floatVal);' and return
 */
// 나를 먼저 키우고, 변한 나 자신을 반환
//++a
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return (*this);
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return (*this);
}

//a++
//int argument는 전위/후위 구분을 위한 '껍데기'
//"일단 현재 값을 사용(반환)하고, 그 뒤에 1을 증가시켜라."
//그래서 우리는 **"과거의 나"**를 기억해둘 필요가 있습니다.
Fixed Fixed::operator++(int) {
    Fixed temp(*this);//copy the current value
    this->_fixedPointValue++;
    return temp;//return old value
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);//copy the current value
    this->_fixedPointValue--;
    return temp;//return old value
}

/**
 * ========================4.Min/Max===========================
 * 
 */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

