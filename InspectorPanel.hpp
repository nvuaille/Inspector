#ifndef INSPECTORPANEL_H
#define INSPECTORPANEL_H

#include <QWidget>

class QVBoxLayout;
class InspectorWidgetInterface;

namespace Ui {
class InspectorPanel;
}

class InspectorPanel : public QWidget
{
    Q_OBJECT

public:
    explicit InspectorPanel(QWidget *parent = 0);
    ~InspectorPanel();

    void newItemInspected(QObject *object = 0);

private:

    QVBoxLayout* _layout;
    InspectorWidgetInterface* itemInspected = nullptr;

};

#endif // INSPECTORPANEL_H
