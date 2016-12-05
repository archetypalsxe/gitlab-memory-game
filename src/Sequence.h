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
        bool checkCharacter(int);
        bool hasLivesRemaining();
        int getDifficulty();
        int getLength();
        /**
         * Get the maximum length of the word
         */
        int getMaxLength();
        /**
         * Return the sequence that should be entered by the user. Is cut to
         * the correct length
         */
        string getSequenceString();
        void died();
        /**
         * Generates the sequence that the user will have to enter
         */
        void generateSequence();
        void nextPosition();
        /**
         * Reset the position that they are typing at so that they are at
         * the beginning of the sequence
         */
        void resetTypingPosition();
        void setDifficulty(int);

    protected:
        char sequence[50];
        int difficulty = 0;
        int livesRemaining;
        int position;
        int workingPosition;
};

#endif
