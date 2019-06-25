#pragma once
#include <iostream>
#include "eventHandling.h"
#include "genericFSM.h"
#include "simpleEventGenerator.h"
#include "defines.h"
#include "auxiliar.h"
#include "io.h"
#include "client.h"
#include "server.h"
#include "Catan.h"


enum implStates : stateTypes { inMyTurn, waitTurn, endOfGame };

using namespace std;
class FSMImplementation : public genericFSM
{
private:

#define TX(x) (static_cast<void (genericFSM::* )(genericEvent *)>(&FSMImplementation::x))

	io* GUI;
	Catan* catan;
	client* COMU_c;
	server* COMU_s;
	message mensaje;
	int myStatus;		// Mi estado en la comunicacion
	bool messageExist;
	bool ackRecived;



	const fsmCell fsmTable3[3][8] = {
		//       Trade						PortTrade                  BankTrade                   Build							MaxScore					Invalid						EndOfTurn			    	DiceThrew				
		{ { inMyTurn,TX(askTrade) },  { inMyTurn,TX(portTrade) }  ,{ inMyTurn,TX(bankTrade) } , { inMyTurn,TX(building) }    ,{ endOfGame,TX(victory) }  ,  { endOfGame,TX(error) },   { waitTurn,TX(endOfMyTurn) }, { inMyTurn,TX(noAction) } },    //inMyTurn
		{ { waitTurn,TX(answering) }, { waitTurn,TX(checkPort) }  ,{ waitTurn,TX(checkBank) } , { waitTurn,TX(verifyBuild) } ,{ waitTurn,TX(victoryCheck) },{ endOfGame,TX(error) },   { inMyTurn,TX(endOtherTurn) },{ waitTurn,TX(dice) } },	  //waitTurn
		{ { endOfGame,TX(noAction) }, { endOfGame,TX(noAction) }  ,{ endOfGame,TX(noAction) } , { endOfGame,TX(noAction) }   ,{ endOfGame,TX(noAction) }  , { endOfGame,TX(noAction) },{ endOfGame,TX(noAction) } ,  { endOfGame,TX(noAction) } }		//endOfGame
	};

	void noAction(genericEvent * ev);
	void askTrade(genericEvent * ev);
	void answering(genericEvent * ev);
	void bankTrade(genericEvent * ev);
	void checkBank(genericEvent * ev);
	void portTrade(genericEvent * ev);
	void checkPort(genericEvent * ev);
	void building(genericEvent * ev);
	void verifyBuild(genericEvent * ev);
	void endOfMyTurn(genericEvent * ev);
	void endOtherTurn(genericEvent * ev);
	void dice(genericEvent * ev);
	void victory(genericEvent * ev);
	void victoryCheck(genericEvent * ev);
	void error(genericEvent * ev);

public:
	FSMImplementation() : genericFSM(&fsmTable3[0][0], 8, 3, inMyTurn) {}
	
	void setFSM(io* GUI_i, Catan* catan_i, client* COMUC_i, server* COMUS_i, int myStatus_i);
};