#include "hexagon.h"

hexagon::hexagon(double x1,double x2,double a)
{
   this->a=a*scale;
    this->x1=x1;
    this->x2=x2;
}

hexagon::~hexagon()
{

}

void hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black,1);
    QBrush brush(Qt::darkGreen);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPolygon polygon;

       polygon << QPoint(x1, x2) << QPoint(x1 + a, x2) << QPoint(x1 + a * 3 / 2, x2 + a * 1.73/2)
           << QPoint(x1 + a, x2 + a * 1.73) << QPoint(x1, x2 + a * 1.73) << QPoint(x1 - a / 2, x2 + a * 1.73 / 2);

    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF hexagon::boundingRect() const
{
    return QRectF(-30, -30, a*a*10, a*a*10);
}

void hexagon::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (event->delta() < 0)
        scale -= 0.1;
    if ((event->delta() > 0))
        scale += 0.1;
    update();
}

QPointF hexagon::getCentre()
{
return boundingRect().center()+mapToScene(scenePos());
}

double hexagon::area() const
{
    return a * a * 1.73 / 4 * scale * scale;
}

double hexagon::perimetr() const
{
    return 6*a*scale;
}
