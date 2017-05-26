//
// Created by adrian on 19/05/17.
//

#include "Boar.h"
#include "Elephant.h"
#include "Wolf.h"

Boar::Boar(Area *area, Point *position) : Animal(area, position) {
    minWeightToLive = 25;
    currentWeight = 50;
    bornWeight = 50;
    maxAge = 60;
    ageToReproduce = 5;
    normalWeight = 100;
    hysteresis = new Hysteresis(false, bornWeight * 2, &currentWeight, bornWeight * 3);
    addProvider(typeid(Elephant).name());
    addProvider(typeid(Wolf).name());
}

Boar::Boar(Area *area) : Boar(area, area->getRandomPoint()) {}

void Boar::reproduce() {
    Point *r = new Point(this->getPosition()->getX(), this->getPosition()->getY());
    this->currentWeight -= bornWeight;
    area->addAnimal(new Boar(area, r));
}
