#ifndef BASICELEMENT_H
#define BASICELEMENT_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QSpinBox>

class BasicElement : public QWidget
{
    Q_OBJECT
public:
    explicit BasicElement(QWidget *parent = 0);

signals:

public slots:
    /*
    * Display or hide contents, onButtonClick
    */
    void expend();

    void renameSection(QString newName);
    void addToSection(QWidget *newWidget);

private:
    QWidget* _container;
    QVBoxLayout* _containerLayout;

    QLabel* _sectionTitle;
    QToolButton* _btn;

    bool isExpended;
};

#endif // BASICELEMENT_H
