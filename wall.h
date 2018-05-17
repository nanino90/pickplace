#ifndef WALL_H
#define WALL_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <qmath.h>

class Wall : public QGraphicsItem
{
	public:
		Wall(qreal width, qreal length);

		QRectF boundingRect() const override;
		QPainterPath shape() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget) override;

	protected:
		//void advance(int step) override;	

	private:
		QColor color;
		qreal width;
		qreal length;


};


#endif
