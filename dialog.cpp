#include "dialog.h"
#include "ui_dialog.h"
#include "model/Area.h"
#include <controller/AreaController.h>
#include <model/animals/Lion.h>
#include <model/animals/Elephant.h>
#include <model/animals/Bear.h>
#include <model/animals/Boar.h>
#include <model/animals/Hippo.h>
#include <model/animals/Wolf.h>
#include <QtConcurrent/QtConcurrentMap>
#include <QtConcurrent/QtConcurrentRun>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog) {

    this->setWindowFlags(Qt::Window);
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    pasture = ui->pasture;
    pasture->setScene(scene);
    pasture->resize(pastureWidth, pastureHeight);
    area = new Area(pastureWidth, pastureHeight);
    areaController = new AreaController(scene, area);  
    on_reset_button_clicked();

}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_start_button_clicked()
{
    timer = new QTimer(areaController);
    connect(timer, SIGNAL(timeout()), areaController, SLOT(run()));
    timer->setInterval(100);
    timer->start();

}

void Dialog::on_step_button_clicked()
{
    areaController->step();
}

void Dialog::on_stop_button_clicked()
{
    timer->stop();
}

void Dialog::on_reset_button_clicked()
{
    areaController->clearAll();
    areaController->addExamplesAnimals(animalStartNumber);
    areaController->drawAllAnimal();
}
