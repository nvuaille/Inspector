#include "inspectorpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InspectorPanel w;
    w.show();

    return a.exec();
}
