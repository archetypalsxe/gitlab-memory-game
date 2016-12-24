#ifndef Controller_h
#define Controller_h

#include "Interface.h"
#include "Sequence.h"
#include "User.h"
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
         * The user of the game
         */
        User user;

        /**
         * Have the user attempt to enter the sequence. Returns whether or
         * not the entire sequence was entered successfully or not
         */
        bool getSequenceAttempt();
        /**
         * The main loop where we display everything to the user and get
         * them to input everything they can remember
         */
        void mainLoop();
        /**
         * Processes the entered sequence and initiates the appropriate response
         */
        void processEnteredSequence(bool);
};


#endif
