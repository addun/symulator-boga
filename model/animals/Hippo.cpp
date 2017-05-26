//
// Created by adrian on 19/05/17.
//

#include "Hippo.h"
#include "Lion.h"

Hippo::Hippo(Area *area, Point *position) : Animal(area, position) {
    minWeightToLive = 25;
    currentWeight = 50;
    bornWeight = 50;
    maxAge = 70;
    ageToReproduce = 5;
    normalWeight = 100;
    hysteresis = new Hysteresis(false, bornWeight * 2, &currentWeight, bornWeight * 3);
    addProvider(typeid(Lion).name());
}

Hippo::Hippo(Area *area) : Hippo(area, area->getRandomPoint()) {}

void Hippo::reproduce() {
    Point *r = new Point(this->getPosition()->getX(), this->getPosition()->getY());
    this->currentWeight -= bornWeight;
    area->addAnimal(new Hippo(area, r));
}
