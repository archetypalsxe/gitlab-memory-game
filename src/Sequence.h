#ifndef Sequence_h
#define Sequence_h

//cout
#include <iostream>
//rand
#include <stdlib.h>

using namespace std;

// The maximum length of a sequence
extern const int MAX_LENGTH;

class Sequence {
    public:
        /**
         * Constructor. Takes in a required difficulty parameter
         */
        Sequence(int);
        /**
         * Checks to see if a provided character is the next character
         * in the sequence
         */
        bool checkCharacter(int);
        /**
         * Returns the length of the sequence that the user is currently
         * working on
         */
        int getLength();
        /**
         * Returns the maximum length of the word
         */
        int getMaxLength();
        /**
         * Return the sequence that should be entered by the user. Is cut to
         * the correct length
         */
        string getSequenceString();
        /**
         * User entered the sequence correctly
         */
        void goodAttempt();
        /**
         * Called when the user is ready to begin their next attempt
         */
        void startNewAttempt();

    protected:
        char sequence[50];
        int position = 0;
        int workingPosition = 0;

        /**
         * Generate a random integer based on the difficulty instance object
         */
        int generateRandomInt(int);
        /**
         * Convert the randomly generated integer into an ASCII value for
         * use throughout the program
         */
        int getAsciiValue(int);
        /**
         * Generates the sequence that the user will have to enter
         */
        void generateSequence(int);
        /**
         * Advances the sequence to the next position (makes the sequence
         * once character bigger)
         */
        void nextPosition();
        /**
         * Reset the position that they are typing at so that they are at
         * the beginning of the sequence
         */
        void resetTypingPosition();
};

#endif
