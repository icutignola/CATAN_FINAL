#include "FSMImplementation.h"

void FSMImplementation::noAction(genericEvent * ev)
{
	cout << "no puedo recibir eso master" << endl;
	return;
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
			catan->ValidTrade(doy, quiero, catan->getPlayer1(), catan->getPlayer2()); // esto ya lo redistribuye( esta en catan.h)
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
			catan->ValidTrade(doy, quiero, catan->getPlayer1(), catan->getPlayer2()); // esto ya lo redistribuye( esta en catan.h)
			GUI->showAnswer(1);
		}
		else if (mensaje.identifier == NO)
		{
			COMU_c->sendAck();
			GUI->showAnswer(0);
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

	char myanswer;
	myanswer = GUI->getYN();
	if (myanswer == YES)
	{

		bool puedo = catan->canTrade(trade1, trade2, catan->getPlayer1(), catan->getPlayer2());
		if (puedo)
		{
			catan->ValidTrade(trade1, trade2, catan->getPlayer1(), catan->getPlayer2());
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
					ackRecived = true;
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
					ackRecived = true;
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
					ackRecived = true;
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
					ackRecived = true;
				}
			}
		}
	}
	else if(myanswer == NO)
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
				ackRecived = true;
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
				ackRecived = true;
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
	catan->tradeBank(trade.give, trade.recive, catan->getPlayer1()); //No deberia checkear si se puede hacer el trade antes?

	if (myStatus == IM_SERVER)
	{
		COMU_s->sendBankTrade(trade.give, trade.recive, 4);

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
		COMU_c->sendBankTrade(trade.give, trade.recive, 4);

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
			GUI->showAnswer(1);
		}
		else if (mensaje.identifier == NO)
		{
			COMU_c->sendAck();
			GUI->showAnswer(0);
		}
	}

	
}

void FSMImplementation::checkBank(genericEvent * ev)
{
	cout << "el otro tradeo con el banco" << endl;
	int woodG = 0, clayG = 0, sheepG = 0, wheatG = 0, stoneG = 0;
	int woodR = 0, clayR = 0, sheepR = 0, wheatR = 0, stoneR = 0;

	message mensaje;
	mensaje = getMessage(void);//recibo info del trade
	resource misResources[5];
	resources bancoDa;

	int i = 0;
	for (i; i == mensaje.contentLong; i++)
	{
		switch (mensaje.content[i])
		{
		case STONE:
		{
			resources[i] = STONE;
			break;
		}
		case WHEAT:
		{
			resources[i] = WHEAT;
			break;
		}
		case WOOD:
		{
			resources[i] = WOOD;
			break;
		}
		case SHEEP:
		{
			resources[i] = SHEEP;
			break;
		}
		case CLAY:
		{
			resources[i] = CLAY;
			break;
		}
		}
	}
	for (i = 0; i == mensaje.contentLongBIS; i++)
	{
		switch (mensaje.contentBIS[i])
		{
		case STONE:
		{
			bancoDa = STONE;
			break;
		}
		case WHEAT:
		{
			bancoDa = WHEAT;
			break;
		}
		case WOOD:
		{
			bancoDa = WOOD;
			break;
		}
		case SHEEP:
		{
			bancoDa = SHEEP;
			break;
		}
		case CLAY:
		{
			bancoDa = CLAY;
			break;
		}
		}
	}

	error puedo = catan.tradeBank(misResources, bancoDa, catan.getPlayer2());
	if (puedo == NO_ERROR)
	{
		//aviso trade
	}
	else
	{
		//generar error
	}
	return;
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

	return;
}

void FSMImplementation::checkPort(genericEvent * ev)
{
	cout << "el otro tradeo con el puerto" << endl;
	//message getMessage(void)

	//catan.tradePort(resources[5] misResources, resources quiero, catan.getPlayer2());
	//agregar if si e if no

	//Faltaria informar via allegro que se hizo el trade

	return;
}

//HECHO
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
			error = catan->canBuildRoad(catan->getPlayer1(), catan->getPlayer2(), coords); //VERIFICAR CON CARO, CAMBIOS QUE SE HICIERON EN ESTA FUNCION POR LOS PRIMEROS DOS TURNOS
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

	if (error != NO_ERROR_t)
	{
		GUI->showNoResource();
	}
	else if (error == NO_ERROR_t)
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
			ackRecived = true;
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
			ackRecived = true;
		}
	}

	GUI->showGeneralDisplay(catan->getPlayer1(), catan->getPlayer2(), catan->getMap(), true, GENERAL_MENU);

} 

void FSMImplementation::verifyBuild(genericEvent * ev)// no se que onda eso del dispatcher
{
	cout << "el otro construyo algo" << endl;
	//message getMessage(void)

	//bool canBuildTown(Player *, Player *, Coordinates, bool);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo (bool en true si es el primer turno)
	//bool canBuildCity(Player *, Coordinates); //idem pero sin bool
	//bool canBuildRoad(Player *, Player*, Coordinates); //idem DEPENDE DEL BUILDING QUE QUIERA HACER CUAL LLAMO

	//if (puede)
	//{
	//error buildTown(Coordinates Coordinates, Player * player); // construye un town, recibe el player que quiere construirla y donde quiere construirla, devuelve si hubo algun error en el proceso
	//error buildCity(Coordinates Coordinates, Player * player); // se fija si hay una town en coordinates, de ser asi construye una city y les saca los recursos al player (ojo! canBuildCity se fija si tiene esos recursos) 
	//error buildRoad(Coordinates Coordinates, Player * player); // construye una road y da el longestRoad si es correcto que esto pase 

	// actualizo display

	//	void sendAck(void)
	// }
	//else
	//{
	//	generar error
	//no respondo nada, el otro se da cuenta por un time out
	//}
	return;
}

void FSMImplementation::endOfMyTurn(genericEvent * ev)
{
	cout << "termine mi turno" << endl;
	GUI->showGeneralDisplay(catan->getPlayer1(), catan->getPlayer2(), catan->getMap(), true, GENERAL_MENU);
	//sendPass();
	return;
}

void FSMImplementation::endOtherTurn(genericEvent * ev)
{
	cout << "Termino el turno del otro" << endl;
	//int dado=catan.getPlayer1()->throwDice()

	// si fue un siete pregunta al jugador a donde mover el robber? (showMoveRobber)

	//void findNumber(dado, catan.getPlayer1(), resources resources[], Coordinates coordinates); //  encuentra todas las islas que tienen el numero tirado por el dado y si el numero era un 7 se encarga de llamar a la funcion que mueve al robber

	//void sendDices (int dice1, int dice2)
	return;
}

//hecho
void FSMImplementation::dice(genericEvent * ev)
{
    catan->getPlayer1()->throwDice();
	cout << "dados" << endl;
	return;
} // player 1 tira dados

void FSMImplementation::victory(genericEvent * ev)
{
	cout << "gane" << endl;
	void sendIWon(void);
	message mensaje;

	mensaje = getMessage(void);

	if (mensaje.identifier == ACK)
	{
		void showIWon(void);
		//generar quit
	}
	else
	{
		//generar error
	}

	return;
}

//hecho
void FSMImplementation::victoryCheck(genericEvent * ev)
{
	cout << "gano?" << endl;
	if ((catan->getPlayer2()->getVictoryPoints()) >= 10)
	{
		void sendAck(void)
			void showILose(void)
	}
	else
	{
		//generar error
	}
	return;
}

void FSMImplementation::error(genericEvent * ev)
{
	cout << "La cagaron" << endl;
	return;
}