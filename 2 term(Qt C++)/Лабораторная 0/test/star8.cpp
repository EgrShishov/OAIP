#include "star8.h"

star8::star8(double x,double y,double radius)
{
    this->x=x;
    this->y=y;
    this->radius=radius;
}

star8::~star8()
{

}

QRectF star8::boundingRect() const
{
    return QRectF(-100,-100,radius*radius,radius*radius);
}

void star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    QPainterPath path(QPoint(x,y-radius));
    double x2, y2, x3, y3;
    int num=8;

       for (int i = 1; i <= num; i++)
       {
           x2 = x + sin((i * 2 - 1) * 3.14 / num) * radius / 2;
           y2 = y - cos((i * 2 - 1) * 3.14 / num) * radius / 2;
           x3 = x + sin(i * 2 * 3.14 / num) * radius;
           y3 = y - cos(i * 2 * 3.14 / num) * radius;

           path.lineTo(x2, y2);
           path.lineTo(x3, y3);
       }

       QPen pen;
       QBrush brush(Qt::gray);
       pen.setColor(Qt::black);
       painter->setBrush(QColor(196,255,196));
       pen.setWidth(1);
       painter->setPen(pen);
       painter->drawPath(path);

}

double star8::perimetr() const
{
    return 6 * 2 * sqrt(pow((x + sin(3.14 / 8) * radius *scale / 2) - (x + sin(6.28 / 8) * radius*scale + 1), 2)
           + pow((y - cos(3.14 / 8) * radius*scale / 2) - (y - cos(6.28 / 8) * radius*scale - 1), 2));
}

double star8::area() const
{
    double x1 = x, y1 = y - radius*scale, x2, y2, x3, y3;
        double square = 0;
        for (int i = 1; i <= 8; i++)
        {
            x2 = x + sin((i * 2 - 1) * 3.14 / 8) * radius * scale / 2;
            y2 = y - cos((i * 2 - 1) * 3.14 / 8) * radius * scale/ 2;
            x3 = x + sin(i * 2 * 3.14 / 8) * radius * scale;
            y3 = y - cos(i * 2 * 3.14 / 8) * radius * scale;

            square += (x1 * y2);
            square -= (y1 * x2);

            square += (x2 * y3);
            square -= (y2 * x3);

            x1 = x3;
            y1 = y3;
        }

        return fabs(square) / 2;
}

QPointF star8::getCentre()
{
return boundingRect().center()+mapToScene(scenePos());
}
