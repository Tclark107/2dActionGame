#include "Player.h"

//debugFlag = 0;

//Player::Player()
//{
//}

int Player::getHealth()
{
    return this->health;
}
int Player::getXpNeeded()
{
    return this->xpNeeded;
}

int Player::getLevel()
{
    return this->level;
}

int Player::getLowAttack()
{
    return this->lowRangeAttack;
}

int Player::getHighAttack()
{
    return this->highRangeAttack;
}

int Player::getStartingHealth()
{
    return this->startingHealth;
}

int Player::getStartingXpNeeded()
{
    return this->startingXpNeeded;
}


void Player::printStats()
{
    std::cout << "health = " << this->health << std::endl;
    std::cout << this->lowRangeAttack << std::endl;
    std::cout << this->highRangeAttack << std::endl;
    std::cout << this->level << std::endl;
    std::cout << "xpNeeded = " << this->xpNeeded << std::endl;
}

int Player::calculateAttack(int lower, int upper)
{
    int attack = (rand() % (upper - lower + 1)) + lower;
    return attack;
}

void Player::takeDamage(int damage)
{
    this->health -= damage;
    if(this->health <= 0)
    {
        //should this be here
        deathEvent();
    }
}

void Player::deathEvent()
{
    // print this to log file
    std::cout << "You Died" << std::endl;
    this->health = this->getStartingHealth();
    // reset to a fraction rather than starting
    this->xpNeeded = this->getStartingXpNeeded();
    
    //respawnEvent()
}

void Player::gainXp(int xpGained)
{
    this->xpNeeded -= xpGained;
    if(this->xpNeeded <= 0)
    {
        levelUpEvent();
    }
}

void Player::levelUpEvent()
{
    // change to a fractional multiplier
    this->startingXpNeeded += 2;
    this->startingHealth += 2;

    this->xpNeeded = this->startingXpNeeded;
    this->health = startingHealth;

    this->level += 1;
    std::cout << "You Leveled up!!! You are now level " << this->level << std::endl; 
}

// testing
//int main()
//{
//   Player player1;
//   int lower = player1.getLowAttack();
//   int upper = player1.getHighAttack();
//   int attack = player1.calculateAttack(lower, upper);
//   std::cout << "attack = " << attack << std::endl;
//   player1.printStats();
//}
