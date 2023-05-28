#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class Rectangle : public QGraphicsItem
{
public:
    Rectangle();
    ~Rectangle();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
