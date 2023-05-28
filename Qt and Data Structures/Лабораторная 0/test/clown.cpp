#include "clown.h"

clown::clown()
{

}

clown::~clown()
{

}

void clown::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   int arrowWidth=30,arrowHeight=30;
    QPolygon arrow;
           arrow << QPoint(0, -arrowWidth/2)
                 << QPoint(arrowHeight, 0)
                 << QPoint(0, arrowWidth/2);

           QPointF p0(100,100);
           QPointF p1(200,100);
           double dx = p1.x() - p0.x();
           double dy = p1.y() - p0.y();
           double angle = atan2(dy, dx);
           QPointF p2(p1.x() - arrowHeight * cos(angle),
                      p1.y() - arrowHeight * sin(angle));
           double lineLen = sqrt(dx*dx + dy*dy);

           if(lineLen >= arrowHeight){
               painter->drawLine(p0, p2);
           }
           painter->save();
           painter->translate(p2);
           painter->rotate(180/3.14159 * angle);
           painter->drawConvexPolygon(arrow);
           painter->restore();
}

QRectF clown::boundingRect() const
{
    return QRectF(0,0,200*scale,200*scale);
}
