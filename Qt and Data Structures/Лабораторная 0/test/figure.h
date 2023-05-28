#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
extern int count;

class figure : public QObject, public QGraphicsItem
{
public:
    explicit figure(QObject *parent = 0);
    ~figure();
    void rotate_right(double arg);
    void rotate_left(double arg);
    void newScale(qreal addd);

    virtual double area() const = 0;
    virtual double perimetr() const = 0;


    virtual QPointF getCentre() = 0;


    QPointF centre;
signals:

protected:
    qreal scale=1;
    int angular=0;
private:
    double x,y;
    QRectF boundingRect() const;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
        delete this;
        count--;
        Q_UNUSED(event);
    }
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
};

#endif // FIGURE_H
