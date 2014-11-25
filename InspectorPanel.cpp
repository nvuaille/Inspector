#include "InspectorPanel.hpp"
#include "ui_inspectorpanel.h"
#include "QPushButton"
#include <QLayout>
#include <QDebug>

#include "IntervalInspectorview.hpp"
#include "InspectorSectionWidget.hpp"
#include "InspectorWidget.hpp"

InspectorPanel::InspectorPanel(QWidget *parent) :
    QWidget(parent)
{
    _layout = new QVBoxLayout;
    _layout->setMargin(8);

    setLayout(_layout);
    setMinimumWidth(300);
//    setMaximumHeight(300);
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
    InspectorWidget *factory = new InspectorWidget;
    InspectorWidgetInterface* item = factory->makeWidget(object);

    _layout->addWidget(item);
}
