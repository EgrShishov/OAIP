#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <QCursor>

class rectangle : public figure
{
public:
    rectangle(double width,double height);
    ~rectangle();

    double perimetr() const;
    double area() const;

    void wheelEvent(QGraphicsSceneWheelEvent *event);
    QPointF getCentre();

public slots:

private:
    QPointF centre;
    double width,height;
    double size;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QRectF boundingRect() const;
};

#endif // RECTANGLE_H
