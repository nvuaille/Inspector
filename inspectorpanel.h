#ifndef INSPECTORPANEL_H
#define INSPECTORPANEL_H

#include <QWidget>

class QVBoxLayout;
class CommonInterface;

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
    CommonInterface* itemInspected = nullptr;

};

#endif // INSPECTORPANEL_H
