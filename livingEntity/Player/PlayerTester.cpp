#include <iostream>

#include "Player.h"

//void print(int variable)
//{
//    std::cout << "TJC variable " << func and file << variable << std::endl;
//}

int score = 0;
//bool debug = 1;

void grade(bool isCorrect)
{
    if(isCorrect)
    {
        score += 1;
    }
}

bool checkHealthChangeMatches(int healthAfterAttack, int currentPlayerHealth)
{
    if(healthAfterAttack != currentPlayerHealth)
    {
        // you have to check this against the startingPlayerHealth
        if(healthAfterAttack <= 0 && currentPlayerHealth == 10)
        {
            // check that deathEvent worked, make sure that the
            // reset worked
            //std::cout << "Player is dead?? newHealth = " << newHealth <<
            //    ", player Health = " << player.getHealth() << std::endl;
            return 1;
        }
        // clean this and move to output Function
        // and make it write to a debug file
        std::cout << "newHealth = " << healthAfterAttack << std::endl;
        std::cout << "player health now = " << currentPlayerHealth << std::endl;

        return 0;
    }
    return 1;
}

// find a way to put this reading top to bottom
// without the compiler complaining
void testPlayerDamage(Player &player, int damage)
{
    int healthBeforeAttack = player.getHealth();
    player.takeDamage(damage);
    int healthAfterAttack = healthBeforeAttack - damage;

    //move this to a checkHealth check and pass in player instead
    //probably want to check if death first
    //checkDeath(newHealth, startingHealth);
    bool healthIsCorrect = checkHealthChangeMatches(healthAfterAttack, player.getHealth());
    grade(healthIsCorrect);
}

void damageTest(Player &testPlayer)
{
    int damage = 2;
    testPlayerDamage(testPlayer, damage);
    testPlayerDamage(testPlayer, damage);
    testPlayerDamage(testPlayer, damage);
    testPlayerDamage(testPlayer, damage);
    testPlayerDamage(testPlayer, damage);
}

bool checkXpChangeMatches(int xpAfterGain, int currentXpNeeded)
{
    //debug flag would be nice
    //std::cout << "xpAfterGain = " << xpAfterGain << std::endl;
    //std::cout << "currentXpneeded = " << currentXpNeeded << std::endl;
    if(xpAfterGain != currentXpNeeded)
    {
        // I need to find a different check for leveled
        // up current xp needed
        if(xpAfterGain <= 0 && currentXpNeeded > 10)
        {
            //std::cout << "Level up?? " << std::endl;
            return 1;
        }
        return 0;
    }
    return 1;
}

void testXpGained(Player &player, int xpGained)
{
    int xpNeededBeforeGain = player.getXpNeeded();
    int xpNeededAfterGain = xpNeededBeforeGain - xpGained;
    player.gainXp(xpGained);

    //checkLevelUp(xpAfterGain, playerStartingHealth);
    bool xpIsCorrect = checkXpChangeMatches(xpNeededAfterGain, player.getXpNeeded());
    grade(xpIsCorrect);
}

void xpGainTest(Player &player)
{
    int xpGained = 3;
    testXpGained(player, xpGained);
    testXpGained(player, xpGained);
    testXpGained(player, xpGained);

    //TODO: debugFlag
    //player.printStats();
    testXpGained(player, xpGained);
    //player.printStats();
}

void testPlayerObject()
{
    Player testPlayer;

    // make score a pointer and pass by reference here
    damageTest(testPlayer);
    xpGainTest(testPlayer);

    // print to log file
    // TODO:writeTesterOutputFunction/File
    std::cout << "score = " << score << std::endl;
}

int main()
{
    testPlayerObject();
}
