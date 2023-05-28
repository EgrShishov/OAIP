#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <QCursor>

class hexagon : public figure
{
public:
    hexagon(double x1, double x2, double a);
    ~hexagon();

    double perimetr() const;
    double area() const;

    void wheelEvent(QGraphicsSceneWheelEvent *event);
    QPointF getCentre();

public slots:

private:
    QPointF centre;
    double a,x1,x2;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;
};

#endif // HEXAGON_H
