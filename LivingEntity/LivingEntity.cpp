#include "LivingEntity.h"

//debugFlag = 0 

//LivingEntity::LivingEntity()
//{
//}

int LivingEntity::getHealth()
{
    return this->health;
}

int LivingEntity::getLevel()
{
    return this->level;
}

int LivingEntity::getLowAttack()
{
    return this->lowRangeAttack;
}

int LivingEntity::getHighAttack()
{
    return this->highRangeAttack;
}

int LivingEntity::getStartingHealth()
{
    return this->startingHealth;
}

int LivingEntity::calculateAttack()
{
	//random between low/high atk
	//TODO: temporary fix, get rid of this
	return this->attack = 5;
}

void LivingEntity::takeDamage(int damage)
{
	this->health -= damage;
	if(checkEntityDeath())
	{
		deathEvent();
	}
}

bool LivingEntity::checkEntityDeath()
{
	if(this->health <= 0)
	{
		return true;
	}
	return false;
}

void LivingEntity::resetHealth()
{
    this->health = this->getStartingHealth();
}

// This needs to be virtual so I can overwrite it
void LivingEntity::deathEvent()
{
    //TODO: print this to log file
    std::cout << "You Died" << std::endl;
	resetHealth();
}

void LivingEntity::printStats()
{
	std::cout << LivingEntity::getHealth() << std::endl;
	std::cout << LivingEntity::getLevel() << std::endl;
	std::cout << LivingEntity::getStartingHealth() << std::endl;
	std::cout << LivingEntity::getLowAttack() << std::endl;
	std::cout << LivingEntity::getHighAttack() << std::endl;
}

