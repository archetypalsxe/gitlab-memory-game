#include "Interface.h"

const int MIN_DIFFICULTY = 1;
const int MAX_DIFFICULTY = 1;

// Public
bool Interface::getEnteredSequence(Sequence sequence) {
    /** @TODO This should be seperated out so that we are not passing the
     * sequence object into here
     */
    int character, charactersEntered = 0;
    bool correct = false;

    sequence.resetTypingPosition();

    do {
        character = getch();
        charactersEntered++;
    } while (
        (correct = sequence.checkCharacter(character)) &&
        charactersEntered < sequence.getLength()
    );

    return correct;
}

int Interface::getDifficulty()
{
    int difficulty;
    do {
        clearWindow();
        displayDifficultyMenu();
        cin >> difficulty;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!validDifficultySelection(difficulty));
    clearWindow();
    return difficulty;
}

void Interface::promptUserForSequence(string sequenceString)
{
    cout << "Remember this sequence:" << endl;
    cout <<  sequenceString << endl << flush;
    usleep((1 + (sequenceString.length() * 0.75)) * 1000000);

    this->clearWindow();
    this->clearKeyboardBuffer();

    cout << "Enter sequence: " << endl << flush;
}

// Protected
bool Interface::validDifficultySelection(int difficulty)
{
    return difficulty >= MIN_DIFFICULTY && difficulty <= MAX_DIFFICULTY;
}

void Interface::clearKeyboardBuffer()
{
    while(kbhit()) {
        getch();
    }
}

void Interface::clearWindow()
{
    if(WINDOWS) {
        system("cls");
    } else {
        system("reset");
    }
}

void Interface::displayDifficultyMenu()
{
    cout << "The Memory Game!" << endl << endl << endl;
    cout << "Please select your difficulty:" << endl;
    cout << "==================================" << endl;
    cout << "1) Only letters" << endl;
    cout << "2) Letters and numbers (Currently Invalid)" << endl;
    cout << "3) Case-sensitive letters and numbers (Currently Invalid)" << endl;
}
