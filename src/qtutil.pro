include(../version.pri)
include(../makefile.local)

TEMPLATE = lib
CONFIG += staticlib
#CONFIG += shared
QT += core
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = mqtutil

VERSION_PARTS = $$VERSION_MAJOR $$VERSION_MINOR $$VERSION_PATCH
VERSION = $$join(VERSION_PARTS, .)

message("Version $$VERSION")

headers.files=mqtutil.h
headers.path=../dist/include/mqtutil

target.files=*.so.*
target.path=../dist/lib

INSTALLS += target headers


SOURCES+=mqtutil.cpp
HEADERS+=mqtutil/mqtutil.h
SOURCES+=path.cpp
HEADERS+=mqtutil/path.h
SOURCES+=detectdistro.cpp
HEADERS+=mqtutil/detectdistro.h
SOURCES+=ini.cpp
HEADERS+=mqtutil/ini.h



SOURCES+=log.cpp
HEADERS+=mqtutil/log.h

CONFIG += warn_on
CONFIG += debug


