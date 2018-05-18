
#include <QObject>
#include <QtWidgets>
#include <math.h>
#include <stdio.h>
#include <iostream>



class Reader: public QThread
{
public:
    void run() override;
};
