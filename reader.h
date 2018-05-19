
#include <QObject>
#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>



class Reader: public QThread
{
public:

	Reader(QObject* event);

    void run() override;

private:
	QObject* evt;
};
