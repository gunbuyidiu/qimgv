#ifndef QIMGV_H
#define QIMGV_H

#include <QtWidgets/QMainWindow>
#include "ui_qimgv.h"

class qimgv : public QMainWindow
{
    Q_OBJECT

public:
    qimgv(QWidget *parent = 0);
    ~qimgv();

private:
    Ui::qimgvClass ui;
};

#endif // QIMGV_H
