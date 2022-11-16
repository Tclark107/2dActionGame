#include <iostream>
#include <stdlib.h>

class livingEntity 
{
    //TODO: move Player Entity classes to livingEntity.cpp or keep this highlevel
    // and make these virtual and put code in sub classes
    // class to class basis
    // make a makefile!!! 
    public:
        void printStats();

        int getHealth();
        int getLevel();
        int getLowAttack();
        int getHighAttack();
        int getStartingHealth();
        int getStartingXpNeeded();
        // How big can attack get?? Int may  be too small
	int calculateAttack(int lower, int upper);
	void takeDamage(int damage);

    private:
        int health = 10;
        int lowRangeAttack = 1;
        int highRangeAttack = 3;
        int level = 1;

        int startingXpNeeded = 10;
        int startingXpNeeded = 10;

        void deathEvent();
}
