#include "Player.h"

//debugFlag = 0;

//Player::Player()
//{
//}

int Player::getXpNeeded()
{
    return this->xpNeeded;
}

int Player::getStartingXpNeeded()
{
    return this->startingXpNeeded;
}

void Player::gainXp(int xpGained)
{
    this->xpNeeded -= xpGained;
    if(this->xpNeeded <= 0)
    {
        levelUpEvent();
    }
}

void Player::increaseStartingXp()
{
    //TODO change to a fractional multiplier
    this->startingXpNeeded += 2;
}

void Player::increaseStartingHealth()
{
    this->startingXpNeeded += 2;
}

void Player::increaseLevel()
{
    this->level += 1;
}

void Player::levelUpEvent()
{
	increaseStartingXp();
	increaseStartingHealth();

	resetHealth();
	resetXp();

	increaseLevel();

    //TODO: print this to log file
    std::cout << "You Leveled up!!! You are now level " << this->level << std::endl; 
}

void Player::resetXP()
{
    this->health = this->getStartingHealth();
}

void Player::deathEvent()
{
    //TODO: print this to log file
    std::cout << "You Died" << std::endl;
	resetHealth();
	resetXp();

	// not all entities will respawn?? or different entities will
	// different respawn events
    //respawnEvent()
}

// testing
//int main()
//{
//   Player player1;
//   player1.printStats();
//}
