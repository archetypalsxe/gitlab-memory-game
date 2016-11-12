#ifndef Sequence_h
#define Sequence_h

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const bool WINDOWS = true;
#else
static const bool WINDOWS = false;
#endif

//cout
#include <iostream>
//rand
#include <stdlib.h>
//usleep
#include <unistd.h>

using namespace std;

class Sequence {
    public:
        Sequence();
        bool checkCharacter(int);
        bool hasLivesRemaining();
        int getDifficulty();
        int getLength();
        void died();
        void displaySequence();
        void generateSequence();
        void nextPosition();
        void setDifficulty(int);

    protected:
        char sequence[50];
        /**
         *	Difficulty of:
         *		1: Only lowercase letters a-z
         *		2: Lowercase Letters & numbers a-z, 0-9
         *		3: Upper & Lowercase Letters & Numbers: A-z, 0-9
         */
        int difficulty;
        int livesRemaining;
        int position;
        int workingPosition;
};

#endif
