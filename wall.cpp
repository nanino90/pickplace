#include "wall.h"



Wall::Wall() :
	color(Qt::red)
{


}

QRectF Wall::boundingRect() const
{
	qreal extra;
	return QRectF(0,0,20,20);
}

QPainterPath Wall::shape() const
{
	QPainterPath path;
	path.addRect(0,0,20,20);
	return path;
}

void Wall::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget)
{
painter->setBrush(color);
painter->drawRect(0,0,20,20);

} 
