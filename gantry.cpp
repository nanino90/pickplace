#include "gantry.h"

qreal width	=40;
qreal length	=40;

Gantry::Gantry() :
	color(Qt::yellow)
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
	setTransformOriginPoint(0,0);
	setPos(mapToParent(1,0));
}
