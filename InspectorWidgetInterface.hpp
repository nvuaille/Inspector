#ifndef INSPECTORWIDGETINTERFACE_H
#define INSPECTORWIDGETINTERFACE_H

#include <QWidget>
class QVBoxLayout;
class QLineEdit;
class QPushButton;
class InspectorSectionWidget;
class QScrollArea;

class InspectorWidgetInterface : public QWidget
{
    Q_OBJECT
public:
    explicit InspectorWidgetInterface(QObject *inspectedObj = 0, QWidget *parent = 0);

signals:

public slots:
    // Manage Sections
    void addNewSection(QString sectionName, QWidget* content);
    void addInSection(QString sectionName, QString objectName, QWidget* content); //todo
    void insertSection(int index, QString name, QWidget* content = 0);
    void removeSection(QString sectionName); //todo
    void moveSection(int oldIndex, int newIndex, QString sectionName = ""); //todo
    void moveSections(); //todo

    // Manage Values
    void updateDisplayedValues(QObject *obj);
    void changeColor(); //todo

private:
    QVBoxLayout *_layout;
    QLineEdit *_objectName;
    QPushButton *_colorButton;
    QPixmap *_colorButtonPixmap;
    QScrollArea *_scrollArea;
    QLineEdit *_comments;

    QObject *_inspectedObject;
};

#endif // INSPECTORWIDGETINTERFACE_H
