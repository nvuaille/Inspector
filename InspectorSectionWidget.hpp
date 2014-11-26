#pragma once

#include <QWidget>
class QVBoxLayout;
class QLabel;
class QToolButton;
class QScrollArea;

/** @brief InspectorSectionWidget is widget that can fold or unfold his content.
 *
 * A header with a name is always displayed.
 * It contains one main widget in a QScrollArea with a vertical layout, that can be folded/unfolded on click on the arrow button.
 */

class InspectorSectionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InspectorSectionWidget(QWidget *parent = 0);
    InspectorSectionWidget(QString name, QWidget *parent = 0);
    ~InspectorSectionWidget();

signals:

public slots:

    // Display tool
    void expend();

    // Manage section

    //! change the name in the header
    void renameSection(QString newName);
    //! add the widget newWidget in the main layout
    void addContent(QWidget *newWidget);
    //! insert newWidget at the index rank in the main layout
    void insertInSection(int index, QWidget *newWidget);

private:

    QScrollArea* _container = nullptr;
    QVBoxLayout* _containerLayout = nullptr; /*!< main layout */

    QLabel* _sectionTitle = nullptr; /*!< header label \todo editable ? */
    QToolButton* _btn = nullptr; /*!< button for the fold/unfold action */

    bool _isUnfolded;
};
