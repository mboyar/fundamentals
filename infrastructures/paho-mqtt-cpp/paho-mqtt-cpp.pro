TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#Qt4
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp

unix:!macx: LIBS += -L/tmp/paho-workspace/paho.mqtt.cpp/.libs/ -lpaho-mqttpp3

INCLUDEPATH += /tmp/paho-workspace/paho.mqtt.cpp/src/
DEPENDPATH += /tmp/paho-workspace/paho.mqtt.cpp/src/


unix:!macx: LIBS += -L/tmp/paho-workspace/paho.mqtt.c/build/output/ -lpaho-mqtt3a

INCLUDEPATH += /tmp/paho-workspace/paho.mqtt.c/src
DEPENDPATH += /tmp/paho-workspace/paho.mqtt.c/src

unix:!macx: LIBS += -L/tmp/paho-workspace/paho.mqtt.c/build/output/ -lpaho-mqtt3as

INCLUDEPATH += /tmp/paho-workspace/paho.mqtt.c/src
DEPENDPATH += /tmp/paho-workspace/paho.mqtt.c/src

unix:!macx: LIBS += -L/tmp/paho-workspace/paho.mqtt.c/build/output/ -lpaho-mqtt3c

INCLUDEPATH += /tmp/paho-workspace/paho.mqtt.c/src
DEPENDPATH += /tmp/paho-workspace/paho.mqtt.c/src

unix:!macx: LIBS += -L/tmp/paho-workspace/paho.mqtt.c/build/output/ -lpaho-mqtt3cs

INCLUDEPATH += /tmp/paho-workspace/paho.mqtt.c/src
DEPENDPATH += /tmp/paho-workspace/paho.mqtt.c/src
