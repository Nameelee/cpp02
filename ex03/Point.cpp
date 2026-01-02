#include "Point.h"

Point::Point() : _x(0), _y(0) {
}

// 2. 좌표 생성자 : float 값을 받아서 Fixed로 변환하여 초기화
Point::Point(const float x, const float y) : _x(x), _y(y) {
}

// 3. 복사 생성자 : 다른 점의 값을 가져와서 초기화
Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {
}

// 4. 대입 연산자 (가장 문제의 구간!)
// _x와 _y가 const이기 때문에, 이미 태어난 객체에 값을 '대입'하는 것은 불가능.
// 그래서 이 함수는 사실상 아무것도 할 수 없습니다
Point &Point::operator=(const Point &other) {
    if (this != &other) {
    }
    return (*this);
}

Point::~Point() {    
}

Fixed Point::getX() const {
    return (this->_x);
}

Fixed Point::getY() const {
    return (this->_y);
}
