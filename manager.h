#ifndef MANAGER_H
#define MANAGER_H

#include <QFile>
#include <QObject>

class Manager : public QObject
{
	Q_OBJECT
	
	public:
		Manager();
		~Manager();

		void loadFile(QString filename);

	private:
		QFile file;

};


#endif
