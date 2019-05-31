#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

enum errorNum { errClientConnect, errServerConnect, errClientRecived, errServerRecived, errClientSend, errServerSend, noError, errInitAllegro };
class errorC
{
public:
	void setErrorNumber(unsigned int errNumber);
	void setErrorDescription(string errDescription);
	unsigned int getErrorNumber(void);
	string getErrorDescription(void);

private:
	unsigned int number;
	string description;
};