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
    BasicElement(QString name, QWidget *content, QWidget *parent = 0);
    ~BasicElement();
    BasicElement(const BasicElement&);

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

#endif // BASICELEMENT_H
