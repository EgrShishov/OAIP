#include "truck.h"

Truck::Truck()
{

}

void Truck::kuzov_on()
{
    was=true;

}

void Truck::kuzov_off()
{
    was=false;
}

void Truck::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   Q_UNUSED(option);Q_UNUSED(widget);

    this->Rectangle::paint(painter,option,widget);

    if(was)
    {

        //painter->translate(150,150);
        painter->rotate(-45);
        painter->drawRect(-1,233,100,50);

    } else {
        painter->drawRect(200,150,100,50);
    }


}
