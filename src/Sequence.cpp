#include "Sequence.h"

const int STARTING_LIVES = 3;
const int MAX_LENGTH = 20;
const int MIN_DIFFICULTY = 1;
const int MAX_DIFFICULTY = 1;

Sequence::Sequence(int difficulty) {
    /**
     *	1 = Only lowercase letters
     *	2 = Upper & lowercase letters
     *	3 = Upper and lowercase letters with numbers
     *	4 = Lowercase letters w/ numbers
     */
    this->difficulty = difficulty;
    livesRemaining = STARTING_LIVES;
    position = 0;
    srand(time(0));
}

Sequence::Sequence()
{
}

bool Sequence::hasLivesRemaining() {
    return livesRemaining > 0;
}

bool Sequence::checkCharacter(int keyPressed) {
    if(keyPressed == sequence[workingPosition]) {
        workingPosition++;
        return true;
    } else {
        return false;
    }
}

bool Sequence::validateDifficultySelection(int difficulty)
{
    return difficulty >= MIN_DIFFICULTY && difficulty <= MAX_DIFFICULTY;
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

void Sequence::died() {
    livesRemaining--;
    cout << livesRemaining << " lives left" << endl;
}

void Sequence::displaySequence() {
    cout << "Remember this sequence:" << endl;
    workingPosition = 0;

    for(int counter = 0; counter < position + 1; counter++) {
        if(counter > 0) {
            cout << " ";
        }
        cout << sequence[counter];
    }
    cout << endl << flush;
    usleep((2 + (position * 0.75)) * 1000000);
    /*
    if(WINDOWS) {
        system("cls");
    } else {
        system("reset");
    }
    */
}

void Sequence::generateSequence() {
    int randomInt;

    for(int counter = 0; counter < 50; counter++) {
        switch(difficulty) {
            case 1:
            default:
                randomInt = rand() % 26;
                //First letter is ASCII a
                randomInt += 97;
                break;
        }
        sequence[counter] = (char)randomInt;
    }
}

void Sequence::nextPosition() {
    position++;
}

void Sequence::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
}
