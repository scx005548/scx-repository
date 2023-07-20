#include "widget.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qInfo()<<1;
    qInfo()<<2;
    qInfo()<<3;
    return a.exec();
}
