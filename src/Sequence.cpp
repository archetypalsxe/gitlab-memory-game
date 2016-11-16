#include "Sequence.h"

const int STARTING_LIVES = 3;

/**
 * Constructor takes in the difficulty as a parameter
 */
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

int Sequence::getDifficulty() {
    return difficulty;
}

int Sequence::getLength() {
    return position + 1;
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
    if(WINDOWS) {
        system("cls");
    } else {
        system("reset");
    }
}

//Generating the sequence to use
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