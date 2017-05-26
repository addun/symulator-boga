//
// Created by adrian on 14/05/17.
//

#ifndef SIMULATOR_OF_GOD_ANIMAL_H
#define SIMULATOR_OF_GOD_ANIMAL_H


#include <ostream>
#include "../Area.h"
#include "../Point.h"
#include "../Hysteresis.h"
#include <typeinfo>
#include <vector>
#include <map>


class Area;

class Animal {


public:
    Animal(Area *area, Point *position);

    Animal(Area *area);

protected:
    Area *area;

protected:
    std::vector<const char *> providers;
    int maxAge;
    int ageToReproduce;
    double minWeightToLive;
    double normalWeight;
    double bornWeight;
    Hysteresis *hysteresis;
    double currentWeight;
    double weightLossRatio = 0.015;
protected:
    void addProvider(const char *provider);


protected:
    void loseWeightWhileMove(Point point);


private:
    std::map<double, Animal *> theClosestAnimals;

    void refreshTheNearestAliveAnimals();


private:
    int currentAge = 0;
protected:
    void increaseAge();


private:
    Point *position;
public:
    Point *getPosition() const;

private:
    bool alive = true;
public:
    bool isAlive() const;

    void setAlive(bool alive);

    bool canLive();


public:
    void move();


public:
    bool canReproduce();

    Animal *getTheNearestAnimalToReproduce();

    void moveToReproduce();

    virtual void reproduce() =0;


public:
    bool canEat();

    Animal *getTheNearestAnimalToEat();

    void moveToEat();

    void eatAnimal(Animal *animal);


public:
    bool canActionWithAnimal(Animal *animal);


public:
    void followToAnimal(Animal *animal);

    void followToPoint(Point p);


public:
    void randomMove();

    Point *getRandomMove();

    void moveToPoint(Point *point);

    int currentSpeed();

public:
    friend std::ostream &operator<<(std::ostream &os, const Animal &animal);

    Animal *getTheNearestAnimalType(std::vector<const char *> typeAnimal);
};

#endif //SIMULATOR_OF_GOD_ANIMAL_H
