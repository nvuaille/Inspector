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
    explicit CommonInterface(QWidget *parent = 0);

signals:

public slots:
    // Manage Sections
    void addNewSection(QString sectionName, QWidget* content);
    void addInSection(QString sectionName, QWidget* content);
    void insertSection(int index, QString name, QWidget* content = 0);
    void removeSection(QString sectionName);
    void moveSection(int oldIndex, int newIndex, QString sectionName = "");
    void moveSections();

    // Manage Values
    void updateDisplayedValues();
    void changeColor();

    // Navigation
//    BasicElement & getSection(QString name) const;

    QVBoxLayout* contentLayout() {return _layout;}

private:
    void init();

    QVBoxLayout *_layout;
    QLineEdit *_objectName;
    QPushButton *_colorButton;
    QPixmap *_colorButtonPixmap;
};

#endif // COMMONINTERFACE_H
