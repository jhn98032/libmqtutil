QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/../src\'"


TEMPLATE = app
CONFIG += console c++11
QT += core
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += test.cpp

# Include the librarys headers
INCLUDEPATH += ../src/

LIB_PATH = $$absolute_path($$_PRO_FILE_PWD_/../src)


# Link against the shared library
LIBS += -L$$LIB_PATH -lmqtutil
#LIBS += ../src/libmqtutil.a


