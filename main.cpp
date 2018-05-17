#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "gantry.h"
#include "reader.h"
#include "enclosure_design.h"

int main (int argc, char** argv)
{
	QApplication app(argc, argv);

	QGraphicsScene scene;
	scene.setSceneRect(0,0,500,500);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	Reader reader;
	reader.start();

	enclosureDesign(scene,450);

	QGraphicsView view(&scene);
	view.setRenderHint(QPainter::Antialiasing);
	view.setBackgroundBrush(Qt::gray);
	view.setCacheMode(QGraphicsView::CacheBackground);
	view.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	view.setWindowTitle("PickPlace");
	view.show();

	QTimer timer;
	QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	timer.start(100);

	app.exec();
	std::cout<<"heee"<<std::endl;
return 0;
}
