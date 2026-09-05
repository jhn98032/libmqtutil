/*
 * libmqtutil - A C++ Qt utility library
 * Copyright (C) 2026 Johan Henriksson johan[a]dexar.se
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

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


