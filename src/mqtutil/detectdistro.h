#ifndef FILE_MQTUTIL_DETECTDISTRO_H
#define FILE_MQTUTIL_DETECTDISTRO_H

#include <QString>

namespace mqtutil
{

typedef enum{ DISTRO_DEBIAN, DISTRO_UBUNTU, DISTRO_UNKNOWN} DistroType;
void detectDistro(DistroType *type, QString *distroDesc);

}; // end of namespace mqtutil


#endif // FILE__DETECTDISTRO_H
