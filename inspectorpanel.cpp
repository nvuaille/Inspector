#include "inspectorpanel.h"
#include "ui_inspectorpanel.h"
#include "QPushButton"
#include <QLayout>

#include "intervalinspectorview.h"
#include "basicelement.h"

InspectorPanel::InspectorPanel(QWidget *parent) :
    QWidget(parent)
{
    _layout = new QVBoxLayout;
    setLayout(_layout);
}

InspectorPanel::~InspectorPanel()
{
}

void InspectorPanel::newItemInspected(QObject *object)
{
    if(itemInspected != nullptr) {
        delete itemInspected;
    }
    // todo : switch on cast result

    // Demo
    itemInspected = new IntervalInspectorView(object, this);
    _layout->addWidget(itemInspected);
}
