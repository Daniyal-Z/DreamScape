QT       += core gui
QT       += multimedia
QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UserPass.cpp \
    artist.cpp \
    artistlogin.cpp \
    artistwindow.cpp \
    forgotpassword.cpp \
    initialwindow.cpp \
    listener.cpp \
    main.cpp \
    login.cpp \
    mainscreen.cpp \
    newplaylist.cpp \
    playlist.cpp \
    sign_up.cpp \
    song.cpp \
    user.cpp

HEADERS += \
    UserPass.h \
    artist.h \
    artistlogin.h \
    artistwindow.h \
    forgotpassword.h \
    initialwindow.h \
    listener.h \
    login.h \
    mainscreen.h \
    newplaylist.h \
    playlist.h \
    sign_up.h \
    song.h \
    user.h

FORMS += \
    artistlogin.ui \
    artistwindow.ui \
    forgotpassword.ui \
    initialwindow.ui \
    login.ui \
    mainscreen.ui \
    newplaylist.ui \
    sign_up.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES += \
    Images/icon3.png \
    Images/icon3_1.png \
    Images/icon7.png \
    Images/icon8.png
