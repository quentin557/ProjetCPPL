TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14
                  -pedantic-errors

SOURCES += main.cpp \
    player.cpp \
    board.cpp \
    square.cpp \
    consolequoridor.cpp \
    quoridor.cpp \
    wall.cpp \
    playablesquare.cpp \
    obersverpattern.cpp

HEADERS += \
    player.h \
    board.h \
    square.h \
    consolequoridor.h \
    quoridor.h \
    wall.h \
    playablesquare.h \
    obersverpattern.h

