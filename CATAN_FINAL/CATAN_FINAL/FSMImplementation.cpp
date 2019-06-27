#include "FSMImplementation.h"

void FSMImplementation::noAction(genericEvent * ev)
{
	cout << "no puedo recibir eso master" << endl;
}

//HECHO
void FSMImplementation::askTrade(genericEvent * ev)
{
	int wood, clay, sheep, wheat, stone;
	wood = catan->getPlayer1()->getWood();
	clay = catan->getPlayer1()->getClay();
	sheep = catan->getPlayer1()->getSheep();
	wheat = catan->getPlayer1()->getWheat();
	stone = catan->getPlayer1()->getStone();

	tradeIn doy, quiero;
	doy = GUI->getTradeInfo(wood, sheep, stone, clay, wheat, 0);//flag es 0 para ofrecer
	quiero = GUI->getTradeInfo(9, 9, 9, 9, 9, 1); //flag es 1 para pedir
		
	if (myStatus == IM_SERVER)
	{
		COMU_s->sendOfferTrade(doy, quiero);

		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == YES)	
		{
			COMU_s->sendAck();
            catan->validTrade(doy, quiero, catan->getPlayer1(), catan->getPlayer2()); // esto ya lo redistribuye( esta en catan.h)
			GUI->showAnswer(1); //deberia ser ACCEPT?
		}
		else if (mensaje.identifier == NO)
		{
			COMU_s->sendAck();
			GUI->showAnswer(0); //deberia ser NO_ACCEPT?
		}
	}
	else if (myStatus == IM_CLIENT)
	{
		// Le envio el settlement
		COMU_c->sendOfferTrade(doy, quiero);

		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == YES)
		{
			COMU_c->sendAck();
            catan->validTrade(doy, quiero, catan->getPlayer1(), catan->getPlayer2()); // esto ya lo redistribuye( esta en catan.h)
			GUI->showAnswer(1); //deberia ser ACCEPT?
		}
		else if (mensaje.identifier == NO)
		{
			COMU_c->sendAck();
			GUI->showAnswer(0); //deberia ser NO_ACCEPT?
		}
	}

}

//HECHO
void FSMImplementation::answering(genericEvent * ev)// al final con los informes hay algo que no entendi
{

	int woodG = 0, clayG = 0, sheepG = 0, wheatG = 0, stoneG = 0;
	int woodR = 0, clayR = 0, sheepR = 0, wheatR = 0, stoneR = 0;

	tradeIn trade1, trade2;

	trade1.wood = catan->getPlayer1()->getWood();
	trade1.sheep = catan->getPlayer1()->getSheep();
	trade1.wheat = catan->getPlayer1()->getWheat();
	trade1.clay = catan->getPlayer1()->getClay();
	trade1.stone = catan->getPlayer1()->getStone();

	trade2.wood = catan->getPlayer2()->getWood();
	trade2.sheep = catan->getPlayer2()->getSheep();
	trade2.wheat = catan->getPlayer2()->getWheat();
	trade2.clay = catan->getPlayer2()->getClay();
	trade2.stone = catan->getPlayer2()->getStone();

	GUI->showYN(trade1, trade2);

	char myAnswer;
	myAnswer = GUI->getYN();
	if (myAnswer == YES)
	{

		bool canTrade = catan->canTrade(trade1, trade2, catan->getPlayer1(), catan->getPlayer2());
		if (canTrade)
		{
            catan->validTrade(trade1, trade2, catan->getPlayer1(), catan->getPlayer2());
			if (myStatus == IM_SERVER)
			{
				COMU_s->sendYes();

				while (!messageExist)
				{
					messageExist = COMU_s->isMessage();
				}
				messageExist = false;
				mensaje = COMU_s->getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)
				{
					ackReceived = true;
				}
			}
			else if (myStatus == IM_CLIENT)
			{
				// Le envio el settlement
				COMU_c->sendYes();

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_c->isMessage();
				}
				messageExist = false;
				mensaje = COMU_c->getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)
				{
					ackReceived = true;
				}
			}
		}
		else
		{
			if (myStatus == IM_SERVER)
			{
				COMU_s->sendNo();

				while (!messageExist)
				{
					messageExist = COMU_s->isMessage();
				}
				messageExist = false;
				mensaje = COMU_s->getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)
				{
					ackReceived = true;
				}
			}
			else if (myStatus == IM_CLIENT)
			{
				// Le envio el settlement
				COMU_c->sendNo();

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_c->isMessage();
				}
				messageExist = false;
				mensaje = COMU_c->getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)
				{
					ackReceived = true;
				}
			}
		}
	}
	else if(myAnswer == NO)
	{
		if (myStatus == IM_SERVER)
		{
			COMU_s->sendNo();

			while (!messageExist)
			{
				messageExist = COMU_s->isMessage();
			}
			messageExist = false;
			mensaje = COMU_s->getMessage(); //Obtengo el mensaje
			if (mensaje.identifier == ACK)
			{
				ackReceived = true;
			}
		}
		else if (myStatus == IM_CLIENT)
		{
			// Le envio el settlement
			COMU_c->sendNo();

			// Espero a que me esponda que recibio los tokens
			while (!messageExist)
			{
				messageExist = COMU_c->isMessage();
			}
			messageExist = false;
			mensaje = COMU_c->getMessage(); //Obtengo el mensaje
			if (mensaje.identifier == ACK)
			{
				ackReceived = true;
			}
		}
	}
}

