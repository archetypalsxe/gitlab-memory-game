#include "Interface.h"

const int MIN_DIFFICULTY = 1;
const int MAX_DIFFICULTY = 1;

// Public

int Interface::getCharacter()
{
    return getch();
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

void Interface::displayMessage(string message, bool newLine)
{
    cout << message;
    if (newLine) {
        cout << endl;
    }
}

void Interface::promptUserForSequence(string sequenceString)
{
    this->displayMessage("Remember this sequence:", true);
    this->displayMessage(sequenceString, true);
    usleep((1 + (sequenceString.length() * 0.75)) * 1000000);

    this->clearWindow();
    this->clearKeyboardBuffer();

    this->displayMessage("Enter sequence:", true);
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
    this->displayMessage("The Memory Game!\n\n", true);
    this->displayMessage("Please select your difficulty:", true);
    this->displayMessage("==================================", true);
    this->displayMessage("1) Only letters", true);
    this->displayMessage("2) Letters and numbers (Currently Invalid)", true);
    this->displayMessage(
        "3) Case-sensitive letters and numbers (Currently Invalid)",
        true
    );
}
