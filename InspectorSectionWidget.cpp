#include "InspectorSectionWidget.hpp"

#include <QLayout>
#include <QLabel>
#include <QToolButton>
#include <QDebug>
#include <QScrollArea>
#include <QScrollBar>

InspectorSectionWidget::InspectorSectionWidget(QWidget *parent) :
    QWidget(parent)
{
    // HEADER : arrow button and name
    QWidget* title = new QWidget;
    QHBoxLayout* titleLayout = new QHBoxLayout;
    _sectionTitle = new QLabel;
    _btn = new QToolButton;

    titleLayout->addWidget(_btn);
    titleLayout->addWidget(_sectionTitle);
    title->setLayout(titleLayout);

    // CONTENT
    _container = new QScrollArea;
    QWidget *areaContent = new QWidget;

    _container->setMinimumSize(150,150);
    _container->setWidgetResizable(true);
//    _container->setVerticalScrollBar(new QScrollBar);
    _containerLayout = new QVBoxLayout;
    _containerLayout->setMargin(0);
    _containerLayout->addStretch();
    areaContent->setLayout(_containerLayout);
    _container->setWidget(areaContent);

    // GENERAL
    QVBoxLayout* globalLayout = new QVBoxLayout;
    globalLayout->addWidget(title);
    globalLayout->addWidget(_container);
    globalLayout->setMargin(5);
//    globalLayout->setContentsMargins(5,5,5,5);
    connect(_btn, SIGNAL(released()), this, SLOT(expend()));

    // INIT
    _isExpended = true;
    _btn->setArrowType(Qt::DownArrow);
    expend();

    setLayout(globalLayout);

    renameSection("Section Name");
}

InspectorSectionWidget::InspectorSectionWidget(QString name, QWidget *parent) :
    InspectorSectionWidget(parent)
{
    renameSection(name);
    setObjectName(name);
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
}

void InspectorSectionWidget::addContent(QWidget *newWidget)
{
    _containerLayout->insertWidget(_containerLayout->count()-1, newWidget);
    //_containerLayout->addWidget(newWidget);
}

void InspectorSectionWidget::insertInSection(int index, QWidget *newWidget)
{
    _containerLayout->insertWidget(index, newWidget);
    _container->setLayout(_containerLayout);
}
