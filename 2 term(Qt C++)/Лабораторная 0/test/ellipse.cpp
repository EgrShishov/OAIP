#include "ellipse.h"

ellipse::ellipse(double R)
{
   this->R=R;
}

ellipse::~ellipse()
{

}

void ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(Qt::yellow);
    QPen pen(4);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(brush);

    double c=R*((scale-1)*2+1);
    painter->drawEllipse(R-30,R-30,c*1.5,R*1.5);
}

QRectF ellipse::boundingRect() const
{
    return QRectF(-30, -30, 2*R*scale + 100, 2*R*scale + 100);
}

void ellipse::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (event->delta() < 0)
        scale -= 0.1;
    if ((event->delta() > 0))
        scale += 0.1;
    update();
}

QPointF ellipse::getCentre()
{
return boundingRect().center()+mapToScene(scenePos());
}

double ellipse::area() const
{
    return M_PI * R * scale * R * scale;
}

double ellipse::perimetr() const
{
    return 4 * (((M_PI * R * scale * scale * R) + (R * scale - R * scale)) / (R * scale + R * scale));
}
