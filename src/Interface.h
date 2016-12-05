#ifndef Interface_h
#define Interface_h

#include "Getch.h"
#include "Sequence.h"

#include <iostream>
//std::numeric_limits
#include <limits>


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
         * Retrieves input from the user until they complete the sequence or
         * they enter a character incorrectly. Returns whether or not they
         * entered the entirity of the sequence correctly or not
         */
        bool getEnteredSequence(Sequence);
        /**
         * Displays the main menu to the user and gets them to select what
         * difficulty they would like to play on
         */
        int getDifficulty();
        /**
         * Prompt the user for a sequence to be entered
         */
        void promptUserForSequence(string);
    protected:
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
};


#endif
