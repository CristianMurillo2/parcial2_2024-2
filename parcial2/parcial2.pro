TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        estacionservicio.cpp \
        main.cpp \
        surtidor.cpp \
        tanquecentral.cpp

HEADERS += \
    estacionservicio.h \
    surtidor.h \
    tanquecentral.h
