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
