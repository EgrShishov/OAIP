#include "canva.h"
#include <QPainter>
canva::canva(QObject *parent) : QGraphicsScene(parent) //, QGraphicsItem()
{

}

canva::~canva()
{

}


void canva::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void canva::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               5*scale,
               5*scale,
               QPen(Qt::NoPen),
               QBrush(color));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();

}

void canva::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(color,5*scale,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
}
