#ifndef INSPECTORSECTIONWIDGET_H
#define INSPECTORSECTIONWIDGET_H

#include <QWidget>
class QVBoxLayout;
class QLabel;
class QToolButton;
class QScrollArea;

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
    void renameSection(QString newName);
    void addContent(QWidget *newWidget);
    void insertInSection(int index, QWidget *newWidget);

private:

    QScrollArea* _container = nullptr;
    QVBoxLayout* _containerLayout = nullptr;

    QLabel* _sectionTitle = nullptr;
    QToolButton* _btn = nullptr;

    bool _isExpended;
};

#endif // INSPECTORSECTIONWIDGET_H
