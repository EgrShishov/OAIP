#ifndef CLOWN_H
#define CLOWN_H

#include "figure.h"
#include <QObject>
#include <QPainter>
#include <QGraphicsItem>

class clown : public figure
{
public:
    clown();
    ~clown();

    double perimetr() const
    {
        return 40*scale;
    }
    double area() const
    {
        return 49*scale;
    }

    void wheelEvent(QGraphicsSceneWheelEvent *event){}
    QPointF getCentre(){}
private:
    qreal scale=1;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // CLOWN_H
