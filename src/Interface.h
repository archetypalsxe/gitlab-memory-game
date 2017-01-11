#ifndef Interface_h
#define Interface_h

#include "Getch.h"

#include <iostream>
//std::numeric_limits
#include <limits>
#include <stdlib.h>


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    static const bool WINDOWS = true;
#else
    static const bool WINDOWS = false;
#endif

using namespace std;

extern const int MIN_DIFFICULTY;
extern const int MAX_DIFFICULTY;

/**
 * Class for controlling interface to the user
 */
class Interface
{
    public:
        /**
         * Waits for the user to enter a character and returns it
         */
        int getCharacter();
        /**
         * Displays the main menu to the user and gets them to select what
         * difficulty they would like to play on
         */
        int getDifficulty();
        /**
         * Displays the appropriate information to the user when they
         * enter a correct sequence
         */
        void correctSequenceEntered();
        /**
         * Displays an appropriate response if the user enters an incorrect
         * sequence
         */
        void incorrectSequenceEntered(int);
        /**
         * Prompt the user for a sequence to be entered
         */
        void promptUserForSequence(string);
        /**
         * Handle an exception that was thrown
         */
        void thrownException(string);
    protected:
        /**
         * Check to see whether a provided difficulty selection is a valid
         * selection or not
         */
        bool validDifficultySelection(int);
        /**
         * Clear out anything that may still be in the buffer before the user
         * has the option to enter what they have seen
         */
        void clearKeyboardBuffer();
        /**
         * Clears the terminal
         */
        void clearWindow();
        /**
         * Display the difficulty menu to the user
         */
        void displayDifficultyMenu();
        /**
         * Displays a provided message to the user
         */
        void displayMessage(string, bool);
};


#endif
