#include "gantry.h"
#include <iostream>

qreal width	=40;
qreal length	=40;

Gantry::Gantry(qreal x, qreal y) :
	color(Qt::yellow)
{
	setPos(x,y);	
	destination.setX(x);
	destination.setY(y);
}

QRectF Gantry::boundingRect() const
{
	return QRectF(0,0,width,length);
}

QPainterPath Gantry::shape() const
{
	QPainterPath path;
	path.addRect(0,0,width,length);
	return path;
}

void Gantry::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
		QWidget* widget)
{
	(void)option;
	(void)widget;

	if(scene()->collidingItems(this).isEmpty())
	painter->setBrush(color);
else	
{
	//emit tamper();	
	painter->setBrush(Qt::black);
	}
	painter->drawRect(0,0,width,length);

} 

void Gantry::advance(int step)
{
	(void) step;
	QPoint actual(x(),y());

	if(actual==destination)
{
		return;
}

	if(actual.x()>destination.x())
		actual.rx()--;
	if(actual.y()>destination.y())
		actual.ry()--;
		actual.ry()--;
	if(actual.x()<destination.x())
	      actual.rx()++;
	if(actual.y()<destination.y())
		actual.ry()++;

	setTransformOriginPoint(0,0);
	setPos(actual);
}

void Gantry::putDestination(qreal x, qreal y)
{
	destination.setX(x);
	destination.setY(y);
}

