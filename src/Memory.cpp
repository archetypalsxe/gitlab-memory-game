#include <iostream>

#include "Controller.h"
#include "Interface.h"

using namespace std;

int main()
{
    Controller controller;
    controller.start();
}


/*
bool getEnteredSequence(Sequence);
bool validDifficultySelection(int);
int mainMenu();
void clearKeyboardBuffer();
void clearWindow();
void displayDifficultyMenu();
void performGameMainLoop(Sequence);
void processEnteredSequence(bool, Sequence*);
*/

/**
 * This is where we initialize everything and get the game going
 */
/*
int main() {
    int difficulty = mainMenu();
    Sequence sequence(difficulty);
    sequence.generateSequence();
    performGameMainLoop(sequence);
}
*/

/**
 * Retrieves input from the user until they complete the sequence or they
 * enter a character incorrectly. Returns whether or not they entered the
 * entirity of the sequence correctly or not
 */
/*
bool getEnteredSequence(Sequence sequence) {
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
*/

/**
 * Test to see whether a user's difficulty selection is valid or not
 */
/*
bool validDifficultySelection(int selection) {
    return selection >= MIN_DIFFICULTY && selection <= MAX_DIFFICULTY;
}
*/

/**
 * Display the main menu to the user and returns their selection for
 * difficulty
 */
/*
int mainMenu() {
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
*/

/**
 * Clear the terminal based on whether we are in Windows or not
 */
/*
void clearWindow() {
    if(WINDOWS) {
        system("cls");
    } else {
        system("reset");
    }
}
*/

/**
 * Display the difficulty menu to the user
 */
/*
void displayDifficultyMenu() {
    cout << "The Memory Game!" << endl << endl << endl;
    cout << "Please select your difficulty:" << endl;
    cout << "==================================" << endl;
    cout << "1) Only letters" << endl;
    cout << "2) Letters and numbers" << endl;
    cout << "3) Case-sensitive letters and numbers" << endl;
}
*/

/**
 * The main game loop where all the magic happens. This is where we take
 * user input and whatnot
 */
/*
void performGameMainLoop(Sequence sequence) {
    bool correct;

    for(
        int counter = 0;
        counter < MAX_LENGTH && sequence.hasLivesRemaining();
        counter++
    ) {
        sequence.displaySequence();
        clearKeyboardBuffer();

        cout << "Enter sequence: " << endl;

        correct = getEnteredSequence(sequence);
        processEnteredSequence(correct, &sequence);
    }
}
*/

/**
 * Clears the keyboard buffer
 */
/*
void clearKeyboardBuffer() {
    //Clearing keyboard buffer
    while(kbhit()) {
        getch();
    }
}
*/

/**
 * Processes the entered sequence and initiates the appropriate response
 */
/*
void processEnteredSequence(bool correct, Sequence* sequence) {
    if(correct) {
        cout << "Correct" << endl;
        sequence->nextPosition();
    } else {
        cout << "Not correct!" << endl;
        sequence->died();
    }
}
*/
