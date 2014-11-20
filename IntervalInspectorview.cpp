#include "IntervalInspectorview.hpp"

#include <QLabel>
#include <QSpinBox>
#include <QLayout>
#include <QWidget>
#include <QToolButton>

IntervalInspectorView::IntervalInspectorView(QObject *object, QWidget *parent) :
    InspectorWidgetInterface(parent)
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
    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setLineWidth(2);

    // Sections
    contentLayout()->insertWidget(2, line);
    insertSection(3, "Duration", new QSpinBox );

    // display data
    updateDisplayedValues(object);
}

void IntervalInspectorView::addAutomation()
{

}