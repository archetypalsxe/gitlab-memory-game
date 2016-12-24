#ifndef User_h
#define User_h

using namespace std;

/**
 * How many lives the user starts with
 */
extern const int STARTING_LIVES;

/**
 * Class that defines the user using the program
 */
class User
{
    public:
        /**
         * Constructor that initializes variables
         */
        User();
        /**
         * Checks to see if the user still has lives remaining
         */
        bool hasLivesRemaining();
        /**
         * Returns the number of lives the user has remaining
         */
        int getLivesRemaining();
        /**
         * The user has entered an incorrect attempt, deducts from the lives
         * remaining
         */
        void incorrectAttempt();
    protected:
        /**
         * The number of lives the user has remaining
         */
        int livesRemaining;
};

#endif
