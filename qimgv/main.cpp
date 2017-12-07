#include "qimgv.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qimgv w;
    w.show();
    return a.exec();
}
