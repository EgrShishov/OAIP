#ifndef STAR8_H
#define STAR8_H

#include "figure.h"

class star8 : public figure
{
public:
    star8(double x,double y,double radius);
    ~star8();

    double perimetr() const;
    double area() const;

    QPointF getCentre();

private:

    double x,y,radius;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;

};

#endif // STAR8_H
