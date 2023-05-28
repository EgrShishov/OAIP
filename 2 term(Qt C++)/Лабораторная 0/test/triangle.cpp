#include "triangle.h"
#include <QMessageBox>

triangle::triangle()
{
a=40,b=40,c=40;
}

triangle::~triangle()
{

}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(1);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(QBrush(QColor(255,224,224)));
    QPolygonF polygon;

//    polygon << this->setPointA();
//    qDebug()<<A;
//    polygon << this->setPointB();
//    polygon << this->setPointC();
//    polygon << this->A;

    polygon << QPoint(300, 175) << QPoint(300 - 30, 175 - 40) << QPoint(300 + 30, 175 - 40);

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawPolygon(polygon);
    //painter->drawPoint(boundingRect().center());
}

QRectF triangle::boundingRect() const
{
    double size=a>b? a : b;
    size=size>c?size:c;
    return QRectF(-40, -40, 500, 500);
}

void triangle::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (event->delta() < 0)
        scale -= 0.1;
    if ((event->delta() > 0))
        scale += 0.1;
    update();
}

QPointF triangle::getCentre()
{
return boundingRect().center()+mapToScene(scenePos());
}

double triangle::area() const
{
    double p = (a + b + c)/2 * scale;
    double ans=sqrtl(p*(p-a)*(p-b)*(p-c)*scale);

    return ans;
}

double triangle::perimetr() const
{
    return scale*(a+b+c);
}

QPointF triangle::setPointA()
{
    A=QCursor::pos();
    qDebug()<<A<<"\n";
    return A;
}

QPointF triangle::setPointB()
{
    B=QCursor::pos();
    qDebug()<<B<<"\n";
    return B;
}

QPointF triangle::setPointC()
{
    C=QCursor::pos();
    qDebug()<<C<<"\n";
    return C;
}
