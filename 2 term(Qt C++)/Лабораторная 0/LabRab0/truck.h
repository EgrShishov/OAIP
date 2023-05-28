#ifndef TRUCK_H
#define TRUCK_H
#include "Rectangle.h"
#include <QGraphicsItem>
#include <QPainter>

class Truck: public Rectangle
{

  bool was=false;

public:
  Truck();

  void kuzov_on();
  void kuzov_off();

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TRUCK_H
