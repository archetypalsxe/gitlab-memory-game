#ifndef Controller_h
#define Controller_h

#include "Interface.h"
#include "Sequence.h"
#include <stdlib.h>

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
        /**
         * The sequence object that will be used throughout the game
         */
        Sequence sequence;

        /**
         *
         */
        void clearKeyBoardBuffer();
        /**
         * The main loop where we display everything to the user and get
         * them to input everything they can remember
         */
        void mainLoop();
        /**
         * Processes the entered sequence and initiates the appropriate response
         */
        void processEnteredSequence(bool, Sequence*);
};


#endif
