//
// Created by adrian on 19/05/17.
//

#ifndef SIMULATOR_OF_GOD_WOLF_H
#define SIMULATOR_OF_GOD_WOLF_H


#include "Animal.h"

class Wolf : public Animal {
public:

    Wolf(Area *area, Point *position);

    Wolf(Area *area);

    void reproduce() override;
};


#endif //SIMULATOR_OF_GOD_WOLF_H
