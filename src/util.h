/*
 * libmqtutil - A C++ Qt utility library
 * Copyright (C) 2026 Johan Henriksson johan[a]dexar.se
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef FILE__UTIL_H
#define FILE__UTIL_H

#include <math.h>

inline double degreesToRadians(double degrees) {
    return degrees/(180.0 / M_PI);
}
inline double radiansToDegrees(double radians) {
    return radians * (180.0 / M_PI);
}



#endif // FILE__UTIL_H
