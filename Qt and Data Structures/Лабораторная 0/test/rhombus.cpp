#include "rhombus.h"

rhombus::rhombus(double x1,double x2,double a)
{
   this->a=a*scale;
    this->x1=x1;
    this->x2=x2;
}

rhombus::~rhombus()
{

}

void rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black,1);
    QBrush brush(Qt::green);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPolygon polygon;

    polygon << QPoint(x1, x2) << QPoint(x1 + a * 1.73 / 2, x2 + a / 2)
            << QPoint(x1 + a * 1.73, x2) << QPoint(x1 + a * 1.73 / 2, x2 - a / 2);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF rhombus::boundingRect() const
{
    return QRectF(-30, -30, a*a, a*a);
}

void rhombus::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (event->delta() < 0)
        scale -= 0.1;
    if ((event->delta() > 0))
        scale += 0.1;
    update();
}

QPointF rhombus::getCentre()
{
return boundingRect().center()+mapToScene(scenePos());
}

double rhombus::area() const
{
    return a * a * 1.73 / 2 * scale * scale;
}

double rhombus::perimetr() const
{
    return 4*a*scale;
}
