#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "events.h"
#include "gantry.h"
#include "reader.h"
#include "menu.h"
#include "manager.h"
#include "enclosure_design.h"

int main (int argc, char** argv)
{
	QApplication app(argc, argv);

	QGraphicsScene scene;
	scene.setSceneRect(0,0,500,500);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);

	enclosureDesign(scene,450);

	Gantry* gantry = new Gantry(scene.height()/2,scene.width()/2);
	scene.addItem(gantry);

	Manager* manager = new Manager();
	Reader reader(manager);
	reader.start();

	QGraphicsView view(&scene);
	view.setRenderHint(QPainter::Antialiasing);
	view.setBackgroundBrush(Qt::gray);
	view.setCacheMode(QGraphicsView::CacheBackground);
	view.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	view.setWindowTitle("PickPlace");
	view.show();


	QTimer timer;
	QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	QObject::connect(manager, SIGNAL(setDestination(qreal, qreal)), gantry, SLOT(putDestination(qreal, qreal)));
	timer.start(100);

	app.exec();
	std::cout<<"Application Finished"<<std::endl;
	return 0;
}
