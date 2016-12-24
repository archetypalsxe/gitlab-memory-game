#include "User.h"

const int STARTING_LIVES = 3;

User::User()
{
    livesRemaining = STARTING_LIVES;
}

bool User::hasLivesRemaining()
{
    return this->getLivesRemaining() > 0;
}

int User::getLivesRemaining()
{
    return this->livesRemaining;
}

void User::incorrectAttempt()
{
    this->livesRemaining--;
}
