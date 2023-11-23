#include <iostream>

#include "TestBase.h"

int main()
{
	TestBase Test;
	
	Test.addOneToGrade();
	std::cout << Test.getGrade() << std::endl;
}

