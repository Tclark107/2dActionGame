#include <iostream>
#include <stdlib.h>

class Player
{
    public:
        void printStats();

        int getHealth();
        int getXpNeeded();
        int getLevel();
        int getLowAttack();
        int getHighAttack();
        int getStartingHealth();
        int getStartingXpNeeded();

        // How big can attack get?? Int may  be too small
        int calculateAttack(int lower, int upper);
        void takeDamage(int damage);
        void gainXp(int xpGained);

    private:
        int health = 10;
        int lowRangeAttack = 1;
        int highRangeAttack = 3;
        int level = 1;
        int xpNeeded = 10;

        int startingHealth = 10;
        int startingXpNeeded = 10;

        void deathEvent();
        void levelUpEvent();
};

