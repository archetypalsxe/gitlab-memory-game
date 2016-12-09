#ifndef Sequence_h
#define Sequence_h

//cout
#include <iostream>
//rand
#include <stdlib.h>
//usleep
#include <unistd.h>

using namespace std;

extern const int STARTING_LIVES;
// The maximum length of a sequence
extern const int MAX_LENGTH;

class Sequence {
    public:
        Sequence();
        /**
         * Checks to see if a provided character is the next character
         * in the sequence
         */
        bool checkCharacter(int);
        /**
         * Checks to see if the user still has lives remaining
         */
        bool hasLivesRemaining();
        /**
         * Returns the difficulty that was selected
         */
        int getDifficulty();
        /**
         * Returns the length of the sequence that the user is currently
         * working on
         */
        int getLength();
        /**
         * Returns the number of lives the user has remaining
         */
        int getLivesRemaining();
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
         * User entered the sequence incorrectly
         */
        void badAttempt();
        /**
         * Generates the sequence that the user will have to enter
         */
        void generateSequence();
        /**
         * User entered the sequence correctly
         */
        void goodAttempt();
        /**
         * Set the difficulty that the user would like to attempt
         */
        void setDifficulty(int);
        /**
         * Called when the user is ready to begin their next attempt
         */
        void startNewAttempt();

    protected:
        char sequence[50];
        int difficulty = 0;
        int livesRemaining;
        int position;
        int workingPosition = 0;

        /**
         * Generate a random integer based on the difficulty instance object
         */
        int generateRandomInt();
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