//HECHO
void FSMImplementation::bankTrade(genericEvent * ev)
{
	tradeBank trade;

	trade = GUI->getTradeBank();
    // tradeBank devuelve true si hizo el trade y false si no lo hizo
    catan->tradeBank(trade.give, trade.receive, catan->getPlayer1()); //No deberia checkear si se puede hacer el trade antes?

	if (myStatus == IM_SERVER)
	{
		COMU_s->sendBankTrade(trade.give, trade.receive, 4);

		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == YES)
		{
			COMU_s->sendAck();
			GUI->showAnswer(1);
		}
		else if (mensaje.identifier == NO)
		{
			COMU_s->sendAck();
			GUI->showAnswer(0);
		}
	}
	else if (myStatus == IM_CLIENT)
	{
		// Le envio el settlement
		COMU_c->sendBankTrade(trade.give, trade.receive, 4);

		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == YES)
		{
			COMU_c->sendAck();
			GUI->showAnswer(1); //deberia ser ACCEPT?
		}
		else if (mensaje.identifier == NO)
		{
			COMU_c->sendAck();
			GUI->showAnswer(0); //deberia ser NO_ACCEPT?
		}
	}

	
}

//HECHO (falta error)
void FSMImplementation::checkBank(genericEvent * ev)
{
	cout << "el otro tradeo con el banco" << endl;
	int woodG = 0, clayG = 0, sheepG = 0, wheatG = 0, stoneG = 0;
	int woodR = 0, clayR = 0, sheepR = 0, wheatR = 0, stoneR = 0;
	errorT puedo;
	char give;
	char take;


	message mensaje;
	if (myStatus == IM_SERVER)
	{
		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == BANK_TRADE)
		{
			give = mensaje.content[0];
			take = mensaje.contentBIS[0];
			puedo = catan->tradeBank(give, take, catan->getPlayer2());
			if (puedo == NO_ERROR_t)
			{
				COMU_s->sendAck();
			}
			else
			{
				//generar error
			}

	
		}
	}
	else if (myStatus == IM_CLIENT)
	{
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == BANK_TRADE)
		{
			give = mensaje.content[0];
			take = mensaje.contentBIS[0];
			puedo = catan->tradeBank(give, take, catan->getPlayer2());
			if (puedo == NO_ERROR_t)
			{
				COMU_c->sendAck();
			}
			else
			{
				//generar error
			}


		}
	}
}

void FSMImplementation::portTrade(genericEvent * ev)// necesito saber que port es
{
	cout << "port trade" << endl;

	int wood, clay, sheep, wheat, stone;
	wood = catan->getPlayer1()->getWood();
	clay = catan->getPlayer1()->getClay();
	sheep = catan->getPlayer1()->getSheep();
	wheat = catan->getPlayer1()->getWheat();
	stone = catan->getPlayer1()->getStone();

	//Que puerto fue?**********************************************************************************

	//tradeDock(resources give[], resources take, Dock dock, Player * player)

	//Checkear que pueda acceder a ese puerto?**********************************************************

	/*if (positivo)
	{
	//sendPortTrade() // de server.h o client.h ????????????????????????????????????????????????????????
	//show enough?
	}
	else
	{
	void showDontEnough(void) //avisa que no podes tradear
	}*/
}

