#include "colordraw.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

ColorDraw::ColorDraw(QWidget *parent) : QWidget(parent)
{

}

void ColorDraw::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);
        QBrush brush;
        QPen pen;

        brush.setColor(QColor(r,g,b));
        brush.setStyle(Qt::SolidPattern);
        //Caneta preta
        pen.setColor(QColor(0,0,0));
        pen.setWidth(2);


        painter.setBrush(brush);
        painter.setPen(pen);

        painter.drawRect(0,0,width(),height());

}

void ColorDraw::set_r(int _r)
{
    r = _r;
    repaint();
}

void ColorDraw::set_g(int _g)
{
    g = _g;
    repaint();
}

void ColorDraw::set_b(int _b)
{
    b = _b;
    repaint();
}

