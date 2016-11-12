//cout
#include <iostream>
#include <stdio.h>
#include <limits>

//Getch
#include "getch.h"

//Sequence class
#include "Sequence.h"

using namespace std;

bool getEnteredSequence(Sequence);
void clearKeyboardBuffer();
void clearWindow();
void performGameMainLoop(Sequence);
void processEnteredSequence(bool, Sequence*);
void mainMenu();

int main() {
    clearWindow();
    Sequence sequence;
    mainMenu();
    sequence.generateSequence();
    performGameMainLoop(sequence);
}

void clearWindow() {
    if(WINDOWS) {
        system("cls");
    } else {
        system("reset");
    }
}

void mainMenu() {
    int difficulty = 0;
    bool valid = false;
    do {
        cout << "The Memory Game!" << endl << endl << endl;
        cout << "Please select your difficulty:" << endl;
        cout << "==================================" << endl;
        cout << "1) Only letters" << endl;
        cout << "2) Letters and numbers" << endl;
        cout << "3) Case-sensitive letters and numbers" << endl;

        cin >> difficulty;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(difficulty) {
            valid = true;
        }
    } while (!valid);
    clearWindow();
}

/**
 * Does the main game loop
 *
 * @param Sequence sequence
 */
void performGameMainLoop(Sequence sequence) {
    bool correct;

    for(int counter = 0; counter < 20 && sequence.hasLivesRemaining(); counter++) {
        sequence.displaySequence();
        clearKeyboardBuffer();

        correct = getEnteredSequence(sequence);
        processEnteredSequence(correct, &sequence);
    }
}

/**
 * Clears the keyboard buffer
 */
void clearKeyboardBuffer() {
    //Clearing keyboard buffer
    while(kbhit()) {
        getch();
    }
}

/**
 * Get's the player's entered sequence
 */
bool getEnteredSequence(Sequence sequence) {
    int character;

    cout << "Enter sequence: " << endl;

    int charactersEntered = 0;
    bool correct = false;
    do {
        character = getch();
        charactersEntered++;
    } while ((correct = sequence.checkCharacter(character)) && charactersEntered < sequence.getLength());

    return correct;
}

/**
 * Processes the entered sequence and initiates the appropriate response
 */
void processEnteredSequence(bool correct, Sequence* sequence) {
    if(correct) {
        cout << "Passed" << endl;
        sequence->nextPosition();
    } else {
        cout << "Failed" << endl;
        sequence->died();
    }
}
