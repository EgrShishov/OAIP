#include "figure.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

figure::figure(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

figure::~figure()
{

}

QRectF figure::boundingRect() const
{
    return QRectF(-30,-30,200,200);
}

void figure::rotate_left(double arg)
{
    angular-=3;
    this->setRotation(angular);
}

void figure::rotate_right(double arg)
{
    angular+=3;
    this->setRotation(angular);
}

void figure::newScale(qreal addd)
{
    this->setScale(addd);
    scale=addd;
}
