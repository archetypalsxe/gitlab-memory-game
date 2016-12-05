#include "Controller.h"

void Controller::start()
{
    try {
        int difficulty = interface.getDifficulty();
        this->sequence.setDifficulty(difficulty);
        this->sequence.generateSequence();
        mainLoop();
    } catch (string e) {
        cout << "There was an exception: " << e << endl;
    }
}

void Controller::mainLoop()
{
    bool correct;

    for(
        int counter = 0;
        counter < sequence.getMaxLength() && sequence.hasLivesRemaining();
        counter++
    ) {
        interface.promptUserForSequence(sequence.getSequenceString());
        correct = interface.getEnteredSequence(sequence);
        this->processEnteredSequence(correct, &sequence);
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
