#include <iostream>
#include <stdlib.h>

//TODO: make a makefile that has this path compiled in
#include "../LivingEntity.h"

class Player : public livingEntity
{
    public:
        void gainXp(int xpGained);
        int getXpNeeded();

    private:
        int xpNeeded = 10;
        void levelUpEvent();
};

