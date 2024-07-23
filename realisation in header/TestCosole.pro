QT -= gui
QT += xml network widgets


CONFIG += c++11 console
CONFIG -= app_bundle


SOURCES += \
        main.cpp \
        unit2.cpp

HEADERS += \
	HeaderWithRealisation.h \
	unit2.h

INCLUDEPATH += ../include


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


