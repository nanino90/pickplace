#include <QtWidgets>
#include <QObject>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "reader.h" 

#include "events.h"


Reader::Reader(Manager* event):
	evt(event)
{
}

void Reader::run() 
{
	evt->printMenu();
}

