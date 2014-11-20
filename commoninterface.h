#ifndef COMMONINTERFACE_H
#define COMMONINTERFACE_H

#include <QWidget>
class QVBoxLayout;
class QLineEdit;
class QPushButton;
class BasicElement;

class CommonInterface : public QWidget
{
    Q_OBJECT
public:
    explicit CommonInterface(QObject *inspectedObj = 0, QWidget *parent = 0);

signals:

public slots:
    // Manage Sections
    void addNewSection(QString sectionName, QWidget* content);
    void addInSection(QString sectionName, QWidget* content); //todo
    void insertSection(int index, QString name, QWidget* content = 0);
    void removeSection(QString sectionName); //todo
    void moveSection(int oldIndex, int newIndex, QString sectionName = ""); //todo
    void moveSections(); //todo

    // Manage Values
    void updateDisplayedValues(QObject *obj);
    void changeColor(); //todo

    QVBoxLayout* contentLayout() {return _layout;}

private:
    void init();

    QVBoxLayout *_layout;
    QLineEdit *_objectName;
    QPushButton *_colorButton;
    QPixmap *_colorButtonPixmap;
    QLineEdit *_comments;

    QObject *_inspectedObject;
};

#endif // COMMONINTERFACE_H
