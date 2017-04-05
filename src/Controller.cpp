#include "Controller.h"

//Public

/**
 * @TODO Fix. Wish that we didn't have to instantiate sequence like this
 */
Controller::Controller() : sequence(1)
{
}

void Controller::start()
{
    try {
        int difficulty = interface.getDifficulty();
        this->sequence = Sequence(difficulty);
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

void Controller::correctSequenceAttempt()
{
    this->sequence.goodAttempt();
    this->interface.correctSequenceEntered();
}

void Controller::incorrectSequenceAttempt()
{
    this->user.incorrectAttempt();
    this->interface.incorrectSequenceEntered(
        this->user.getLivesRemaining()
    );
}

void Controller::mainLoop()
{
    for(
        int counter = 0;
        counter < this->sequence.getMaxLength() && user.hasLivesRemaining();
        counter++
    ) {
        interface.promptUserForSequence(this->sequence.getSequenceString());
        if(this->getSequenceAttempt()) {
            this->correctSequenceAttempt();
        } else {
            this->incorrectSequenceAttempt();
        }
    }
}
