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
    _layout->setMargin(5);
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

    //addNewSection("Properties");
   // _layout->addWidget(new InspectorSectionWidget("Properties",this));
    _comments = new QLineEdit;
    addNewSection("Comment", _comments);
    _layout->addStretch();
}

void InspectorWidgetInterface::addNewSection(QString sectionName, QWidget *content)
{
    InspectorSectionWidget* section = new InspectorSectionWidget(sectionName, this);
    section->addContent(content);
    _layout->addWidget(section);
}

void InspectorWidgetInterface::addSubSection(QString parentSection, QString subSection, InspectorSectionWidget *content)
{
    InspectorSectionWidget* section = findChild<InspectorSectionWidget*>(parentSection);

    if(section != nullptr) {
        {
            content->renameSection(subSection);
            content->setObjectName(subSection);
            section->addContent(content);
        }
    }
}

void InspectorWidgetInterface::addInSection(QString sectionName, QWidget *content)
{
    InspectorSectionWidget* section = findChild<InspectorSectionWidget*>(sectionName);

    if(section != nullptr) {
        {
            section->addContent(content);
        }
    }
}

void InspectorWidgetInterface::insertSection(int index, QString name, QWidget *content)
{
    InspectorSectionWidget* section = new InspectorSectionWidget(this);
    section->renameSection(name);
    section->addContent(content);
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

