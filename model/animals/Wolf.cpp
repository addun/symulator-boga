//
// Created by adrian on 19/05/17.
//

#include "Wolf.h"
#include "Lion.h"
#include "Hippo.h"

Wolf::Wolf(Area *area, Point *position) : Animal(area, position) {
    minWeightToLive = 25;
    currentWeight = 50;
    bornWeight = 50;
    maxAge = 70;
    ageToReproduce = 5;
    normalWeight = 100;
    hysteresis = new Hysteresis(false, bornWeight * 2, &currentWeight, bornWeight * 3);
    addProvider(typeid(Lion).name());
    addProvider(typeid(Hippo).name());
}

Wolf::Wolf(Area *area) : Wolf(area, area->getRandomPoint()) {}

void Wolf::reproduce() {
    Point *r = new Point(this->getPosition()->getX(), this->getPosition()->getY());
    this->currentWeight -= bornWeight;
    area->addAnimal(new Wolf(area, r));
}
