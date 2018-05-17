#include "wall.h"

Wall::Wall(qreal width, qreal length) :
	color(Qt::blue),
	width(width),
	length(length)	
{

}

QRectF Wall::boundingRect() const
{
	return QRectF(0,0,width,length);
}

QPainterPath Wall::shape() const
{
	QPainterPath path;
	path.addRect(0,0,width,length);
	return path;
}

void Wall::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget)
{
(void)option;
(void)widget;

painter->setBrush(color);
painter->drawRect(0,0,width,length);

} 

//void Wall::advance(int step)
//{
//	(void) step;
//}
