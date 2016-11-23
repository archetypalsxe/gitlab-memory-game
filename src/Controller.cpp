#include "Controller.h"

// Public
void Controller::start()
{
    int difficulty = interface.getDifficulty();
    Sequence sequence(difficulty);
    sequence.generateSequence();
    this->sequence = sequence;
    mainLoop();
}

// Protected
void Controller::mainLoop()
{
    bool correct;

    for(
        int counter = 0;
        counter < sequence.getMaxLength() && sequence.hasLivesRemaining();
        counter++
    ) {
        // @TODO This should be the interface
        sequence.displaySequence();
        interface.clearWindow();
        interface.clearKeyboardBuffer();

        cout << "Enter sequence: " << endl;

        correct = interface.getEnteredSequence(sequence);
        processEnteredSequence(correct, &sequence);
    }
}

void Controller::processEnteredSequence(bool correct, Sequence* sequence) {
    if(correct) {
        cout << "Correct" << endl;
        sequence->nextPosition();
    } else {
        cout << "Not correct!" << endl;
        sequence->died();
    }
}
