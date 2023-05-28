#include "square.h"

square::square(double a)
{
   this->a=a;
}

square::~square()
{

}

double square::area() const
{
    return scale*scale*a*a;
}

double square::perimetr() const
{
    return scale*4*a;
}

void square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black,1);
    painter->setPen(pen);
    painter->setBrush(QColor(0, 0, 255, 127));
    painter->drawRect(-30,-30,a,a);
}

QRectF square::boundingRect() const
{
    return QRectF(-30, -30, a, a);
}

QPointF square::getCentre()
{
return boundingRect().center()+mapToScene(scenePos());
}
