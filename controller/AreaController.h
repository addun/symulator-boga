#ifndef AREACONTROLLER_H
#define AREACONTROLLER_H

#include <QGraphicsScene>
#include "../model/Area.h"

class AreaController : public QObject {
    Q_OBJECT

public:
    AreaController(QGraphicsScene *scene, Area *a);

private:
    Area *area;
    QGraphicsScene *scene;
    void drawAnimal(Animal *a);
    bool isRunning = false;
public:
    Area *getArea() const;

    void setArea(Area *area);

    QGraphicsScene *getScene() const;

    void setScene(QGraphicsScene *scene);

public:
    void step();
    void addExamplesAnimals(int manyEach);
    void clearAll();
    void drawAllAnimal();

public slots:
    void run();

};

#endif // AREACONTROLLER_H
