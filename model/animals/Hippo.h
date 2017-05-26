//
// Created by adrian on 19/05/17.
//

#ifndef SIMULATOR_OF_GOD_HIPPO_H
#define SIMULATOR_OF_GOD_HIPPO_H


#include "Animal.h"

class Hippo : public Animal {
public:

    Hippo(Area *area, Point *position);

    Hippo(Area *area);

    void reproduce() override;
};


#endif //SIMULATOR_OF_GOD_HIPPO_H
