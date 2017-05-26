//
// Created by adrian on 19/05/17.
//

#include "Bear.h"
#include "Boar.h"
#include "Elephant.h"

Bear::Bear(Area *area, Point *position) : Animal(area, position) {
    minWeightToLive = 25;
    currentWeight = 50;
    bornWeight = 50;
    maxAge = 70;
    ageToReproduce = 5;
    normalWeight = 100;
    hysteresis = new Hysteresis(false, bornWeight * 2, &currentWeight, bornWeight * 3);
    addProvider(typeid(Boar).name());
    addProvider(typeid(Elephant).name());
}

Bear::Bear(Area *area) : Bear(area, area->getRandomPoint()) {}

void Bear::reproduce() {
    Point *r = new Point(this->getPosition()->getX(), this->getPosition()->getY());
    this->currentWeight -= bornWeight;
    area->addAnimal(new Bear(area, r));
}
