#include "manager.h"
#include <iostream>
Manager::Manager()
{
	system("clear");
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


	std::cout<<"0.Close program"<<std::endl;
	std::cout<<". . . . . . . . . . . . . . ."<<std::endl;

	int selection;
	std::cin>>selection;

	switch(selection)
	{
		case 0:
			std::exit;
			break;
		case 1:
			emit setDestination(20,35);
			loadFile();
			break;
		case 2:
			emit setDestination(20,35);
			break;
		default:
			break;

	}
	system("clear");

}
