#ifndef INTERVALINSPECTORVIEW_H
#define INTERVALINSPECTORVIEW_H

#include "commoninterface.h"

class IntervalInspectorView : public CommonInterface
{
    Q_OBJECT
public:
    explicit IntervalInspectorView(QObject *object, QWidget *parent = 0);

signals:

public slots:
    void addAutomation();

private:

};

#endif // INTERVALINSPECTORVIEW_H
