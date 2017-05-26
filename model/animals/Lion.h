//
// Created by adrian on 18/05/17.
//

#ifndef SIMULATOR_OF_GOD_LION_H
#define SIMULATOR_OF_GOD_LION_H


#include "Animal.h"

class Lion : public Animal{
public:
    Lion(Area *area, Point *position);

    void reproduce() override;

    Lion(Area *area);

};


#endif //SIMULATOR_OF_GOD_LION_H
