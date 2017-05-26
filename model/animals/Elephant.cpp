//
// Created by adrian on 19/05/17.
//

#include "Elephant.h"
#include "Lion.h"
#include "Wolf.h"

Elephant::Elephant(Area *area, Point *position) : Animal(area, position) {
    minWeightToLive = 25;
    currentWeight = 50;
    bornWeight = 50;
    maxAge = 70;
    ageToReproduce = 5;
    normalWeight = 100;
    hysteresis = new Hysteresis(false, bornWeight * 2, &currentWeight, bornWeight * 3);
    addProvider(typeid(Wolf).name());
    addProvider(typeid(Lion).name());
}

Elephant::Elephant(Area *area) : Elephant(area, area->getRandomPoint()) {}

void Elephant::reproduce() {
    Point *r = new Point(this->getPosition()->getX(), this->getPosition()->getY());
    this->currentWeight -= bornWeight;
    area->addAnimal(new Elephant(area, r));
}
