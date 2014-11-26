#pragma once

#include "InspectorWidgetInterface.hpp"

/*!
 * \brief The IntervalInspectorView class
 *      Inherits from InspectorWidgetInterface. Manages an inteface for an Interval (Timebox) element.
 */

class IntervalInspectorView : public InspectorWidgetInterface
{
    Q_OBJECT
public:
    explicit IntervalInspectorView(QObject *object, QWidget *parent = 0);

signals:

public slots:
    /*!
     * \brief addAutomation Add an automation
     */
    void addAutomation();

private:

};
