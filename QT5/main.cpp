#include "widget.h"
#include <QApplication>
#include <QDbug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qInfo()<<1;
    qInfo()<<2;
    qInfo()<<4;
    return a.exec();
}
