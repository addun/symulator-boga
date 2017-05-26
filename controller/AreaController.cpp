#include <QGraphicsScene>
#include <iostream>
#include <zconf.h>
#include "AreaController.h"
#include "../model/animals/Lion.h"
#include "../model/animals/Elephant.h"
#include "../model/animals/Bear.h"
#include "../model/animals/Boar.h"
#include "../model/animals/Hippo.h"
#include "../model/animals/Wolf.h"

AreaController::AreaController(QGraphicsScene *scene, Area *a) : scene(scene), area(a) {
}

void AreaController::addExamplesAnimals(int manyEach) {
    for (int m = 0; m < manyEach; ++m) {
        for (int var = 0; var < 1; ++var) {
            area->addAnimal(new Lion(area));
        }

        for (int var = 0; var < 1; ++var) {
            area->addAnimal(new Elephant(area));
        }

        for (int var = 0; var < 1; ++var) {
            area->addAnimal(new Bear(area));
        }
        for (int var = 0; var < 1; ++var) {
            area->addAnimal(new Boar(area));
        }
        for (int var = 0; var < 1; ++var) {
            area->addAnimal(new Hippo(area));
        }
        for (int var = 0; var < 1; ++var) {
            area->addAnimal(new Wolf(area));
        }
    }
}

void AreaController::clearAll() {
    scene->clear();
    area->removeAllAnimals();
}

void AreaController::drawAllAnimal(){
    for (Animal *a: area->getAnimals()) {
        drawAnimal(a);
    }
}

void AreaController::run() {
    if(!isRunning){
        isRunning = true;
        if (area->anyAlive()) {
            step();
        }
        isRunning = false;
    }
}

void AreaController::step() {
    area->nextUnitTime();
    scene->clear();
    QPen blackpen(Qt::black);
    blackpen.setWidth(3);
    drawAllAnimal();
}

Area *AreaController::getArea() const {
    return area;
}

void AreaController::setArea(Area *area) {
    AreaController::area = area;
}

QGraphicsScene *AreaController::getScene() const {
    return scene;
}

void AreaController::setScene(QGraphicsScene *scene) {
    AreaController::scene = scene;
}

void AreaController::drawAnimal(Animal *a){
    QPen blackpen;
    blackpen.setWidth(3);
    if (typeid(Lion).name() == typeid(*a).name()) {
        blackpen.setColor(Qt::red);
    } else if (typeid(Wolf).name() == typeid(*a).name()) {
        blackpen.setColor(Qt::green);
    } else if (typeid(Elephant).name() == typeid(*a).name()) {
        blackpen.setColor(Qt::yellow);
    } else if (typeid(Hippo).name() == typeid(*a).name()) {
        blackpen.setColor(Qt::blue);
    } else if (typeid(Boar).name() == typeid(*a).name()) {
        blackpen.setColor(Qt::gray);
    } else if (typeid(Bear).name() == typeid(*a).name()) {
        blackpen.setColor(Qt::cyan);
    } else {
        blackpen.setColor(Qt::black);
    }
    scene->addRect(a->getPosition()->getX(), a->getPosition()->getY(), 2, 2, blackpen);
}
