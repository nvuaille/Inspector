#include "basicelement.h"

#include <QLayout>
#include <QLabel>
#include <QToolButton>


BasicElement::BasicElement(QWidget *parent) :
    QWidget(parent)
{
    init();
    renameSection("Section Name");
}

BasicElement::BasicElement(QString name, QWidget *content, QWidget *parent)
{
    init();
    renameSection(name);
    addToSection(content);
}

BasicElement::~BasicElement()
{

}

void BasicElement::init()
{
    // HEADER : arrow and name
    QWidget* title = new QWidget;
    QHBoxLayout* titleLayout = new QHBoxLayout;
    _sectionTitle = new QLabel;
    _btn = new QToolButton;

    titleLayout->addWidget(_btn);
    titleLayout->addWidget(_sectionTitle);
    title->setLayout(titleLayout);

    // CONTENT
    _container = new QWidget;
    _containerLayout = new QVBoxLayout;

    // GENERAL
    QVBoxLayout* globalLayout = new QVBoxLayout;
    globalLayout->addWidget(title);
    globalLayout->addWidget(_container);

    connect(_btn, SIGNAL(released()), this, SLOT(expend()));

    // INIT
    _isExpended = true;
    _btn->setArrowType(Qt::DownArrow);

    setLayout(globalLayout);
}

void BasicElement::expend()
{
    _isExpended = !_isExpended;
    _container->setVisible(_isExpended);
    if (_isExpended) {
        _btn->setArrowType(Qt::DownArrow);
    }
    else {
        _btn->setArrowType(Qt::RightArrow);
    }
}

void BasicElement::renameSection(QString newName)
{
    _sectionTitle->setText(newName);
}

void BasicElement::addToSection(QWidget *newWidget)
{
    _containerLayout->addWidget(newWidget);
    _container->setLayout(_containerLayout);
}

void BasicElement::insertInSection(int index, QWidget *newWidget)
{
    _containerLayout->insertWidget(index, newWidget);
    _container->setLayout(_containerLayout);
}



