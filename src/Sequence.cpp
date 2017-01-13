#include "Sequence.h"

const int MAX_LENGTH = 20;

// Public

Sequence::Sequence(int difficulty = 1)
{
    srand(time(0));
    this->generateSequence(difficulty);
}

bool Sequence::checkCharacter(int keyPressed) {
    if(keyPressed == this->sequence[workingPosition]) {
        this->workingPosition++;
        return true;
    } else {
        return false;
    }
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

void Sequence::goodAttempt()
{
    this->nextPosition();
}

void Sequence::startNewAttempt()
{
    this->resetTypingPosition();
}

// Protected

int Sequence::generateRandomInt(int difficulty)
{
    int randomInt;

    switch(difficulty) {
        /**
         * 1 = Only lowercase letters
         * 2 = Upper & lowercase letters
         * 3 = Upper and lowercase letters with numbers
         * 4 = Lowercase letters w/ numbers
         */
        case 1:
            randomInt = rand() % 26;
            //First letter is ASCII a
            randomInt += 97;
            break;
        default:
            throw string(
                "Invalid difficulty. Difficulty set to: "
            ) + to_string(difficulty);
    }

    return randomInt;
}

void Sequence::generateSequence(int difficulty) {
    for(int counter = 0; counter < this->getMaxLength(); counter++) {
        sequence[counter] = (char)this->generateRandomInt(difficulty);
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
