#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>

#include "events.h"
#include "gantry.h"
#include "reader.h"
#include "manager.h"
#include "enclosure_design.h"

int main (int argc, char** argv)
{
	QApplication app(argc, argv);

	QGraphicsScene scene;
	scene.setSceneRect(0,0,500,500);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	events evt;
	Reader reader(&evt);
	reader.start();

	enclosureDesign(scene,450);

	Gantry* gantry = new Gantry(scene.height()/2,scene.width()/2);
	scene.addItem(gantry);

	Manager* manager = new Manager();

	QGraphicsView view(&scene);
	view.setRenderHint(QPainter::Antialiasing);
	view.setBackgroundBrush(Qt::gray);
	view.setCacheMode(QGraphicsView::CacheBackground);
	view.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	view.setWindowTitle("PickPlace");
	view.show();


	QTimer timer;
	QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	//QObject::connect(gantry, SIGNAL(tamper()), gantry, SLOT(setDestination(40,40)));
	//QObject::connect(gantry, SIGNAL(tamper()), &evt, SLOT(collision()));
	//QObject::connect(&reader, SIGNAL(setDestination()), &gantry, SLOT(getDestination()));
	timer.start(100);

	QTimer t;
	QObject::connect(&t,SIGNAL(timeout()), gantry, SLOT(setDestination(int,int)));
	t.start(2000);
	app.exec();
	std::cout<<"Application Finished"<<std::endl;
	return 0;
}
