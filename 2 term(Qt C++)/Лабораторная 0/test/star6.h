#ifndef STAR6_H
#define STAR6_H

#include "figure.h"

class star6 : public figure
{
public:
    star6(double x,double y,double radius);
    ~star6();

    double perimetr() const;
    double area() const;

    QPointF getCentre();

private:

    double x,y,radius;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

};

#endif // STAR6_H
