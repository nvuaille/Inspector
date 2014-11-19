#include "inspectorpanel.h"
#include "ui_inspectorpanel.h"
#include "QPushButton"
#include <QLayout>

#include "commoninterface.h"
#include "basicelement.h"

InspectorPanel::InspectorPanel(QWidget *parent) :
    QWidget(parent)
{
    _layout = new QVBoxLayout;
    setLayout(_layout);

    //demo
    newItemInspected();
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
    itemInspected = new CommonInterface;
    _layout->addWidget(itemInspected);
}

void InspectorPanel::addSection(QString name, QWidget *content)
{
    BasicElement* section = new BasicElement(this);
    section->renameSection(name);
    section->addToSection(content);
    _layout->addWidget(section);
}

