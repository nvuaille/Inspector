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

void InspectorPanel::newItemInspected()
{
    if(itemInspected != nullptr) {
        delete itemInspected;
    }

    // Demo
    itemInspected = new intervalInspectorView;
    _layout->addWidget(itemInspected);
}
