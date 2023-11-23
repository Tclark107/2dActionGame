#include "TestBase.h"

TestBase::TestBase()
{
	Initialize();
}

void TestBase::Initialize()
{
	this->debugFile.open("debug.log");	
	this->logFile.open("debug.log");	
}

//TODO: write constructor/destructor for closing/initing??

//TODO: look up how topass in any object
bool TestBase::checkObjectCreated(/*template*/)
{
	if(/*template*/ true)
	{
		return true;
	}
	return false;
}

int TestBase::getGrade()
{
	return this->grade;
}

void TestBase::addOneToGrade()
{
	this->grade += 1;	
}
