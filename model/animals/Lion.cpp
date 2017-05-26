//
// Created by adrian on 18/05/17.
//

#include "Lion.h"
#include "Elephant.h"
#include "Hippo.h"
#include "Bear.h"

Lion::Lion(Area *area, Point *position) : Animal(area, position) {
    minWeightToLive = 25;
    currentWeight = 50;
    bornWeight = 50;
    maxAge = 70;
    ageToReproduce = 5;
    normalWeight = 100;
    hysteresis = new Hysteresis(false, bornWeight * 2, &currentWeight, bornWeight * 3);
    addProvider(typeid(Hippo).name());
    addProvider(typeid(Bear).name());
}

Lion::Lion(Area *area) : Lion(area, area->getRandomPoint()) {}

void Lion::reproduce() {
    Point *r = new Point(this->getPosition()->getX(), this->getPosition()->getY());
    this->currentWeight -= bornWeight;
    area->addAnimal(new Lion(area, r));
}
