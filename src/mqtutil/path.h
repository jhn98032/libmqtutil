#ifndef FILE_MQTUTIL_PATH_H
#define FILE_MQTUTIL_PATH_H

#include <QString>

namespace mqtutil
{

QString getFileTitle(QString filename);
QString getFilenamePart(QString fullPath);
void dividePath(QString fullPath, QString *filename, QString *folderPath);
QString getExtensionPart(QString filename);

QString simplifyPath(QString path);

void seperatePath(QString fullPath, QString *dir, QString *filename);
void seperatePath(QString fullPath, QString *dir,QString *title, QString *ext);
void seperateFilename(QString filename,QString *title, QString *ext);

};


#endif // FILE_MQTUTIL_PATH_H

