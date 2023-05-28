#ifndef STAR_H
#define STAR_H

#include <QPainter>
#include "figure.h"
class star : public figure
{
public:
    star(double x,double y,double radius);
    ~star();

    double perimetr() const;
    double area() const;

    QPointF getCentre();

private:
    double x,y,radius;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;
};

#endif // STAR_H
