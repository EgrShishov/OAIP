#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"
#include <QCursor>

class ellipse : public figure
{
public:
    ellipse(double R);
    ~ellipse();

    double perimetr() const;
    double area() const;

    void wheelEvent(QGraphicsSceneWheelEvent *event);
    QPointF getCentre();

private:
    //double scale=1.1;
    QPointF centre;
    double R;
    double size;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;
};

#endif // ELLIPSE_H
