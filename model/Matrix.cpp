//
// Created by adrian on 17/05/17.
//

#include <iostream>
#include "Matrix.h"

void Matrix::addAnimalToCell(Animal *animal) {
    std::vector<Animal *> *cell = getAnimalCell(animal);
    cell->push_back(animal);
}

bool Matrix::isAnimalOnCell(Point point) {
    std::vector<Animal *> *cell = getCell(point);
    for (auto &&item : *cell) {
        if (item == nullptr) {
            return false;
        }
    }
    return true;
}

std::vector<Animal *> *Matrix::getAnimalCell(Animal *animal) {
    return getCell(*animal->getPosition());
}

std::vector<Animal *> *Matrix::getCell(Point point) {
    return &matrix[point.getX()][point.getY()];
}

Matrix::Matrix(unsigned int width, unsigned int height) {
    matrix.resize(width);
    for (std::vector<std::vector<Animal *>> &row : matrix) {
        row.resize(height);
    }
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os << "matrix: " << std::endl;
    for (int i = 0; i < matrix.matrix.size(); ++i) {
        for (int j = 0; j < matrix.matrix[i].size(); ++j) {
            for (auto &&item :matrix.matrix[i][j]) {
                os << "Animal:" << std::endl;
                os << "X: " << i << "     Y:" << j << std::endl;
                os << *item << std::endl;
            }
        }
    }
    return os;
}

void Matrix::removeAnimalFromCell(Animal *animal) {
    std::vector<Animal *> *cell = getAnimalCell(animal);
    unsigned int index = 0;
    for (std::vector<Animal *>::iterator i = cell->begin(); i < cell->end(); ++i, ++index) {
        if (animal == cell->at(index)) {
            cell->erase(i);
            break;
        }
    }
}

bool Matrix::pointExist(Point point) {
    if (point.getX() < 0 || point.getY() < 0){
        return false;
    }
    return !(point.getX() >= matrix.size() || point.getY() >= matrix[0].size());
}