==========
libmqtutil
==========

A C++ Qt utility library with BSD license.

Build and install
-----------------

doxygen is needed for building:

.. code-block:: bash

    sudo apt install doxygen


Run:

.. code-block:: bash

    ./configure

Followed by:

.. code-block:: bash
    make
    make install


Usage instructions
------------------

To use add the following to the pro file:

  QMAKE_CXXFLAGS+=`libmqtutil-config --cflags`
  LIBS+=`libmqtutil-config --ldflags`


Author
------

Written by Johan Henriksson (johan@dexar.se)

Dependencies
-------------
None

