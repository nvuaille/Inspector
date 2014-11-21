#include "InspectorWidget.hpp"
#include "IntervalInspectorview.hpp"
#include <QDebug>

//using namespace iscore;

InspectorWidgetInterface *InspectorWidget::makeWidget(QObject *sourceElement)
{
    return new IntervalInspectorView(sourceElement);
}

InspectorWidgetInterface *InspectorWidget::makeWidget(QList<QObject *> sourceElements)
{
    return new IntervalInspectorView(sourceElements.at(0));
}
