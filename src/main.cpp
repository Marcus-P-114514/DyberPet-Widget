#include "DyberPet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    DyberPet w;
    w.show();
    return a.exec();
}
