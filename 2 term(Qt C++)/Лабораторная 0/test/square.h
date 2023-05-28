#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class square : public figure
{
public:
    square(double a);
    ~square();

    double perimetr() const;
    double area() const;

    QPointF getCentre();

private:
    double a;
    double size;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;
};

#endif // SQUARE_H
