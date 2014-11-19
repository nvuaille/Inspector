#include "intervalinspectorview.h"

#include <QLabel>
#include <QSpinBox>
#include <QLayout>
#include <QWidget>
#include <QToolButton>

intervalInspectorView::intervalInspectorView(QWidget *parent) :
    CommonInterface(parent)
{


    // Add Automation Section
    QWidget* title = new QWidget;
    QHBoxLayout* titleLayout = new QHBoxLayout;
    QLabel* sectionTitle = new QLabel("Add Automation");
    QToolButton* btn = new QToolButton;

    titleLayout->addWidget(btn);
    titleLayout->addWidget(sectionTitle);
    title->setLayout(titleLayout);

 //   connect(_btn, SIGNAL(released()), this, SLOT(addAutomation()));
    btn->setText("+");

     contentLayout()->insertWidget(2, title);

    // Other section
    insertSection(2, "Duration", new QSpinBox );
}
