/*
 * libmqtutil - A C++ Qt utility library
 * Copyright (C) 2026 Johan Henriksson johan[a]dexar.se
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef FILE_MQTUTIL_DETECTDISTRO_H
#define FILE_MQTUTIL_DETECTDISTRO_H

#include <QString>

namespace mqtutil
{

typedef enum{ DISTRO_DEBIAN, DISTRO_UBUNTU, DISTRO_UNKNOWN} DistroType;
void detectDistro(DistroType *type, QString *distroDesc);

}; // end of namespace mqtutil


#endif // FILE__DETECTDISTRO_H
