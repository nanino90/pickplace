#include "manager.h"
#include <iostream>

void clr ()
{
	int val=system("clear");
	(void)val;
	return;
}

Manager::Manager()
{
clr();	
	std::cout<<"Welcome to QPick&Place"<<std::endl;
	std::cout<<std::endl;

}

Manager::~Manager()
{
}

void Manager::loadFile()
{
	QFile file("./placement");
	if (!file.open(QIODevice::ReadOnly))
		return;

	QTextStream out(&file);
	placement=out.readAll();

}


void Manager::printMenu()
{
	if(!fileOpen)
	{
		std::cout<<"1.Load file"<<std::endl;
	}
	else
	{
		std::cout<<"2.Start program"<<std::endl;

	}


	std::cout<<"3.Go to"<<std::endl;
	std::cout<<"0.Close program"<<std::endl;
	std::cout<<". . . . . . . . . . . . . . ."<<std::endl;

	for(QString i : messages)
	std::cout<<i.toStdString()<<std::endl;
	

	int selection;
	std::cin>>selection;

	switch(selection)
	{
		case 0:
			exit(0);
			break;
		case 1:
			emit setDestination(2000,350);
			loadFile();
			break;
		case 2:
			emit setDestination(20,35);
			break;
		case 3:
			emit setDestination(200,200);
			break;
		default:
			break;

	}
	clr();	
}

void Manager::collision()
{
	QString collision_message("Collision!");
	messages.push_back(collision_message);		
	clr();	
	printMenu();	
}
