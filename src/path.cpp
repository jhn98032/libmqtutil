/*
 * libmqtutil - A C++ Qt utility library
 * Copyright (C) 2026 Johan Henriksson johan[a]dexar.se
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#include "mqtutil/path.h"


#include <assert.h>
#include <QString>
#include <QFile>
#include <QProcess>
#include <QMap>

namespace mqtutil
{
    
/**
 * @brief Returns the filetitle of a file.
 * @param filename     The filename (Ex: "/a_path/test.bmp").
 * @return the filetitle  (Eg: "test")
 */
QString
getFileTitle(QString filename)
{
    filename = getFilenamePart(filename);
    int lastPos = filename.lastIndexOf('.');
    if (lastPos == -1)
        return filename;
    else
        return filename.left(lastPos);
}

/**
 * @brief Divides a path into a filename and a path.
 *
 * Example: dividePath("/dir/filename.ext") => "/dir", "filename.ext".
 */
void
dividePath(QString fullPath, QString * filename, QString * folderPath)
{
    int divPos = fullPath.lastIndexOf('/');
    if (divPos > 0)
    {
        if (filename)
            *filename = fullPath.mid(divPos + 1);
        if (folderPath)
            *folderPath = fullPath.left(divPos);
    }
    else
    {
        if (filename)
            *filename = fullPath;
    }
}


/**
* @brief Divides a path into its components
* @param fullPath   The full path (Eg: "/a/dir/file.ext")
* @param dir        Will be set to the dir (Eg: "/a/dir")
* @param title      Will be set to the title (Eg: "file")
* @param ext        Will be set to the ext (Eg: "ext")
*/
void seperatePath(QString fullPath, QString *dir,QString *title, QString *ext)
{
    QString foundExt;
    QString foundTitle;
    QString foundDir;
    
    // Extract the extension
    int extPos = fullPath.lastIndexOf('.');
    if(extPos != -1)
    {
        foundExt = fullPath.mid(extPos+1);
        fullPath = fullPath.left(extPos-1);
    }

    // Extract the dir
    int lastDirSep = fullPath.lastIndexOf('/');
    if(lastDirSep == -1)
        lastDirSep = fullPath.lastIndexOf('\\');
    if(lastDirSep != -1)
    {
        foundDir = fullPath.left(lastDirSep);
        foundTitle = fullPath.mid(lastDirSep+1);
    }
    else
    {
        foundTitle = fullPath;
    }

    // No title but a extension?
    if(foundTitle.isEmpty())
    {
        foundTitle = foundExt;
        foundExt = "";
    }
    
    if(dir)
        *dir = foundDir;
    if(ext)
        *ext = foundExt;
    if(title)
        *title = foundTitle;
}

/**
 * @brief Returns the filename of a path.
 *
 * Example: getFilenamePart("/dir/filename.ext") => "filename.ext".
 */
QString
getFilenamePart(QString fullPath)
{
    QString filename;
    mqtutil::dividePath(fullPath, &filename, NULL);
    return filename;
}


/**
 * @brief Returns the extension of a file.
 * @return The extension excluding the dot (Eg: "txt").
 */
QString
getExtensionPart(QString filename)
{
    int idx = filename.lastIndexOf('.');
    if (idx == -1)
        return QString("");
    return filename.mid(idx + 1);
}


static QString
priv_simplifySubPath(QString path)
{
    QString out;

    if (path.startsWith('/'))
        return simplifyPath(path.mid(1));
    if (path.startsWith("./"))
        return simplifyPath(path.mid(2));

    QString first;
    QString rest;

    int piv = path.indexOf('/');
    if (piv == -1)
        return path;
    else
    {
        first = path.left(piv);
        rest = path.mid(piv + 1);
        rest = priv_simplifySubPath(rest);
        if (rest.isEmpty())
            path = first;
        else
            path = first + "/" + rest;
    }
    return path;
}


/**
 * @brief Simplifies a path by removing unnecessary seperators.
 *
 * Eg: simplifyPath("./a///path/") => "./a/path".
 */
QString
simplifyPath(QString path)
{
    QString out;
    if (path.startsWith("./"))
        out = "./" + priv_simplifySubPath(path.mid(2));
    else if (path.startsWith('/'))
        out = '/' + priv_simplifySubPath(path.mid(1));
    else
        out = priv_simplifySubPath(path);
    return out;
}



/**
* @brief Divides a path into its components
* @param fullPath   The full path (Eg: "/a/dir/file.ext")
* @param dir        Will be set to the dir (Eg: "/a/dir")
* @param filename      Will be set to the title (Eg: "file.ext")
*/
void seperatePath(QString fullPath, QString *dir, QString *filename)
{
    QString foundFilename;
    QString foundDir;
    


    // Extract the dir
    int lastDirSep = fullPath.lastIndexOf('/');
    if(lastDirSep == -1)
        lastDirSep = fullPath.lastIndexOf('\\');
    if(lastDirSep != -1)
    {
        foundDir = fullPath.left(lastDirSep);
        foundFilename = fullPath.mid(lastDirSep+1);
    }
    else
    {
        foundFilename = fullPath;
    }

    if(dir)
        *dir = foundDir;
    if(filename)
        *filename = foundFilename;
}

/**
* @brief Divides a filename into its components
* @param filename   The filename (Eg: "example.ext")
* @param title      Will be set to the title (Eg: "file")
* @param ext        Will be set to the ext (Eg: "ext")
*/
void seperateFilename(QString filename,QString *title, QString *ext)
{
    QString foundExt;
    QString foundTitle;
    
    // Extract the extension
    int extPos = filename.lastIndexOf('.');
    if(extPos != -1)
    {
        foundExt = filename.mid(extPos+1);
        foundTitle = filename.left(extPos-1);
    }

    
    // No filename but a extension?
    if(foundTitle.isEmpty())
    {
        foundTitle = foundExt;
        foundExt = "";
    }
    
    if(ext)
        *ext = foundExt;
    if(title)
        *title = foundTitle;
}




}; // end of namespace mqtutil