void FSMImplementation::checkPort(genericEvent * ev)
{
	cout << "el otro tradeo con el puerto" << endl;
	//message getMessage(void)

	//catan.tradePort(resources[5] misResources, resources quiero, catan.getPlayer2());
	//agregar if si e if no

	//Faltaria informar via allegro que se hizo el trade

}

//HECHO (CARO FIJATE EN CAN BUILD ROAD!!!!)
void FSMImplementation::building(genericEvent * ev)
{
	// PUEDE SER QUE LO QUE ESTA COMENTADO ABAJO NO HACE FALTA QUE VAYA!!!!
	//if (input == BUILD)
	//{
	//	AllGUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, BUILDING_MENU);
	//	mensaje = AllGUI.getBuildingInput();
	//}
	
	// EN TEORIA YA SE APRETO EL BOTON "CONSTRUIR"

	genIn input;

	GUI->showGeneralDisplay(catan->getPlayer1(), catan->getPlayer2(), catan->getMap(), true, BUILDING_MENU);
	input = GUI->getBuildingInput();

	//Coordenadas para logica
	Coordinates coords(input.x, input.y, input.z);
	//Coordenadas para comunicacion
	coordenates coordMessage;
	coordMessage.x = input.x;
	coordMessage.y = input.y;
	coordMessage.z = input.z;


	bool error = false;
	switch (input.identifier)
	{
		case ROAD:
		{
			error = catan->canBuildRoad(catan->getPlayer1(), catan->getPlayer2(), coords, true); //VERIFICAR CON CARO, CAMBIOS QUE SE HICIERON EN ESTA FUNCION POR LOS PRIMEROS DOS TURNOS
			break;
		}
		case CITY:
		{
			error = catan->canBuildCity(catan->getPlayer1(), coords);
			break;
		}
		case SETTLEMENT:
		{
			error = catan->canBuildTown(catan->getPlayer1(), catan->getPlayer2(), coords, true);
			break;
		}
	}

	if (error)
	{
		GUI->showNoResource();
	}
	else
	{
		switch (input.identifier)
		{
			case ROAD:
			{
				catan->buildRoad(coords, catan->getPlayer1()); 
				if (myStatus == IM_SERVER)
				{
					COMU_s->sendRoad(coordMessage, 2);
				}
				else if (myStatus == IM_CLIENT)
				{
					COMU_c->sendRoad(coordMessage, 2);
				}
				break;
			}
			case CITY:
			{
                catan->buildCity(coords, catan->getPlayer1());
				if (myStatus == IM_SERVER)
				{
					COMU_s->sendCity(coordMessage, 3);
				}
				else if (myStatus == IM_CLIENT)
				{
					COMU_c->sendCity(coordMessage, 3);
				}
				break;
			}
			case SETTLEMENT:
			{
                catan->buildTown(coords, catan->getPlayer1());
				if (myStatus == IM_SERVER)
				{
					COMU_s->sendSettlement(coordMessage, 3);
				}
				else if (myStatus == IM_CLIENT)
				{
					COMU_c->sendSettlement(coordMessage, 3);
				}
				break;
			}
		}
	}

	if (myStatus == IM_SERVER)
	{
		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)
		{
			ackReceived = true;
		}
	}
	else if (myStatus == IM_CLIENT)
	{
		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)
		{
			ackReceived = true;
		}
	}

	GUI->showGeneralDisplay(catan->getPlayer1(), catan->getPlayer2(), catan->getMap(), true, GENERAL_MENU);

} 

