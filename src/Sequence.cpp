#include "Sequence.h"

const int STARTING_LIVES = 3;
const int MAX_LENGTH = 20;

Sequence::Sequence()
{
    livesRemaining = STARTING_LIVES;
    position = 0;
    srand(time(0));
}

bool Sequence::hasLivesRemaining() {
    return livesRemaining > 0;
}

bool Sequence::checkCharacter(int keyPressed) {
    if(keyPressed == this->sequence[workingPosition]) {
        this->workingPosition++;
        return true;
    } else {
        return false;
    }
}

int Sequence::getDifficulty() {
    return difficulty;
}

int Sequence::getLength() {
    return position + 1;
}

int Sequence::getMaxLength()
{
    return MAX_LENGTH;
}

string Sequence::getSequenceString()
{
    string sequenceString;

    for(int counter = 0; counter < position + 1; counter++) {
        sequenceString += sequence[counter];
    }
    return sequenceString;
}

void Sequence::died() {
    livesRemaining--;
    cout << livesRemaining << " lives left" << endl;
}

void Sequence::generateSequence() {
    int randomInt;

    for(int counter = 0; counter < 50; counter++) {
        /**
         *	1 = Only lowercase letters
         *	2 = Upper & lowercase letters
         *	3 = Upper and lowercase letters with numbers
         *	4 = Lowercase letters w/ numbers
         */
        switch(difficulty) {
            case 1:
                randomInt = rand() % 26;
                //First letter is ASCII a
                randomInt += 97;
                break;
            default:
                throw string(
                    "Invalid difficulty. Difficulty set to: "
                ) + to_string(this->difficulty);
        }
        sequence[counter] = (char)randomInt;
    }
}

void Sequence::nextPosition()
{
    this->position++;
}

void Sequence::resetTypingPosition()
{
    this->workingPosition = 0;
}

void Sequence::setDifficulty(int difficulty) {
    if (difficulty == 0) {
        throw string("Alphabetic or zero difficulty provided");
    }
    this->difficulty = difficulty;
}
