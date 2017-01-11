#include "Controller.h"

//Public

void Controller::start()
{
    try {
        int difficulty = interface.getDifficulty();
        this->sequence.setDifficulty(difficulty);
        this->sequence.generateSequence();
        mainLoop();
    } catch (string e) {
        this->interface.thrownException(e);
    }
}

//Protected

bool Controller::getSequenceAttempt()
{
    int character, charactersEntered = 0;
    bool correct = false;

    this->sequence.startNewAttempt();

    do {
        character = this->interface.getCharacter();
        charactersEntered++;
    } while (
        (correct = this->sequence.checkCharacter(character)) &&
        charactersEntered < this->sequence.getLength()
    );

    return correct;
}

void Controller::mainLoop()
{
    bool correct;

    for(
        int counter = 0;
        counter < sequence.getMaxLength() && user.hasLivesRemaining();
        counter++
    ) {
        interface.promptUserForSequence(sequence.getSequenceString());
        correct = this->getSequenceAttempt();
        this->processEnteredSequence(correct);
    }
}

void Controller::processEnteredSequence(bool correct)
{
    if(correct) {
        this->sequence.goodAttempt();
        this->interface.correctSequenceEntered();
    } else {
        this->user.incorrectAttempt();
        this->interface.incorrectSequenceEntered(
            this->user.getLivesRemaining()
        );
    }
}
