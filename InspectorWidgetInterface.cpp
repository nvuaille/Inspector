#include "InspectorSectionWidget.hpp"
#include "InspectorWidgetInterface.hpp"

#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

static const int COLOR_ICON_SIZE = 21;

InspectorWidgetInterface::InspectorWidgetInterface(QObject *inspectedObj, QWidget *parent) :
    QWidget(parent), _inspectedObject{inspectedObj}
{
    _layout = new QVBoxLayout;
    setLayout(_layout);

    init();
    _comments = new QLineEdit;
    addNewSection("Comment", _comments);
    updateDisplayedValues(_inspectedObject);

    //findChild<QWidget*>("ElementColor")->setVisible(false);

}

void InspectorWidgetInterface::init()
{
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
}


void InspectorWidgetInterface::addNewSection(QString sectionName, QWidget *content)
{
    InspectorSectionWidget* section = new InspectorSectionWidget(this);
    section->renameSection(sectionName);
    section->addToSection(content);
    _layout->addWidget(section);
}

void InspectorWidgetInterface::addInSection(QString sectionName, QWidget *content)
{

}

void InspectorWidgetInterface::insertSection(int index, QString name, QWidget *content)
{
    InspectorSectionWidget* section = new InspectorSectionWidget(this);
    section->renameSection(name);
    section->addToSection(content);
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
    _objectName->setText(obj->objectName()); // récupérer direct le vrai nom
    _colorButtonPixmap->fill(QColor(Qt::gray)); // récupérer direct la vraie couleur
    _colorButton->setIcon(QIcon(*_colorButtonPixmap));
    _comments->setText(obj->metaObject()->className());
    _inspectedObject = obj;
}

void InspectorWidgetInterface::changeColor()
{

}

