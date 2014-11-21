#include "InspectorSectionWidget.hpp"
#include "InspectorWidgetInterface.hpp"

#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QScrollArea>
#include <QScrollBar>
#include <QDebug>

static const int COLOR_ICON_SIZE = 21;

InspectorWidgetInterface::InspectorWidgetInterface(QObject *inspectedObj, QWidget *parent) :
    QWidget(parent), _inspectedObject{inspectedObj}
{
    _layout = new QVBoxLayout;
    setLayout(_layout);

    // Object Name : label + lineEdit in a container
    QWidget *nameLine = new QWidget(this);
    QHBoxLayout *nameLayout = new QHBoxLayout;
    _objectName = new QLineEdit;
    nameLine->setObjectName("ElementName");

    nameLayout->addWidget(_objectName);
    nameLine->setLayout(nameLayout);

    _colorButton = new QPushButton;
    _colorButton->setMaximumSize(QSize(1.5*COLOR_ICON_SIZE, 1.5*COLOR_ICON_SIZE));
    _colorButton->setIconSize(QSize(COLOR_ICON_SIZE, COLOR_ICON_SIZE));
    _colorButtonPixmap = new QPixmap(4 * COLOR_ICON_SIZE / 3, 4 * COLOR_ICON_SIZE / 3);

    _colorButton->setIcon(QIcon(*_colorButtonPixmap));

    nameLayout->addWidget(_colorButton);
    _layout->addWidget(nameLine);

    // Connection
    connect(_colorButton, SIGNAL(clicked()), this, SLOT(changeColor()));
/*
    _scrollArea = new QScrollArea;
    _scrollArea->setLayout(new QVBoxLayout);
    _layout->addWidget(_scrollArea);
*/
    QScrollArea *propertiesArea = new QScrollArea;
    propertiesArea->setVerticalScrollBar(new QScrollBar);
    QWidget *areaContent = new QWidget;
    QVBoxLayout *contentLayout = new QVBoxLayout;
    areaContent->setLayout(contentLayout);
    propertiesArea->setMinimumHeight(150);
    propertiesArea->setWidgetResizable(true);
    propertiesArea->setWidget(areaContent);

    addNewSection("Properties", propertiesArea);
    _comments = new QLineEdit;
    addNewSection("Comment", _comments);
}

void InspectorWidgetInterface::addNewSection(QString sectionName, QWidget *content)
{
    InspectorSectionWidget* section = new InspectorSectionWidget(this);
    section->renameSection(sectionName);
    section->addToCurrentSection(content);
    section->setObjectName(sectionName);
    _layout->addWidget(section);
}

void InspectorWidgetInterface::addInSection(QString sectionName, QString objectName, QWidget *content)
{
    InspectorSectionWidget* section = findChild<InspectorSectionWidget*>(sectionName);

    if(section != nullptr) {
        if(sectionName.compare("Properties") == 0) {
            section->findChild<QScrollArea*>()->widget()->layout()->addWidget(new InspectorSectionWidget(objectName, content));
        }
        else
        {
            section->addToCurrentSection(content);
            section->renameSection(objectName);
        }
    }
}

void InspectorWidgetInterface::insertSection(int index, QString name, QWidget *content)
{
    InspectorSectionWidget* section = new InspectorSectionWidget(this);
    section->renameSection(name);
    section->addToCurrentSection(content);
    section->setObjectName(name);
    _layout->insertWidget(index, section);
}

void InspectorWidgetInterface::removeSection(QString sectionName)
{

}

void InspectorWidgetInterface::moveSection(int oldIndex, int newIndex, QString sectionName)
{

}

void InspectorWidgetInterface::moveSections()
{

}

void InspectorWidgetInterface::updateDisplayedValues(QObject *obj)
{
    // DEMO
    if (obj != nullptr) {
        _objectName->setText(obj->objectName()); // récupérer direct le vrai nom
        _colorButtonPixmap->fill(QColor(Qt::gray)); // récupérer direct la vraie couleur
        _colorButton->setIcon(QIcon(*_colorButtonPixmap));
        _comments->setText(obj->metaObject()->className());
        _inspectedObject = obj;
    }
}

void InspectorWidgetInterface::changeColor()
{

}

