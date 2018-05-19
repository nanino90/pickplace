#ifndef MANAGER_H
#define MANAGER_H

#include <QFile>
#include <QObject>
#include <QTextStream>

class Manager : public QObject
{
	Q_OBJECT
	
	public:
		Manager();
		~Manager();

		void loadFile();
		void printMenu();

	private:
		QString placement;
		bool fileOpen;		

	public slots:

	signals:
		void setDestination(qreal x, qreal y);

};


#endif
