/*
 * Copyright (C) 2014-2016 Johan Henriksson.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */
 
#include "mqtutil/mqtutil.h"

#include <QPalette>
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QThread>

#include <math.h>

#include "version.h"
#include "util.h"


namespace mqtutil
{

/**
 * @brief Checks if a string describe a integer.
 * @ingroup MAPI
 */
bool isInteger(QString str)
{
    if(str.size() == 0)
        return false;
    if(str[0] == '-')
        return true;
    if(str[0].isDigit())
        return true;
    if(str.startsWith("0x") || str.startsWith("0X"))
        return true;
    return false;
}



/**
* @brief Sets the color of a QCheckBox.
*/
void
setCheckBoxTextColor(QCheckBox * checkBox, QColor clr)
{
    QPalette p = checkBox->palette();
    p.setColor(QPalette::Active, QPalette::WindowText, clr);
    checkBox->setPalette(p);
/*
    QString sstr = QString("QCheckBox { windowtext: rgba(%1,%2,%3,255); }").arg(clr.red()).arg(clr.green()).arg(clr.blue());
    checkBox->setStyleSheet(sstr);
*/
}


/**
* @brief Splits a string into tokens.
* @param str   The string to divide.
* @param sepList   List of characters that divides the string.
*/ 
QStringList
splitString(QString str, QStringList sepList)
{
#ifdef NEVER
    QString tok;
    QStringList lst;

    if (str.isEmpty())
        return lst;

    for (int u = 0; u < str.length(); u++)
    {
        QChar c = str[u];
        bool isSplit = false;
        for (int sepIdx = 0; sepIdx < sepList.size(); sepIdx++)
        {
            if (c == sepList[sepIdx])
                isSplit = true;
        }
        if (isSplit)
        {
            lst.append(tok);
            tok.clear();
        }
        else
            tok += c;
    }
    lst.append(tok);
    return lst;
#else
    return str.split(QRegularExpression("[" + sepList.join("") + "]"));
    //return str.split(QRegExp("[" + sepList.join("") + "]"));
#endif
}

/**
* @brief Splits a string into tokens.
* @param str   The string to divide.
* @param c     The character that divides the string.
*/ 
QStringList
splitString(QString str, QChar c)
{
    return str.split(c);
}


/**
* @brief Creates a string that describes a elapsed time.
*/
QString
deltaTimeMsToStr(qint64 milliseconds)
{
    qint64 seconds = 0;
    qint64 minutes = 0;
    qint64 hours = 0;

    QString str;

    seconds = milliseconds / 1000LL;
    if (seconds > 9)
    {
        milliseconds -= seconds * 1000LL;

        minutes = seconds / 60;
        seconds -= minutes * 60;
        hours = minutes / 60;
        minutes -= hours * 60;

        if (hours > 0)
            return QString::asprintf("%dh %dm %d sec", (int) hours,
                                     (int) minutes, (int) seconds);
        if (minutes > 0)
            return QString::asprintf("%dm %d sec", (int) minutes,
                                     (int) seconds);
        return QString::asprintf("%d sec", (int) seconds);
    }
    else
        return QString::asprintf("%d msec", (int) milliseconds);
}


/**
* @brief Returns a random color.
*/
QColor
getRandomColor()
{
    quint32 r = QRandomGenerator::global ()->generate();
    quint32 g = QRandomGenerator::global ()->generate();
    quint32 b = QRandomGenerator::global ()->generate();
    QColor c = QColor(r & 0xff, g & 0xff, b & 0xff);
    return c;

}


/**
* @brief Calculates the minium distance between a line and a point.
*/
double
lineToPointDistance(QPointF start, QPointF end, QPointF point)
{
    double m_A;
    double m_B;
    double m_C;

    m_A = start.y() - end.y();
    m_B = end.x() - start.x();
    m_C = start.x() * end.y() - end.x() * start.y();


    return fabs(m_A * point.x() + m_B * point.y() + m_C) /
        sqrt(m_A * m_A + m_B * m_B);
}


/**
* @brief Calculates the minimum distance between two points.
*/
double
distance(QPointF p1, QPointF p2)
{
    double dx = p1.x() - p2.x();
    double dy = p1.y() - p2.y();
    return sqrt(dx * dx + dy * dy);
}



/**
 * @brief Rotates a point.
 * @param r             The point.
 * @param rotation      Rotation clockwise in degrees.
 */
QPointF
rotate(QPointF r, double rotation)
{
    if (rotation == 0.0)
        return r;
    while (rotation < 0.0)
        rotation += 360.0;
    if (rotation == 90.0)
        return QPointF(r.y(), -r.x());
    else if (rotation == 180.0)
        return QPointF(-r.x(), -r.y());
    else if (rotation == 270.0)
        return QPointF(-r.y(), r.x());
    QPointF rot;
    double rotationRad = degreesToRadians(rotation);

    rot.setX(r.x() * cos(rotationRad) - r.y() * sin(rotationRad));
    rot.setY(r.y() * cos(rotationRad) + r.x() * sin(rotationRad));

    return rot;
}


/**
* @brief Angles in radians to angle in Qt units.
*/ 
int radToQt(double rad)
{
    while(rad>2*M_PI)
        rad -= 2*M_PI;
        
    while(rad<0.0)
        rad += 2*M_PI;
    return (int)((rad/(2.0*M_PI))*(16.0*360.0));
}

/**
 * @brief Sleeps for a specific number of milliseconds.
 * @param t     The time to sleep in milliseconds.
 */
void msleep(int t)
{
    QObject().thread()->usleep(t*1000);
}


/**
* @brief Converts between radians and degrees.
*/
double radToDegrees (double rad)
{
    return (360.0 * rad) / (2.0*M_PI);
}



/**
*  @brief Converts a hex two byte string to a unsigned char.
*/
quint8 hexStringToU8(const char *str)
{
    quint8 d = 0;
    char c1 = str[0];
    char c2 = str[1];

    // Upper byte
    if('0' <= c1 && c1 <= '9')
        d = c1 - '0';
    else if('a' <= c1 && c1 <= 'f')
        d = 0xa + (c1 - 'a');
    else if('A' <= c1 && c1 <= 'F')
        d = 0xa + (c1 - 'A');
    else // invalid character
    {
        assert(0);
        return 0;
    }
    d = d<<4;

    // Lower byte
    if('0' <= c2 && c2 <= '9')
        d +=  c2-'0';
    else if('a' <= c2 && c2 <= 'f')
        d +=  0xa + (c2-'a');
    else if('A' <= c2 && c2 <= 'F')
        d +=  0xa + (c2-'A');
    else // invalid character?
    {
        assert(0);
        d = d>>4;
    }

    return d;
}

QString getMQtUtilVersion()
{
    return QString::asprintf("%d.%d.%d", LIB_MAJOR, LIB_MINOR, LIB_PATCH);
}


}; // end of namespace mqtutil

