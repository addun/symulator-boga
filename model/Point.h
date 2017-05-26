//
// Created by adrian on 14/05/17.
//

#ifndef SIMULATOR_OF_GOD_POINT_H
#define SIMULATOR_OF_GOD_POINT_H


#include <ostream>

class Point {
private:
    int x;
    int y;
public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    Point(int x, int y);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    double distance(Point p);

    int diffY(Point point);

    int diffX(Point point);

    bool operator<(const Point &rhs) const;

    bool operator>(const Point &rhs) const;

    bool operator<=(const Point &rhs) const;

    bool operator>=(const Point &rhs) const;
};


#endif //SIMULATOR_OF_GOD_POINT_H
