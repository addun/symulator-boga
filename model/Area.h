//
// Created by adrian on 14/05/17.
//

#ifndef SIMULATOR_OF_GOD_AREA_H
#define SIMULATOR_OF_GOD_AREA_H

#include <deque>
#include <vector>
#include <ostream>
#include <deque>
#include "animals/Animal.h"
#include "Point.h"
#include "Matrix.h"

class Animal;
class Matrix;

class Area {

public:
    Area(unsigned int width, unsigned int height);

private:
    int width;
    int height;
public:
    int getWidth() const;

    int getHeight() const;


private:
    std::deque<Animal *> animals;
public:
    const std::deque<Animal *> &getAnimals() const;


private:
    Matrix *matrix;
public:
    Matrix *getMatrix() const;


public:
    void nextUnitTime();

    bool isInArea(Point point);

    void removeAllDeathAnimals();

    void removeAllAnimals();

    virtual void addAnimal(Animal *animal);

    bool anyAlive();

    Point *getRandomPoint();

    friend std::ostream &operator<<(std::ostream &os, const Area &area);

    double density();

};

#endif //SIMULATOR_OF_GOD_AREA_H
