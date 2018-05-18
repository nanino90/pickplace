#include "events.h"
#include <iostream>

events::events()
{
	std::cout<<"Init event"<<std::endl;
}

events::~events()
{
}

void events::collision()
{
	std::cout<<"slot run"<<std::endl;
}
