//
// Created by adrian on 19/05/17.
//

#ifndef SIMULATOR_OF_GOD_ELEPHANT_H
#define SIMULATOR_OF_GOD_ELEPHANT_H


#include "Animal.h"

class Elephant : public Animal {
public:
    Elephant(Area *area, Point *position);

    Elephant(Area *area);

    void reproduce() override;

};


#endif //SIMULATOR_OF_GOD_ELEPHANT_H
