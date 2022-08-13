QT       += quick location

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#cc++2a
CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    communicator/etcpserver.cpp \
    controller/econtroller.cpp \
    controller/emapcontroller.cpp \
    controller/eradarcontroller.cpp \
    gui/item/eabstractitem.cpp \
    gui/item/eplotitem.cpp \
    gui/item/eradaritem.cpp \
    gui/model/eplotmodel.cpp \
    gui/model/eradarmodel.cpp \
    main.cpp

HEADERS += \
    communicator/etcpserver.h \
    controller/econtroller.h \
    controller/emapcontroller.h \
    controller/eradarcontroller.h \
    gui/item/eabstractitem.h \
    gui/item/eplotitem.h \
    gui/item/eradaritem.h \
    gui/model/eplotmodel.h \
    gui/model/eradarmodel.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc
