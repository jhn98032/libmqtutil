#include <QCoreApplication>
#include <QDebug>
#include "../src/mqtutil/mqtutil.h"
#include "../src/mqtutil/ini.h"


using namespace mqtutil;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("%s\n", isInteger("-2") ? "true" : "false");

    Ini ini;
    QStringList ss;
    ss.append("hej");
    ss.append("kalle;");
    ss.append("nisse");
    ini.setStringList("ss", ss);
    ss = ini.getStringList("ss", QStringList());
    assert(ss[1] == "kalle;");

    return 0;
}


