#ifndef EVENTS_H
#define EVENTS_H

#include <QObject>

class events : public QObject
{
	Q_OBJECT
public:
	events();
	~events();

public slots:
	void collision();

};


#endif

