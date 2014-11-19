#ifndef BASICELEMENT_H
#define BASICELEMENT_H

#include <QWidget>
class QVBoxLayout;
class QLabel;
class QToolButton;

class BasicElement : public QWidget
{
    Q_OBJECT
public:
    explicit BasicElement(QWidget *parent = 0);
    ~BasicElement();
    BasicElement(const BasicElement&);

signals:

public slots:

    // Display tool
    void expend();

    // Manage section
    void renameSection(QString newName);
    void addToSection(QWidget *newWidget);

private:
    QWidget* _container;
    QVBoxLayout* _containerLayout;

    QLabel* _sectionTitle;
    QToolButton* _btn;

    bool _isExpended;
};

#endif // BASICELEMENT_H
