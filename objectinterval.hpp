#ifndef OBJECTINTERVAL_HPP
#define OBJECTINTERVAL_HPP

#include <QObject>
#include <QColor>

class ObjectInterval : public QObject
{
    Q_OBJECT
public:
    explicit ObjectInterval(QObject *parent = 0);
    ObjectInterval(QString name, QString comments, QColor color, QObject *parent =0);



    QString name() const;
    void setName(const QString &name);

    QString comments() const;
    void setComments(const QString &comments);

    QColor color() const;
    void setColor(const QColor &color);

signals:

public slots:

private:
    QString _name;
    QString _comments;
    QColor _color;

};

#endif // OBJECTINTERVAL_HPP
