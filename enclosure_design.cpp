#include "enclosure_design.h"


const qreal width =10;

void enclosureDesign(QGraphicsScene &scene,qreal size)
{
	//Paint 4 wall around the workign area
	Wall* wall1= new Wall(width,size);
	wall1->setPos(0,0);
	scene.addItem(wall1);

	Wall* wall2= new Wall(size,width);
	wall2->setPos(0+width,0);
	scene.addItem(wall2);

	Wall* wall3= new Wall(width,size);
	wall3->setPos(0+width+size,0);
	scene.addItem(wall3);
	
	Wall* wall4= new Wall(size,width);
	wall4->setPos(0+width,0+size-width);
	scene.addItem(wall4);
}
