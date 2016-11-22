#ifndef Interface_h
#define Interface_h

#include "Getch.h"
#include <iostream>


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    static const bool WINDOWS = true;
#else
    static const bool WINDOWS = false;
#endif

using namespace std;

/**
 * Class for controlling interface to the user
 */
class Interface
{
    public:
        void test();
};


#endif
