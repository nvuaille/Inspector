#pragma once

#include <QWidget>

class QVBoxLayout;
class InspectorWidgetInterface;

namespace Ui {
class InspectorPanel;
}

/*!
 * \brief The InspectorPanel class manages the main panel.
 *
 *  It creates and displays the view for each inspected element.
 */

class InspectorPanel : public QWidget
{
    Q_OBJECT

public:
    explicit InspectorPanel(QWidget *parent = 0);
    ~InspectorPanel();

    /*!
     * \brief newItemInspected load the view for the selected object
     *
     *  It's called when the user selects a new item
     * \param object The selected objet.
     */
    void newItemInspected(QObject *object = 0);

private:

    QVBoxLayout* _layout;
    InspectorWidgetInterface* itemInspected = nullptr;
};
