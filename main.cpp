#include "InspectorPanel.hpp"
#include "objectinterval.hpp"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InspectorPanel w;

    ObjectInterval* test = new ObjectInterval("MonNom", "remarques diverses", Qt::red );
    w.newItemInspected(test);

    w.show();

    return a.exec();
}
