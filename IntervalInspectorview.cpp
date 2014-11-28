#include "IntervalInspectorview.hpp"
#include "InspectorSectionWidget.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QLayout>
#include <QFormLayout>
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

    // line
    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setLineWidth(2);

    QWidget *startWidget = new QWidget;
    _startForm = new QFormLayout(startWidget);

    // Sections
    areaLayout()->insertWidget(1, automTitle);
    insertSection( 0, "Automations");
    areaLayout()->insertWidget(2, line);
    insertSection( 3, "Start", startWidget);
    insertSection( 4, "End", new QLabel("End state"));

    std::vector<QString>::iterator it;
    for( it = object->automations()->begin(); it != object->automations()->end() ; it++ ) {
        addAutomation(*it);
    }

    // display data
    updateDisplayedValues(object);
}

void IntervalInspectorView::addAutomation(QString address)
{
    InspectorSectionWidget* autom = findChild<InspectorSectionWidget*>("Automations");
    if (autom != nullptr) {
        autom->addContent(new InspectorSectionWidget(address));

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
        _startForm->addRow("/first/message", new QLineEdit);

    }
}
