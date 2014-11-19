#include "basicelement.h"

BasicElement::BasicElement(QWidget *parent) :
    QWidget(parent)
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
    isExpended = true;
    _btn->setArrowType(Qt::DownArrow);
    renameSection("Section Name");

    setLayout(globalLayout);
}

void BasicElement::expend()
{
    isExpended = !isExpended;
    _container->setVisible(isExpended);
    if (isExpended) {
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

