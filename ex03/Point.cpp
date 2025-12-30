#include "Point.h"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {
}

