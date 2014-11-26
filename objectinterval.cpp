#include "objectinterval.hpp"

ObjectInterval::ObjectInterval(QObject *parent) :
    QObject(parent)
{
}

ObjectInterval::ObjectInterval(QString name, QString comments, QColor color, QObject *parent):
    _name{name}, _comments{comments}, _color{color}
{

}
QString ObjectInterval::name() const
{
    return _name;
}

void ObjectInterval::setName(const QString &name)
{
    _name = name;
}
QString ObjectInterval::comments() const
{
    return _comments;
}

void ObjectInterval::setComments(const QString &comments)
{
    _comments = comments;
}
QColor ObjectInterval::color() const
{
    return _color;
}

void ObjectInterval::setColor(const QColor &color)
{
    _color = color;
}



