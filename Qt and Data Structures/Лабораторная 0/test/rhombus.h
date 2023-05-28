#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <QCursor>

class rhombus : public figure
{
public:
    rhombus(double x1,double x2,double a);
    ~rhombus();

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

#endif // RHOMBUS_H
