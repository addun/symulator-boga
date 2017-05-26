//
// Created by adrian on 14/05/17.
//

#include <cmath>
#include "Point.h"

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

Point::Point(int x, int y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "x: " << point.x << " y: " << point.y;
    return os;
}

double Point::distance(Point p) {
    int diffX = abs(x - p.getX());
    int diffY = abs(y - p.getY());
    return sqrt(diffX * diffX + diffY * diffY);
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

int Point::diffX(Point point){
    return x - point.getX();
}

int Point::diffY(Point point){
    return y - point.getY();
}

bool Point::operator<(const Point &rhs) const {
    return x< rhs.x && y < rhs.y;
}

bool Point::operator>(const Point &rhs) const {
    return x> rhs.x && y > rhs.y;
}

bool Point::operator<=(const Point &rhs) const {
    return !(rhs < *this);
}

bool Point::operator>=(const Point &rhs) const {
    return !(*this < rhs);
}
