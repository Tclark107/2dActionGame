#include "TesterBase.h"

void TesterBase::Initialize()
{
	this->debugFile.open("debug.log");	
	this->logFile.open("debug.log");	
}

//TODO: write constructor/destructor for closing/initing??

//TODO: look up how topass in any object
bool TesterBase::checkOjectCreated(/*template*/)
{
	return true;
}

int getGrade()
{
	return this->grade;
}

void TesterBase::addOneToGrade()
{
	this->grade += 1;	
}
