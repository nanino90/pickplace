#ifndef GANTRY_H
#define GANTRY_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <qmath.h>

class Gantry : public QGraphicsItem
{
	public:
		Gantry();

		QRectF boundingRect() const override;
		QPainterPath shape() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget) override;

	protected:
		//void advance(int step) override;	

	private:
		QColor color;


};


#endif
