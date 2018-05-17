#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "gantry.h"
#include "wall.h"
#include "reader.h"

int main (int argc, char** argv)
{
	QApplication app(argc, argv);

	QGraphicsScene scene;
	scene.setSceneRect(0,0,500,500);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	Reader reader;
	reader.start();

	Wall* wall= new Wall();
	wall->setPos(250,250);

	scene.addItem(wall);

	QGraphicsView view(&scene);
	view.setRenderHint(QPainter::Antialiasing);
	view.setBackgroundBrush(Qt::gray);
	view.setCacheMode(QGraphicsView::CacheBackground);
	view.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	view.setWindowTitle("PickPlace");
	view.show();

	app.exec();
	std::cout<<"heee"<<std::endl;
return 0;
}
