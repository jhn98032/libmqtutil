/*
 * libmqtutil - A C++ Qt utility library
 * Copyright (C) 2026 Johan Henriksson johan[a]dexar.se
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

/**

@mainpage libmqtutil

libmqtutil is a utility library for C/C++ programs.

@ref mqtutil "List of functions and classes"

The API is contained in these files:
 
 - detectdistro.h
 - mqtutil.h
 - path.h
 - ini.h
 - log.h

@section sec_usage Example usage

Include files needed are "mqtutil/mqtutil.h".
All code is placed in the "mqtutil" namespace.
Example:
@code
  #include <mqtutil/mqtutil.h>
  using namespace mqtutil;
  void main()
  {
    DistroType distro;
    QString name;
    detectDistro (&distro, &name);
    printf("You are running on '%s'\n", qPrintable(name));
  } 
@endcode
*/
