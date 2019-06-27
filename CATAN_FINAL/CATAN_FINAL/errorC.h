#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

enum errorNum { errClientConnect, errServerConnect, errClientReceived, errServerReceived, errClientSend, errServerSend, noError, errInitAllegro };
class errorC
{
public:
	void setErrorNumber(unsigned int errNumber);
	void setErrorDescription(string errDescription);
	unsigned int getErrorNumber();
	string getErrorDescription();

private:
	unsigned int number;
	string description;
};