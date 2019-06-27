#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include "defines.h"
#include "auxiliar.h"


class controller
{
public:
	//controller();
	//~controller();

	virtual bool startConnection(void) = 0;
	virtual void sendName(void) = 0;
	virtual void sendDices(unsigned int dice1, unsigned int dice2) = 0;
	virtual void sendNameIs(unsigned char lcount, const char* name) = 0;
	virtual void sendAck(void) = 0;
	virtual void sendMapIs(char arr[MAX_NUMBER_PIECES]) = 0;
	virtual void sendCircularTokens(char arr[MAX_NUMBER_PIECES]) = 0;
	virtual void sendRobberCards(unsigned int ncard, const char *arr) = 0;
	virtual void sendRobberMove(unsigned char terrain) = 0;
	virtual void sendSettlement(coordenates coord, unsigned int coordQuant) = 0;
	virtual void sendRoad(coordenates coord, unsigned int coordQuant) = 0;
	virtual void sendCity(coordenates coord, unsigned int coordQuant) = 0;
};
