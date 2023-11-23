#include <iostream>
#include <stdlib.h>

//TODO: make a makefile that has this path compiled in
#include "../LivingEntity.h"

class Player : public LivingEntity
{
    public:
		int getStartingXpNeeded();
        int getXpNeeded();

        void gainXp(int xpGained);

    private:
        int xpNeeded = 10;
		int startingXpNeeded = 10;

		void resetXp();
        void levelUpEvent();
		void increaseStartingXp();
		void increaseStartingHealth();
		void increaseLevel();
};

