#include "Sequence.h"

const int MAX_LENGTH = 20;

// Public

Sequence::Sequence()
{
    position = 0;
    srand(time(0));
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

void Sequence::generateSequence() {
    for(int counter = 0; counter < this->getMaxLength(); counter++) {
        sequence[counter] = (char)this->generateRandomInt();
    }
}

void Sequence::goodAttempt()
{
    this->nextPosition();
}

void Sequence::setDifficulty(int difficulty) {
    if (difficulty == 0) {
        throw string("Alphabetic or zero difficulty provided");
    }
    this->difficulty = difficulty;
}

void Sequence::startNewAttempt()
{
    this->resetTypingPosition();
}

// Protected

int Sequence::generateRandomInt()
{
    int randomInt;

    switch(this->difficulty) {
        case 1:
            /**
             * 1 = Only lowercase letters
             * 2 = Upper & lowercase letters
             * 3 = Upper and lowercase letters with numbers
             * 4 = Lowercase letters w/ numbers
             */
            randomInt = rand() % 26;
            //First letter is ASCII a
            randomInt += 97;
            break;
        default:
            throw string(
                "Invalid difficulty. Difficulty set to: "
            ) + to_string(this->difficulty);
    }

    return randomInt;
}

void Sequence::nextPosition()
{
    this->position++;
}

void Sequence::resetTypingPosition()
{
    this->workingPosition = 0;
}
