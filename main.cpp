#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>

#include "events.h"
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

	Gantry* gantry = new Gantry();
	gantry->setPos(scene.height()/2,scene.width()/2);	
	scene.addItem(gantry);

	QGraphicsView view(&scene);
	view.setRenderHint(QPainter::Antialiasing);
	view.setBackgroundBrush(Qt::gray);
	view.setCacheMode(QGraphicsView::CacheBackground);
	view.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	view.setWindowTitle("PickPlace");
	view.show();

	events evt;

	QTimer timer;
	QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	QObject::connect(&timer, SIGNAL(timeout()), &evt, SLOT(collision()));
	//QObject::connect(&reader, SIGNAL(setDestination()), &gantry, SLOT(getDestination()));
	timer.start(100);

	app.exec();
	std::cout<<"heee"<<std::endl;
	return 0;
}
