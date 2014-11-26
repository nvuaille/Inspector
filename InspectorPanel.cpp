#include "InspectorPanel.hpp"
#include "ui_inspectorpanel.h"
#include "QPushButton"
#include <QLayout>
#include <QDebug>
#include <QScrollArea>

#include "IntervalInspectorview.hpp"
#include "InspectorSectionWidget.hpp"
#include "InspectorWidget.hpp"

InspectorPanel::InspectorPanel(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    QScrollArea *globalArea = new QScrollArea;
    QWidget *globalContent = new QWidget;
    globalArea->setWidgetResizable(true);

    _layout = new QVBoxLayout;
    _layout->setMargin(8);
    globalContent->setLayout(_layout);
    globalArea->setWidget(globalContent);
    lay->addWidget(globalArea);

    setMinimumWidth(300);
    setMaximumHeight(600);
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
