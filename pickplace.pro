
QT += \
	widgets	\
	core

CONFIG += c++11

TEMPLATE = app

HEADERS += \
	gantry.h \
	wall.h \
	events.h \
	reader.h \
	manager.h \
	enclosure_design.h

SOURCES += \
	main.cpp \
	gantry.cpp \
	wall.cpp \
	events.cpp \
	reader.cpp \
	manager.cpp \
	enclosure_design.cpp

TARGET = pickplace.run

