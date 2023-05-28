#include "rectangle.h"

rectangle::rectangle(double width,double height)
{
   this->width=width*scale;
   this->height=height*scale;
}

rectangle::~rectangle()
{

}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black,1);
    painter->setBrush(QColor(255, 0, 0, 127));
    painter->setPen(pen);
    painter->drawRect(-30,-30,width,height);
}

QRectF rectangle::boundingRect() const
{
    return QRectF(-30, -30, width, height);
}

void rectangle::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (event->delta() < 0)
        scale -= 0.1;
    if ((event->delta() > 0))
        scale += 0.1;
    update();
}

QPointF rectangle::getCentre()
{
   return this->pos();
}

double rectangle::area() const
{
    if(this!=nullptr)
    return 2*width*height*scale*scale;
    else return 0;
}

double rectangle::perimetr() const
{
    return 2*(width+height)*scale;
}

