#ifndef Controller_h
#define Controller_h

#include "Interface.h"

using namespace std;

/**
 * The class that controls and orchestrates the game
 */
class Controller
{
    public:
        /**
         * Initiates the game
         */
        void start();
    protected:
        /**
         * Object for controlling the interface to the user
         */
        Interface interface;
};


#endif
