#ifndef GANTRY_H
#define GANTRY_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsObject>
#include <qmath.h>

class Gantry : public QGraphicsObject
{
	Q_OBJECT

	public:
		Gantry(qreal x, qreal y);

		QRectF boundingRect() const override;
		QPainterPath shape() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget) override;
	public slots:
		void setDestination(int x, int  y);

	protected:
		void advance(int step) override;	
	signals:
		void tamper(void);

	private:
		QColor color;
		QPoint destination;
};


#endif
