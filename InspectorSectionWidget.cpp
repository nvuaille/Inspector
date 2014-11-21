#include "InspectorSectionWidget.hpp"

#include <QLayout>
#include <QLabel>
#include <QToolButton>
#include <QDebug>

InspectorSectionWidget::InspectorSectionWidget(QWidget *parent) :
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
    _isExpended = true;
    _btn->setArrowType(Qt::DownArrow);

    setLayout(globalLayout);

    renameSection("Section Name");
}

InspectorSectionWidget::InspectorSectionWidget(QString name, QWidget *content, QWidget *parent) :
    InspectorSectionWidget(parent)
{
    renameSection(name);
    setObjectName(name);
    addToCurrentSection(content);
}

InspectorSectionWidget::~InspectorSectionWidget()
{

}

void InspectorSectionWidget::expend()
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

void InspectorSectionWidget::renameSection(QString newName)
{
    _sectionTitle->setText(newName);
 //   _sectionTitle->setObjectName(newName);
}

void InspectorSectionWidget::addToCurrentSection(QWidget *newWidget)
{
    _containerLayout->addWidget(newWidget);
    _container->setLayout(_containerLayout);
}

void InspectorSectionWidget::insertInSection(int index, QWidget *newWidget)
{
    _containerLayout->insertWidget(index, newWidget);
    _container->setLayout(_containerLayout);
}



