#include "Rectangle.h"
#include <QGraphicsItem>

#define move 20
Rectangle::Rectangle()
{

}
Rectangle::~Rectangle()
{

}

void Rectangle::moveRight()
{
    this->moveBy(move,0);
}

void Rectangle::moveLeft()
{
    this->moveBy(-move,0);
}
void Rectangle::moveUp()
{
    this->moveBy(0,-move);
}
void Rectangle::moveDown()
{
    this->moveBy(0,move);
}

QRectF Rectangle::boundingRect() const
{
   return(QRectF(0,0,800,600));
}

void Rectangle::paint(QPainter* painter,const QStyleOptionGraphicsItem *option, QWidget *widget)
{
Q_UNUSED(option); Q_UNUSED(widget);

    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    QBrush brush(Qt::black);
    painter->setBrush(brush);

    painter->drawRect(200,200,150,50);
    painter->drawRect(300,150,50,50);

    painter->setBrush(Qt::white);
    painter->drawRect(310,160,40,30);
    painter->drawEllipse(200,230,40,40);
    painter->drawEllipse(300,230,40,40);

}
