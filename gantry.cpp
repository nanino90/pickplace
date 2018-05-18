#include "gantry.h"

qreal width	=40;
qreal length	=40;

Gantry::Gantry() :
	color(Qt::yellow),
	destination(40,40)
{

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

	painter->setBrush(color);
	painter->drawRect(0,0,width,length);

} 

void Gantry::advance(int step)
{
	(void) step;
	QPoint actual(x(),y());

	if(actual.x()>destination.x())
		actual.rx()--;
	if(actual.y()>destination.y())
		actual.ry()--;
	if(actual.x()<destination.x())
		actual.rx()++;
	if(actual.y()<destination.y())
		actual.ry()++;

	setTransformOriginPoint(0,0);
	setPos(actual);
}

