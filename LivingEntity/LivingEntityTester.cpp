#include <iostream>
#include <fstream>

#include "LivingEntity.h"

//void print(int variable)
//{
//    std::cout << "TJC variable " << func and file << variable << std::endl;
//}

int score = 0;
bool debugMode = 1;
std::ofstream debugFile;
std::ofstream logFile;

void grade(bool isCorrect)
{
    if(isCorrect)
    {
        score += 1;
    }
}

void initialize()
{
}

bool checkHealthChangeMatches(int healthAfterAttack, 
                              int currentLivingEntityHealth)
{
    if(healthAfterAttack != currentLivingEntityHealth)
    {
        // you have to check this against the startingLivingEntityHealth
        if(healthAfterAttack <= 0 && currentLivingEntityHealth == 10)
        {
            if(debugMode)
            {
                debugFile << "LivingEntity is dead?? newHealth = " 
                        << healthAfterAttack <<
                    ", liveEntity Health = " 
                    << currentLivingEntityHealth << std::endl;
            }
            return 1;
        }
        // clean this and move to output Function
        // and make it write to a debug file
        debugFile << "newHealth = " << healthAfterAttack << std::endl;
        debugFile << "liveEntity health now = " << currentLivingEntityHealth 
                  << std::endl;

        return 0;
    }
    return 1;
}

bool checkDead(int currentHealth, int currentStartingHealth)
{
    if(currentHealth == currentStartingHealth)
    {
        return 1;
    }
    return 0;
}

// find a way to put this reading top to bottom
// without the compiler complaining
void testEntityDamage(LivingEntity &liveEntity, int damage)
{
    int healthBeforeAttack = liveEntity.getHealth();
    int startingHealthBeforeAttack = liveEntity.getStartingHealth();

    // This line makes liveEntity.health = liveEntity.health - damage
    // If leveled up, then gainXp(int) resets stats
    int healthAfterAttack = healthBeforeAttack - damage;

    liveEntity.takeDamage(damage);

    int currentStartingHealth = liveEntity.getStartingHealth();
    int currentHealth = liveEntity.getHealth();

    // check dead
    //  if currenthealth is = tobase health then you died and code
    //  is working
    //  depending on this out come
    //  check if the health change matches based off of damage
    //  which is what this function does
    //  otherwise grade what the check dead did
    bool healthIsCorrect = checkHealthChangeMatches(healthAfterAttack, 
                                                    liveEntity.getHealth());
    grade(healthIsCorrect);
}

void damageTest(LivingEntity &testLiveEntity)
{
	//for 1 < X < 1000
	// damage is equal to random number between Health
	// and 0
	// if liveEntity health - damage < 0 and not dead then throw error
	//
    int damage = 2;
    testEntityDamage(testLiveEntity, damage);
    testEntityDamage(testLiveEntity, damage);
    testEntityDamage(testLiveEntity, damage);
    testEntityDamage(testLiveEntity, damage);
    testEntityDamage(testLiveEntity, damage);
}

void testLivingEntityObject()
{
    LivingEntity testLiveEntity;

    damageTest(testLiveEntity);

    // print to log file
    // TODO:writeTesterOutputFunction/File
    logFile << "score = " << score << std::endl;
}

int main()
{
    debugFile.open("debug.log");
    logFile.open("out.log");
    testLivingEntityObject();
    debugFile.close();
    logFile.close();
}
