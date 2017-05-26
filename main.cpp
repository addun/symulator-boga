#include "dialog.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    srand((unsigned int) time(NULL));

    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
//
//#include <iostream>
//#include "model/Area.h"
//#include "model/animals/Lion.h"
//#include "model/animals/Elephant.h"
//
//int main() {
//
//    str2int();
//
//    Area *area;
//    area = new Area(500, 500);
//
//    for (int m = 0; m < 50; ++m) {
//        for (int var = 0; var < 1; ++var) {
//            area->addAnimal(new Lion(area));
//        }
//
//        for (int var = 0; var < 1; ++var) {
//            area->addAnimal(new Elephant(area));
//        }
//    }
//
//    while (area->anyAlive()) {
//        area->nextUnitTime();
//    }
//
//
//    return 0;
//}