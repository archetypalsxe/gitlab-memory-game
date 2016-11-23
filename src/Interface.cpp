#include "Interface.h"

bool Interface::getEnteredSequence(Sequence sequence) {
    int character, charactersEntered = 0;
    bool correct = false;

    do {
        character = getch();
        charactersEntered++;
    } while (
        (correct = sequence.checkCharacter(character)) &&
        charactersEntered < sequence.getLength()
    );

    return correct;
}

// Public
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

// Protected
bool Interface::validDifficultySelection(int difficulty)
{
    Sequence sequence;
    return sequence.validateDifficultySelection(difficulty);
}

void Interface::displayDifficultyMenu()
{
    cout << "The Memory Game!" << endl << endl << endl;
    cout << "Please select your difficulty:" << endl;
    cout << "==================================" << endl;
    cout << "1) Only letters" << endl;
    cout << "2) Letters and numbers" << endl;
    cout << "3) Case-sensitive letters and numbers" << endl;
}
