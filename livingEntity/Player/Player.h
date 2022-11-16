#include <iostream>
#include <stdlib.h>

#include "livingEntity.h"

class Player : public livingEntity
{
    public:
        void gainXp(int xpGained);
        int getXpNeeded();

    private:
        int xpNeeded = 10;
        void levelUpEvent();
};

