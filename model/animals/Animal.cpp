//
// Created by adrian on 14/05/17.
//

#include <cmath>
#include <algorithm>
#include <iostream>
#include "Animal.h"

void Animal::move() {
    if (alive) {
        hysteresis->switchStateIfCan();
        if (canReproduce()) {
            moveToReproduce();
        } else if (canEat()) {
            moveToEat();
        } else {
            randomMove();
        }
        increaseAge();
        if (!canLive()) {
            setAlive(false);
        }
    }
}

bool Animal::canReproduce() {
    return hysteresis->isUpper() && currentAge >= ageToReproduce;
}

std::ostream &operator<<(std::ostream &os, const Animal &animal) {
    os << "position: " << *animal.position << std::endl;
    os << "alive: " << animal.isAlive() << std::endl;
    os << "weight: " << animal.currentWeight << std::endl;
    os << "age: " << animal.currentAge << std::endl;
    if (animal.hysteresis->isLower())
        os << "Type: atack!" << std::endl;
    else if (animal.hysteresis->isUpper())
        os << "Type: reproduction!" << std::endl;
    return os;
}

bool Animal::isAlive() const {
    return alive;
}

void Animal::setAlive(bool alive) {
    Animal::alive = alive;
}

void Animal::followToPoint(Point point) {
    int cs = currentSpeed();
    int diffX = position->diffX(point);
    int diffY = position->diffY(point);

    int newPointX = position->getX();
    int newPointY = position->getY();


    if (abs(diffX) <= cs) {
        newPointX = point.getX();
    } else if (diffX < 0) {
        newPointX = position->getX() + cs;
    } else if (diffX > 0) {
        newPointX = position->getX() - cs;
    }

    if (abs(diffY) <= cs) {
        newPointY = point.getY();
    } else if (diffY < 0) {
        newPointY = position->getY() + cs;
    } else if (diffY > 0) {
        newPointY = position->getY() - cs;
    }

    Point *p = new Point(newPointX, newPointY);
    moveToPoint(p);
}


Point *Animal::getRandomMove() {
    int sec = 0;
    int randomX = 0;
    int randomY = 0;
    int cs = currentSpeed();
    Point *p = NULL;
    do {
        randomX = ((rand() % (cs * 2 + 1) - cs)) + position->getX();
        randomY = ((rand() % (cs * 2 + 1) - cs)) + position->getY();
        p = new Point(randomX - 1, randomY - 1);
        if (++sec > 500) {
            throw std::overflow_error("Can't find next move!");
        }
    } while (!area->isInArea(*p));
    return p;
}

Animal::Animal(Area *area, Point *position) : position(position), area(area) {}

Animal::Animal(Area *area) : Animal(area, area->getRandomPoint()) {}

void Animal::moveToPoint(Point *point) {
    loseWeightWhileMove(*point);
    area->getMatrix()->removeAnimalFromCell(this);
    position = point;
    area->getMatrix()->addAnimalToCell(this);
}

void Animal::loseWeightWhileMove(Point point) {
    double distance = position->distance(point);
    currentWeight -= distance * weightLossRatio;
}

Point *Animal::getPosition() const {
    return position;
}

void Animal::randomMove() {
    Point *p = getRandomMove();
    moveToPoint(p);
}

Animal *Animal::getTheNearestAnimalType(std::vector<const char *> typeAnimal) {
    Point firstCorner = *getPosition();
    Point start(0, 0);
    Point end(area->getWidth(), area->getHeight());
    Point temp = *getPosition();
    Point secondCorner = *getPosition();
    Matrix *matrix = area->getMatrix();
    int count = 1;

    do {
        temp = firstCorner;
        secondCorner = Point(firstCorner.getX() + count - 1, firstCorner.getY() + count - 1);

        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < count; ++i) {
                switch (j) {
                    case 0:
                        temp.setX(firstCorner.getX() + i);
                        break;
                    case 1:
                        temp.setY(firstCorner.getY() + i);
                        break;
                    case 2:
                        temp.setX(secondCorner.getX() - i);
                        break;
                    case 3:
                        temp.setY(secondCorner.getY() - i);
                        break;
                    default:
                        break;
                }
                if (matrix->pointExist(temp) && matrix->isAnimalOnCell(temp)) {
                    for (auto &&item : *matrix->getCell(temp)) {
                        for (auto &&provider : typeAnimal) {
                            if (typeid(*item).name() == provider) {
                                return item;
                            }
                        }
                    }
                }
            }
        }

        firstCorner.setX(temp.getX() - 1);
        firstCorner.setY(temp.getY() - 1);
        count += 2;
    } while (
            firstCorner.getX() > 0
            || firstCorner.getY() > 0
            || secondCorner.getX() < matrix->matrix.size()
            || secondCorner.getY() < matrix->matrix[0].size()
            );
    return NULL;
}

void Animal::refreshTheNearestAliveAnimals() {
    theClosestAnimals.clear();
    for (Animal *animal : area->getAnimals()) {
        if (animal->isAlive() && animal != this) {
            theClosestAnimals[position->distance(*animal->position)] = animal;
        }
    }
}

void Animal::followToAnimal(Animal *animal) {
    followToPoint(*animal->position);
}


Animal *Animal::getTheNearestAnimalToEat() {
    if (area->density() > 0.01)
        return getTheNearestAnimalType(providers);

    refreshTheNearestAliveAnimals();
    for (std::pair<const double, Animal *> &pair : theClosestAnimals) {
        for (const char *const &provider:providers) {
            if (typeid(*pair.second).name() == provider) {
                return pair.second;
            }
        }
    }
    return NULL;
}

Animal *Animal::getTheNearestAnimalToReproduce() {
    if (area->density() > 0.01) {
        std::vector<const char *> reproduce = {typeid(*this).name()};
        return getTheNearestAnimalType(reproduce);
    }
    refreshTheNearestAliveAnimals();
    for (std::pair<const double, Animal *> &pair : theClosestAnimals) {
        if (typeid(*pair.second).name() == typeid(*this).name()) {
            return pair.second;
        }
    }
    return NULL;
}

bool Animal::canActionWithAnimal(Animal *animal) {
    return *position == *animal->getPosition() && animal->isAlive();
}

void Animal::eatAnimal(Animal *animal) {
    currentWeight += animal->currentWeight;
    animal->setAlive(false);
}

int Animal::currentSpeed() {
    int speed = (int) (-0.3 * currentWeight + 55);
    if (speed > 50) {
        return 50;
    }
    if (speed < 5) {
        return 5;
    }
    return speed;
}

bool Animal::canLive() {
    return currentAge <= maxAge && currentWeight >= minWeightToLive;
}

bool Animal::canEat() {
    return hysteresis->isLower();
}

void Animal::moveToReproduce() {
    Animal *animal = getTheNearestAnimalToReproduce();
    if (animal == NULL) {
        randomMove();
    } else {
        followToAnimal(animal);
        if (canActionWithAnimal(animal)) {
            reproduce();
        }
    }
}

void Animal::moveToEat() {
    Animal *animal = getTheNearestAnimalToEat();
    if (animal == NULL) {
        randomMove();
    } else {
        followToAnimal(animal);
        if (canActionWithAnimal(animal)) {
            eatAnimal(animal);
        }
    }
}

void Animal::increaseAge() {
    currentAge++;
}

void Animal::addProvider(const char *provider) {
    providers.push_back(provider);
}