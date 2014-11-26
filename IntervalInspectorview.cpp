#include "IntervalInspectorview.hpp"
#include "InspectorSectionWidget.hpp"

#include <QLabel>
#include <QSpinBox>
#include <QLayout>
#include <QWidget>
#include <QToolButton>
#include <QDebug>
#include <QScrollArea>

IntervalInspectorView::IntervalInspectorView(ObjectInterval *object, QWidget *parent) :
    InspectorWidgetInterface(parent)
{
    setObjectName("Interval");

    // Add Automation Section
    QWidget* automTitle = new QWidget;
    QHBoxLayout* automTitleLayout = new QHBoxLayout;
    QLabel* sectionTitle = new QLabel("Add Automation");
    QToolButton* btn = new QToolButton;
    btn->setText("+");
    btn->setObjectName("addAutom");

    automTitleLayout->addWidget(btn);
    automTitleLayout->addWidget(sectionTitle);
    automTitle->setLayout(automTitleLayout);

    connect(btn, SIGNAL(released()), this, SLOT(addAutomation()));

    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setLineWidth(2);

    // Sections
    static_cast<QVBoxLayout*>(layout())->insertWidget(layout()->count()-2, automTitle);
    insertSection( layout()->count()-2, "Automations", new InspectorSectionWidget);
    static_cast<QVBoxLayout*>(layout())->insertWidget(layout()->count()-2, line);
    insertSection( layout()->count()-2, "Start", new QLabel("Start state"));
    insertSection( layout()->count()-2, "End", new QLabel("End state"));

    // display data
    updateDisplayedValues(object);
}

void IntervalInspectorView::addAutomation()
{
    InspectorSectionWidget* autom = findChild<InspectorSectionWidget*>("Automations");
    if (autom != nullptr) {
        autom->addContent(new InspectorSectionWidget);

    }
}

void IntervalInspectorView::updateDisplayedValues(ObjectInterval *obj)
{
    // DEMO
    if (obj != nullptr) {
        setName(obj->name());
        setColor(obj->color());
        setComments(obj->comments());
        setInspectedObject(obj);
        changeLabelType("TimeBox");
    }
}
