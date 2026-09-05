/*
 * Copyright (C) 2014-2016 Johan Henriksson.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */
#ifndef FILE_MQTUTIL_MQTUTIL_H
#define FILE_MQTUTIL_MQTUTIL_H

#include <QString>

#include <QCheckBox>
#include <QColor>
#include <QStringList>
#include <QPointF>

#include "mqtutil/path.h"

namespace mqtutil
{

bool isInteger(QString str);

void setCheckBoxTextColor(QCheckBox *checkBox, QColor clr);

QStringList splitString(QString str, QStringList sepList);
QStringList splitString(QString str, QChar c);

QString deltaTimeMsToStr(qint64 milliseconds);

QColor getRandomColor();
 
double lineToPointDistance(QPointF start, QPointF end, QPointF point);
double distance(QPointF p1, QPointF p2);

QPointF rotate(QPointF r, double degreesRotation);

int radToQt(double rad);

double radToDegrees(double rad);

void msleep(int t);


quint8 hexStringToU8(const char *str);

QString getMQtUtilVersion();

}; // end of namespace mqtutil


/**
 *  \defgroup MAPI libmqtutil API
*/

#endif // FILE_MQTUTIL_MQTUTIL_H





