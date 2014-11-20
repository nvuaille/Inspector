#include "InspectorPanel.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InspectorPanel w;

    QObject* test = new QObject;
    test->setObjectName("Bobby Watson");

    w.newItemInspected(test);

    w.show();

    return a.exec();
}
