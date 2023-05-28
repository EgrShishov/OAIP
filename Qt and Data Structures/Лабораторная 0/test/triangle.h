#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <QCursor>

class triangle : public figure
{
public:
    triangle();
    ~triangle();

    double perimetr() const;
    double area() const;

    void wheelEvent(QGraphicsSceneWheelEvent *event);
    QPointF getCentre();

public slots:
    QPointF setPointA();
    QPointF setPointB();
    QPointF setPointC();

private:
    QPoint A,B,C;
    double a,b,c;
    QPointF centre;
    double size;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;
};

#endif // TRIANGLE_H
