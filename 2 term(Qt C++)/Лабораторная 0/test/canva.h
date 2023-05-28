#ifndef CANVA_H
#define CANVA_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QResizeEvent>
extern QColor color;

class canva : public QGraphicsScene //, public QGraphicsItem
{

public:
    canva(QObject *parent = 0);
    ~canva();  

private:
    QPointF previousPoint;      // Координаты предыдущей точки

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal scale = 1;
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CANVA_H
