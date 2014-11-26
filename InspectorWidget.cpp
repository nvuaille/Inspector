#include "InspectorWidget.hpp"
#include "IntervalInspectorview.hpp"
#include <QDebug>

//using namespace iscore;

InspectorWidgetInterface *InspectorWidget::makeWidget(QObject *sourceElement)
{
    return new IntervalInspectorView(static_cast<ObjectInterval*>(sourceElement));
}

InspectorWidgetInterface *InspectorWidget::makeWidget(QList<QObject *> sourceElements)
{
    return new IntervalInspectorView(static_cast<ObjectInterval*>(sourceElements.at(0)));
}
