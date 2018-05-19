
#include <QObject>
#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>

#include "manager.h"



class Reader: public QThread
{
	public:

		Reader(Manager* event);

		void run() override;

	private:
		Manager* evt;
};
