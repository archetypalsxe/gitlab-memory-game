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
        this->interface.displayMessage("There was an exception: " + e, true);
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
        this->interface.displayMessage("Correct", true);
        this->sequence.goodAttempt();
    } else {
        this->interface.displayMessage("Not correct!", true);
        this->user.incorrectAttempt();
        this->interface.displayMessage(
            to_string(this->user.getLivesRemaining()) + " lives left",
            true
        );
    }
}
