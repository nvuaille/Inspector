#include "commoninterface.h"
#include "basicelement.h"

#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

static const int COLOR_ICON_SIZE = 21;

CommonInterface::CommonInterface(QWidget *parent) :
    QWidget(parent)
{
    _layout = new QVBoxLayout;
    setLayout(_layout);

    init();
    addNewSection("Comment", new QLineEdit);
    updateDisplayedValues();

    //findChild<QWidget*>("ElementColor")->setVisible(false);

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

void CommonInterface::updateDisplayedValues()
{
    _objectName->setText("objectX"); // récupérer direct le vrai nom
    _colorButtonPixmap->fill(QColor(Qt::gray)); // récupérer direct la vraie couleur
    _colorButton->setIcon(QIcon(*_colorButtonPixmap));

}

void CommonInterface::changeColor()
{

}

void CommonInterface::init()
{
    // Name
    QWidget *nameLine = new QWidget(this);
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Object Name : ");
    _objectName = new QLineEdit;
    nameLine->setObjectName("ElementName");

    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(_objectName);
    nameLine->setLayout(nameLayout);
    _layout->addWidget(nameLine);

    //Color
    QWidget *colorLine = new QWidget(this);
    QHBoxLayout *colorLayout = new QHBoxLayout;
    QLabel *colorLabel = new QLabel("Object Color : ");
    colorLine->setObjectName("ElementColor");
    _colorButton = new QPushButton;
    _colorButton->setMaximumSize(QSize(1.5*COLOR_ICON_SIZE, 1.5*COLOR_ICON_SIZE));
    _colorButton->setIconSize(QSize(COLOR_ICON_SIZE, COLOR_ICON_SIZE));
    _colorButtonPixmap = new QPixmap(4 * COLOR_ICON_SIZE / 3, 4 * COLOR_ICON_SIZE / 3);

    _colorButton->setIcon(QIcon(*_colorButtonPixmap));

    colorLayout->addWidget(colorLabel);
    colorLayout->addWidget(_colorButton);
    colorLayout->addWidget(new QLabel);  // trouver mieux !!
    colorLine->setLayout(colorLayout);
    _layout->addWidget(colorLine);

    // Connection
    connect(_colorButton, SIGNAL(clicked()), this, SLOT(changeColor()));  // Le slot sera dans un 'presenteur'
}
