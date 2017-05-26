//
// Created by adrian on 19/05/17.
//

#ifndef SIMULATOR_OF_GOD_BEAR_H
#define SIMULATOR_OF_GOD_BEAR_H


#include "Animal.h"

class Bear : public Animal {
public:
    Bear(Area *area, Point *position);

    Bear(Area *area);

    void reproduce() override;
};


#endif //SIMULATOR_OF_GOD_BEAR_H
