#include "errorC.h"

void errorC::setErrorNumber(unsigned int errNumber)
{
	number = errNumber;
}

void errorC::setErrorDescription(string errDescription)
{
	description = errDescription;
}

unsigned int errorC::getErrorNumber(void)
{
	return number;
}

string errorC::getErrorDescription(void)
{
	return description;
}
