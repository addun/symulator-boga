//
// Created by adrian on 19/05/17.
//

#ifndef SIMULATOR_OF_GOD_BOAR_H
#define SIMULATOR_OF_GOD_BOAR_H


#include "Animal.h"

class Boar : public Animal {
public:

    Boar(Area *area, Point *position);

    Boar(Area *area);

    void reproduce() override;
};


#endif //SIMULATOR_OF_GOD_BOAR_H
