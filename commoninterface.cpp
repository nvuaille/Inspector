#include "commoninterface.h"
#include "basicelement.h"

#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

static const int COLOR_ICON_SIZE = 21;

CommonInterface::CommonInterface(QObject *inspectedObj, QWidget *parent) :
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

void CommonInterface::init()
{
    // Object Name : label + lineEdit in a container
    QWidget *nameLine = new QWidget(this);
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Name : ");
    _objectName = new QLineEdit;
    nameLine->setObjectName("ElementName");

    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(_objectName);
    nameLine->setLayout(nameLayout);
    _layout->addWidget(nameLine);

    // Object Color : label + button in a container.
    QWidget *colorLine = new QWidget(this);
    QHBoxLayout *colorLayout = new QHBoxLayout;
    QLabel *colorLabel = new QLabel("Color : ");
    colorLine->setObjectName("ElementColor");
    _colorButton = new QPushButton;
    _colorButton->setMaximumSize(QSize(1.5*COLOR_ICON_SIZE, 1.5*COLOR_ICON_SIZE));
    _colorButton->setIconSize(QSize(COLOR_ICON_SIZE, COLOR_ICON_SIZE));
    _colorButtonPixmap = new QPixmap(4 * COLOR_ICON_SIZE / 3, 4 * COLOR_ICON_SIZE / 3);

    _colorButton->setIcon(QIcon(*_colorButtonPixmap));

    colorLayout->addWidget(colorLabel);
    colorLayout->addWidget(_colorButton);
    colorLayout->addWidget(new QLabel);  // manage space. --> trouver mieux !!
    colorLine->setLayout(colorLayout);
    _layout->addWidget(colorLine);

    // Connection
    connect(_colorButton, SIGNAL(clicked()), this, SLOT(changeColor()));
}


void CommonInterface::addNewSection(QString sectionName, QWidget *content)
{
    BasicElement* section = new BasicElement(this);
    section->renameSection(sectionName);
    section->addToSection(content);
    _layout->addWidget(section);
}

void CommonInterface::addInSection(QString sectionName, QWidget *content)
{

}

void CommonInterface::insertSection(int index, QString name, QWidget *content)
{
    BasicElement* section = new BasicElement(this);
    section->renameSection(name);
    section->addToSection(content);
    _layout->insertWidget(index, section);
}

void CommonInterface::removeSection(QString sectionName)
{

}

void CommonInterface::moveSection(int oldIndex, int newIndex, QString sectionName)
{

}

void CommonInterface::moveSections()
{

}

void CommonInterface::updateDisplayedValues(QObject *obj)
{
    // DEMO
    _objectName->setText(obj->objectName()); // récupérer direct le vrai nom
    _colorButtonPixmap->fill(QColor(Qt::gray)); // récupérer direct la vraie couleur
    _colorButton->setIcon(QIcon(*_colorButtonPixmap));
    _comments->setText(obj->metaObject()->className());
    _inspectedObject = obj;
}

void CommonInterface::changeColor()
{

}

