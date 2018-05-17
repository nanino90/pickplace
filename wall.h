#ifndef WALL_H
#define WALL_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


class Wall : public QGraphicsItem
{
	public:
		Wall();

		QRectF boundingRect() const override;
		QPainterPath shape() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget) override;

	private:
		QColor color;


};


#endif
