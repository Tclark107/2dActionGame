#include <iostream>
#include <stdlib.h>

class LivingEntity 
{
    //TODO: move Player Entity classes to livingEntity.cpp or keep this highlevel
    // and make these virtual and put code in sub classes
    // class to class basis
    // make a makefile!!! 
    public:

    private:
        int health = 10;
        int lowRangeAttack = 1;
        int highRangeAttack = 3;
		int attack = 0;
        int level = 1;
		int startingHealth = 10;

        int getHealth();
        int getLevel();
        int getLowAttack();
        int getHighAttack();
        int getStartingHealth();

		// How big can attack get?? is int right here
		int calculateAttack();
		void takeDamage(int damage);
		bool checkEntityDeath();
		void resetHealth();
        void deathEvent();
        void printStats();
};
