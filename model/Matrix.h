//
// Created by adrian on 17/05/17.
//

#ifndef SIMULATOR_OF_GOD_AREAMATRIX_H
#define SIMULATOR_OF_GOD_AREAMATRIX_H

#include <vector>
#include <ostream>
#include "animals/Animal.h"

class Animal;

class Matrix {

public:
    std::vector<
            std::vector<
                    std::vector<Animal *>
            >
    > matrix;

public:
    Matrix(unsigned int width, unsigned int height);

    std::vector<Animal *> *getCell(Point point);

    std::vector<Animal *> *getAnimalCell(Animal *animal);

    void addAnimalToCell(Animal *animal);

    void removeAnimalFromCell(Animal *animal);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    bool isAnimalOnCell(Point point);

    bool pointExist(Point point);
};


#endif //SIMULATOR_OF_GOD_AREAMATRIX_H
