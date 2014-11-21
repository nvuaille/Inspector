#include "IntervalInspectorview.hpp"
#include "InspectorSectionWidget.hpp"

#include <QLabel>
#include <QSpinBox>
#include <QLayout>
#include <QWidget>
#include <QToolButton>
#include <QDebug>
#include <QScrollArea>

IntervalInspectorView::IntervalInspectorView(QObject *object, QWidget *parent) :
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
    addInSection("Properties", "Duration", new QSpinBox);
    addInSection("Properties", "Automations", new InspectorSectionWidget);
    static_cast<QVBoxLayout*>(layout())->insertWidget(layout()->count()-1, automTitle);
    static_cast<QVBoxLayout*>(layout())->insertWidget(layout()->count()-1, line);

    // display data
    updateDisplayedValues(object);
}

void IntervalInspectorView::addAutomation()
{
    InspectorSectionWidget* autom = this->findChild<InspectorSectionWidget*>("Automations");
    qDebug() << this->children();
    if (autom != nullptr) {
        autom->addToCurrentSection(new InspectorSectionWidget);
    }
}
