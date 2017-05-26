//
// Created by adrian on 14/05/17.
//

#include <thread>
#include <iostream>
#include "Area.h"
#include "animals/Lion.h"

Area::Area(unsigned int width, unsigned int height) : width(width), height(height) {
    matrix = new Matrix(width, height);
}


int Area::getWidth() const {
    return width;
}

int Area::getHeight() const {
    return height;
}

void Area::nextUnitTime() {
    for (Animal *animal : animals) {
        animal->move();
    }
    removeAllDeathAnimals();
}

std::ostream &operator<<(std::ostream &os, const Area &area) {
    os << "Animals: \n";
    for (Animal *animal : area.animals) {
        os << *animal << std::endl;
    }
    return os;
}

void Area::addAnimal(Animal *animal) {
    animals.push_back(animal);
    matrix->addAnimalToCell(animal);
}


bool Area::anyAlive() {
    for (Animal *animal : animals) {
        if (animal->isAlive()) {
            return true;
        }
    }
    return false;
}

Point *Area::getRandomPoint() {
    int randomX = rand() % (width);
    int randomY = rand() % (height);
    return new Point(randomX, randomY);
}

bool Area::isInArea(Point point) {
    if (point.getY() >= height || point.getY() < 0) {
        return false;
    }
    return !(point.getX() >= width || point.getX() < 0);
}

const std::deque<Animal *> &Area::getAnimals() const {
    return animals;
}

void Area::removeAllDeathAnimals() {
    for (unsigned int j = 0; j < animals.size();) {
        if (!animals[j]->isAlive()) {
            matrix->removeAnimalFromCell(animals[j]);
            animals.erase(animals.begin() + j);
        } else {
            ++j;
        }
    }
}

Matrix *Area::getMatrix() const {
    return matrix;
}

void Area::removeAllAnimals(){
    animals.clear();
}

double Area::density() {
    return (animals.size() / (width * height) * 100);
}
