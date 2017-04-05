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
    int randomMax;

    switch(difficulty) {
        /**
         * 1 = Only lowercase letters
         * 2 = Lowercase letters w/ numbers
         * 3 = Upper & lowercase letters with numbers
         */
        case 1:
            randomMax = 26;
            break;
        case 2:
            randomMax = 36;
            break;
        case 3:
            randomMax = 62;
            break;
        default:
            throw string(
                "Invalid difficulty. Difficulty set to: "
            ) + to_string(difficulty);
    }

    return this->getAsciiValue(rand() % randomMax);
}

int Sequence::getAsciiValue(int randomInt)
{
    // Lowercase letter
    if(randomInt < 26) {
        // a
        randomInt += 97;
    } else if (randomInt < 36) { // Number
        // 0 (48 - 26)
        randomInt += 22;
    } else { // Uppercase letter
        // A (65 - 36)
        randomInt += 29;
    }

    return randomInt;
}

void Sequence::generateSequence(int difficulty) {
    for(int counter = 0; counter < this->getMaxLength(); counter++) {
        sequence[counter] = static_cast<char>(
            this->generateRandomInt(difficulty)
        );
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
