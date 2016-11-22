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
extern const int MIN_DIFFICULTY;
extern const int MAX_DIFFICULTY;

class Sequence {
    public:
        /**
         * Constructor takes in the difficulty as a parameter
         */
        Sequence(int);
        bool checkCharacter(int);
        bool hasLivesRemaining();
        int getDifficulty();
        int getLength();
        void died();
        void displaySequence();
        /**
         * Generates the sequence that the user will have to enter
         */
        void generateSequence();
        void nextPosition();
        void setDifficulty(int);

    protected:
        char sequence[50];
        int difficulty;
        int livesRemaining;
        int position;
        int workingPosition;
};

#endif