//HECHO (CARO FIJATE EN CAN BUILD ROAD Y EL ORDEN DE LA INVOCACION DE LOS PLAYERS!!!!)
void FSMImplementation::verifyBuild(genericEvent * ev)// no se que onda eso del dispatcher
{
	cout << "el otro construyo algo" << endl;
	bool error = false;

	if (myStatus == IM_SERVER)
	{
		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
	}
	else if (myStatus == IM_CLIENT)
	{
		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
	}

	//Coordenadas para logica
	Coordinates coords(mensaje.x, mensaje.y, mensaje.z);

	switch (mensaje.identifier)
	{
		case ROAD:
		{
			error = !catan->canBuildRoad(catan->getPlayer2(), catan->getPlayer1(), coords, true); //VERIFICAR CON CARO, CAMBIOS QUE SE HICIERON EN ESTA FUNCION POR LOS PRIMEROS DOS TURNOS
			break;
		}
		case CITY:
		{
			error = !catan->canBuildCity(catan->getPlayer2(), coords);
			break;
		}
		case SETTLEMENT:
		{
			error = !catan->canBuildTown(catan->getPlayer2(), catan->getPlayer1(), coords, true);
			break;
		}
	}

	if (error)
	{
		//ERROR
	}
	else
	{
		switch (mensaje.identifier)
		{
			case ROAD:
			{
				catan->buildRoad(coords, catan->getPlayer2());
				if (myStatus == IM_SERVER)
				{
					COMU_s->sendAck();
				}
				else if (myStatus == IM_CLIENT)
				{
					COMU_c->sendAck();
				}
				break;
			}
			case CITY:
			{
                catan->buildCity(coords, catan->getPlayer2());
				if (myStatus == IM_SERVER)
				{
					COMU_s->sendAck();
				}
				else if (myStatus == IM_CLIENT)
				{
					COMU_c->sendAck();
				}
				break;
			}
			case SETTLEMENT:
			{
                catan->buildTown(coords, catan->getPlayer2());
				if (myStatus == IM_SERVER)
				{
					COMU_s->sendAck();
				}
				else if (myStatus == IM_CLIENT)
				{
					COMU_c->sendAck();
				}
				break;
			}
		}
	}

	GUI->showGeneralDisplay(catan->getPlayer1(), catan->getPlayer2(), catan->getMap(), false, GENERAL_MENU);
}

//HECHO
void FSMImplementation::endOfMyTurn(genericEvent * ev)
{
	cout << "termine mi turno" << endl;
	GUI->showGeneralDisplay(catan->getPlayer1(), catan->getPlayer2(), catan->getMap(), false, GENERAL_MENU);
	if (myStatus == IM_SERVER)
	{
		COMU_s->sendPass();
		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
	}
	else if (myStatus == IM_CLIENT)
	{
		COMU_c->sendPass();
		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
	}
}

void FSMImplementation::endOtherTurn(genericEvent * ev)
{
	cout << "Termino el turno del otro" << endl;
	//int dado=catan.getPlayer1()->throwDice()

	// si fue un siete pregunta al jugador a donde mover el robber? (showMoveRobber)

	//void findNumber(dado, catan.getPlayer1(), resources resources[], Coordinates coordinates); //  encuentra todas las islas que tienen el numero tirado por el dado y si el numero era un 7 se encarga de llamar a la funcion que mueve al robber
}

//HECHO
void FSMImplementation::dice(genericEvent * ev)
{
	int dado1;
	int dado2;
    dado1 = catan->getPlayer1()->throwDice();
	dado2 = catan->getPlayer1()->throwDice();
	if (myStatus == IM_SERVER)
	{
		COMU_s->sendDices(dado1, dado2);
		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)
		{
			ackReceived = true;
		}
	}
	else if (myStatus == IM_CLIENT)
	{
		COMU_c->sendDices(dado1, dado2);
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)
		{
			ackReceived = true;
		}
	}
} // player 1 tira dados

//HECHO
void FSMImplementation::victory(genericEvent * ev)
{
	cout << "gane" << endl;
	if (myStatus == IM_SERVER)
	{
		COMU_s->sendIWon();
		while (!messageExist)
		{
			messageExist = COMU_s->isMessage();
		}
		messageExist = false;
		mensaje = COMU_s->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)
		{
			GUI->showIWon();
		}
	}
	else if (myStatus == IM_CLIENT)
	{
		COMU_c->sendIWon();
		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_c->isMessage();
		}
		messageExist = false;
		mensaje = COMU_c->getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)
		{
			GUI->showIWon();
		}
	}
}

//HECHO
void FSMImplementation::victoryCheck(genericEvent * ev)
{
	cout << "gano?" << endl;
	if ((catan->getPlayer2()->getVictoryPoints()) >= 10)
	{
		if (myStatus == IM_SERVER)
		{
			COMU_s->sendAck();
		}
		else if (myStatus == IM_CLIENT)
		{
			COMU_c->sendAck();
		}	
	}
	else
	{
		//generar error
	}
}

void FSMImplementation::error(genericEvent * ev)
{
	cout << "La cagaron" << endl;
}

//HECHO, funcion que pasa los pumnteros
void FSMImplementation::setFSM(io * GUI_i, Catan * catan_i, client * COMUC_i, server * COMUS_i, int myStatus_i)
{
	GUI = GUI_i;
	catan = catan_i;
	COMU_c = COMUC_i;
	COMU_s = COMUS_i;
	myStatus = myStatus_i;
}
