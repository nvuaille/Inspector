#ifndef COMMONINTERFACE_H
#define COMMONINTERFACE_H

#include <QWidget>
class QVBoxLayout;
class QLineEdit;
class QPushButton;

class CommonInterface : public QWidget
{
    Q_OBJECT
public:
    explicit CommonInterface(QWidget *parent = 0);

signals:

public slots:
    void addSection(QString name, QWidget* content);
    void setValues();

private:
    void init();

    QVBoxLayout *_layout;
    QLineEdit *_objectName;
    QPushButton *_colorButton;
    QPixmap *_colorButtonPixmap;
};

#endif // COMMONINTERFACE_H
