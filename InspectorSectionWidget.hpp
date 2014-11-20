#ifndef INSPECTORSECTIONWIDGET_H
#define INSPECTORSECTIONWIDGET_H

#include <QWidget>
class QVBoxLayout;
class QLabel;
class QToolButton;

class InspectorSectionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InspectorSectionWidget(QWidget *parent = 0);
    InspectorSectionWidget(QString name, QWidget *content, QWidget *parent = 0);
    ~InspectorSectionWidget();
    InspectorSectionWidget(const InspectorSectionWidget&);

    void init();

signals:

public slots:

    // Display tool
    void expend();

    // Manage section
    void renameSection(QString newName);
    void addToSection(QWidget *newWidget);
    void insertInSection(int index, QWidget *newWidget);

private:

    QWidget* _container;
    QVBoxLayout* _containerLayout;

    QLabel* _sectionTitle;
    QToolButton* _btn;

    bool _isExpended;
};

#endif // INSPECTORSECTIONWIDGET_H
