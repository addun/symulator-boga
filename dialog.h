#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QCheckBox>
#include <controller/AreaController.h>
#include "model/Area.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_start_button_clicked();

    void on_step_button_clicked();

    void on_stop_button_clicked();

    void on_reset_button_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsView *pasture;
    int pastureWidth = 500;
    int pastureHeight = 500;
    int animalStartNumber = 50;
    Area *area;
    AreaController *areaController;
    QTimer *timer;
};

#endif // DIALOG_H
