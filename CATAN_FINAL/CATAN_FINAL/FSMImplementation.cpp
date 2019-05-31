//#include "FSMImplementation.h"
//
//void FSMImplementation::noAction(genericEvent * ev)
//{
//	cout << "no puedo recibir eso master" << endl;
//	return;
//}
//void FSMImplementation::askTrade(genericEvent * ev)
//{
//	int wood, clay, sheep, wheat, stone;
//	wood = catan.getPlayer1()->getWood();
//	clay = catan.getPlayer1()->getClay();
//	sheep = catan.getPlayer1()->getSheep();
//	wheat = catan.getPlayer1()->getWheat();
//	stone = catan.getPlayer1()->getStone();
//
//	tradeIn doy, quiero;
//
//	doy = AllGUI.getTradeInfo(wood, sheep, stone, clay, wheat, 0);//flag es 0 para ofrecer
//
//	quiero = AllGUI.getTradeInfo(9, 9, 9, 9, 9, 1); //flag es 1 para pedir
//		
//	
//	//sendOfferTrade(doy, quiero);
//	//message mensaje;
//	//mensaje = getMessage(void); //message es estructura esta en comu 
//
//	//if (mensaje.identifier == YES)//Acepto
//	//{
//	//	ValidTrade(give[], request[], catan.getPlayer1(), catan.getPlayer2()); // esto ya lo redistribuye( esta en catan.h)
//	//	void showAnswer(1)
//	//}
//	//else
//	//{
//	//	void showAnswer(0);
//	//}
//	return;
//}
//void FSMImplementation::answering(genericEvent * ev)// al final con los informes hay algo que no entendi
//{
//	cout << "tradeas?" << endl;
//
//	int woodG = 0, clayG = 0, sheepG = 0, wheatG = 0, stoneG = 0;
//	int woodR = 0, clayR = 0, sheepR = 0, wheatR = 0, stoneR = 0;
//
//	tradeIn trade1, trade2;
//
//	trade1.wood = catan.getPlayer1()->getWood();
//	trade1.sheep = catan.getPlayer1()->getSheep();
//	trade1.wheat = catan.getPlayer1()->getWheat();
//	trade1.clay = catan.getPlayer1()->getClay();
//	trade1.stone = catan.getPlayer1()->getStone();
//
//	trade2.wood = catan.getPlayer2()->getWood();
//	trade2.sheep = catan.getPlayer2()->getSheep();
//	trade2.wheat = catan.getPlayer2()->getWheat();
//	trade2.clay = catan.getPlayer2()->getClay();
//	trade2.stone = catan.getPlayer2()->getStone();
//
//	AllGUI.showYN(trade1, trade2);//muestro 
//	char myanswer;
//	myanswer = AllGUI.getYN();//obtengo respuesta
//
//	if (myanswer == YES)//yes
//	{
//
//		bool puedo = catan.canTrade(trade1, trade2, catan.getPlayer1(), catan.getPlayer2());
//		if (puedo)
//		{
//			catan.ValidTrade(trade1, trade2, catan.getPlayer1(), catan.getPlayer2());
//			//sendYes
//		}
//		else
//		{
//			//sendNo
//		}
//	}
//	else
//	{
//		//sendNo
//	}
//
//	return;
//}
//void FSMImplementation::bankTrade(genericEvent * ev)
//{
//	cout << "banktrade" << endl;
//	int wood, clay, sheep, wheat, stone;
//
//	((catan.getPlayer1()->getWood()) >= 1) ? wood = 1 : wood = 0;
//	((catan.getPlayer1()->getClay()) >= 1) ? clay = 1 : clay = 0;
//	((catan.getPlayer1()->getSheep()) >= 1) ? sheep = 1 : sheep = 0;
//	((catan.getPlayer1()->getWheat()) >= 1) ? wheat = 1 : wheat = 0;
//	((catan.getPlayer1()->getStone()) >= 1) ? stone = 1 : stone = 0;
//
//	tradeIn doy, quiero;
//	int suma, aux = 1;
//	while (aux)
//	{
//		doy = getTradeInfo(wood, sheep, stone, clay, wheat, 0); //Te devuelve lo que ofrece y lo que pide.
//		suma = ((doy.wood) + (doy.wheat) + (doy.stone) + (doy.clay) + (doy.sheep))
//			if (suma == 1 || suma == 0)
//			{
//				aux = 0;
//			}
//			else
//			{
//				aux = 1;
//			}
//	}
//	void FSMImplementation::checkBank(genericEvent * ev)
//	{
//	}
//	if (suma)
//	{
//		aux = 1;
//		while (aux)
//		{
//			quiero = getTradeInfo(1, 1, 1, 1, 1, 1); //Te devuelve lo que ofrece y lo que pide.
//			suma = ((quiero.wood) + (quiero.wheat) + (quiero.stone) + (quiero.clay) + (quiero.sheep))
//				if (suma == 1 || suma == 0)
//				{
//					aux = 0;
//				}
//				else
//				{
//					aux = 1;
//				}
//		}
//
//	}
//	else
//	{
//		//avisar que cancelo el trade?
//	}
//	if (suma)
//	{
//		resources misResources[5]
//			resources bancoDa;
//		error positivo;
//		if (doy.stone == 1)
//		{
//			for (int i = 0; i == 3; i++)
//			{
//				misResources[i] = STONE;
//			}
//		}
//		if (doy.wheat == 1)
//		{
//			for (int i = 0; i == 3; i++)
//			{
//				misResources[i] = WHEAT;
//			}
//		}
//		if (doy.clay == 1)
//		{
//			for (int i = 0; i == 3; i++)
//			{
//				misResources[i] = CLAY;
//			}
//		}
//		if (doy.sheep == 1)
//		{
//			for (int i = 0; i == 3; i++)
//			{
//				misResources[i] = SHEEP;
//			}
//		}
//		if (doy.wood == 1)
//		{
//			for (int i = 0; i == 3; i++)
//			{
//				misResources[i] = WOOD;
//			}
//		}
//		misResources[4] = END;
//		if (quiero.stone == 1)
//		{
//			bancoDa = STONE;
//		}
//		if (quiero.wheat == 1)
//		{
//			bancoDa = WHEAT;
//		}
//		if (quiero.clay == 1)
//		{
//			bancoDa = CLAY;
//		}
//		if (quiero.sheep == 1)
//		{
//			bancoDa = SHEEP;
//		}
//		if (quiero.wood == 1)
//		{
//			bancoDa = WOOD;
//		}
//		positivo = catan.tradeBank(misResources, bancoDa, catan.getPlayer1());// acordarse de poner el END final(aca esta tanto la logica que hace el trade y la que redistribuye los recursos)
//
//		if (positivo == NO_ERROR)
//		{
//			sendBankTrade(/*unsigned char cantSources, const char* offerSources, unsigned char giveSource */) // de server.h o client.h
//		//show enough?
//		}
//		else
//		{
//			void showDontEnough(void) //avisa que no podes tradear
//		}
//	}
//	else
//	{
//		//avisar que cancelo el trade?
//	}
//	return;
//}
//void FSMImplementation::checkBank(genericEvent * ev)
//{
//	cout << "el otro tradeo con el banco" << endl;
//	int woodG = 0, clayG = 0, sheepG = 0, wheatG = 0, stoneG = 0;
//	int woodR = 0, clayR = 0, sheepR = 0, wheatR = 0, stoneR = 0;
//
//	message mensaje;
//	mensaje = getMessage(void);//recibo info del trade
//	resource misResources[5];
//	resources bancoDa;
//
//	int i = 0;
//	for (i; i == mensaje.contentLong; i++)
//	{
//		switch (mensaje.content[i])
//		{
//		case STONE:
//		{
//			resources[i] = STONE;
//			break;
//		}
//		case WHEAT:
//		{
//			resources[i] = WHEAT;
//			break;
//		}
//		case WOOD:
//		{
//			resources[i] = WOOD;
//			break;
//		}
//		case SHEEP:
//		{
//			resources[i] = SHEEP;
//			break;
//		}
//		case CLAY:
//		{
//			resources[i] = CLAY;
//			break;
//		}
//		}
//	}
//	for (i = 0; i == mensaje.contentLongBIS; i++)
//	{
//		switch (mensaje.contentBIS[i])
//		{
//		case STONE:
//		{
//			bancoDa = STONE;
//			break;
//		}
//		case WHEAT:
//		{
//			bancoDa = WHEAT;
//			break;
//		}
//		case WOOD:
//		{
//			bancoDa = WOOD;
//			break;
//		}
//		case SHEEP:
//		{
//			bancoDa = SHEEP;
//			break;
//		}
//		case CLAY:
//		{
//			bancoDa = CLAY;
//			break;
//		}
//		}
//	}
//
//	error puedo = catan.tradeBank(misResources, bancoDa, catan.getPlayer2());
//	if (puedo == NO_ERROR)
//	{
//		//aviso trade
//	}
//	else
//	{
//		//generar error
//	}
//	return;
//}
//void FSMImplementation::portTrade(genericEvent * ev)
//{
//	cout << "port trade" << endl;
//
//	int wood, clay, sheep, wheat, stone;
//	wood = catan.getPlayer1()->getWood();
//	clay = catan.getPlayer1()->getClay();
//	sheep = catan.getPlayer1()->getSheep();
//	wheat = catan.getPlayer1()->getWheat();
//	stone = catan.getPlayer1()->getStone();
//
//	//Que puerto fue?**********************************************************************************
//
//	//tradeDock(resources give[], resources take, Dock dock, Player * player)
//
//	//Checkear que pueda acceder a ese puerto?**********************************************************
//
//	/*if (positivo)
//	{
//	//sendPortTrade() // de server.h o client.h ????????????????????????????????????????????????????????
//	//show enough?
//	}
//	else
//	{
//	void showDontEnough(void) //avisa que no podes tradear
//	}*/
//
//	return;
//}
//void FSMImplementation::checkPort(genericEvent * ev)
//{
//	cout << "el otro tradeo con el puerto" << endl;
//	//message getMessage(void)
//
//	//catan.tradePort(resources[5] misResources, resources quiero, catan.getPlayer2());
//	//agregar if si e if no
//
//	//Faltaria informar via allegro que se hizo el trade
//
//	return;
//}
//void FSMImplementation::building(genericEvent * ev)
//{
//
//	cout << "construi algo" << endl;
//	//genIn getInput(void) //esperara a que cuty haga el menu
//
//	//traducir coordenadas
//	mesagge mensaje;
//	bool error;
//	error error2;
//	switch (mensaje.identifier)
//	{
//	case ROAD:
//	{
//		error = canBuildRoad(catan.getPlayer1(), catan.getPlayer2(), Coordinates);
//	}
//	case CITY:
//	{
//		error = canBuildCity(catan.getPlayer1(), Coordinates);
//	}
//	case SETTLEMENT:
//	{
//		error = canBuildTown(catan.getPlayer1(), catan.getPlayer2(), Coordinates, 0);
//	}
//	}
//
//	if (error)
//	{
//		//void showNoResource (void) (por ahora seria que no se puede hacer)
//	}
//	else
//	{
//		switch (mensaje.identifier)
//		{
//		case ROAD:
//		{
//			error2 = buildRoad(Coordinates Coordinates, Player * player);
//		}
//		case CITY:
//		{
//			error2 = buildCity(Coordinates Coordinates, Player * player);
//		}
//		case SETTLEMENT:
//		{
//			error2 = buildTown(Coordinates Coordinates, Player * player);
//		}
//		}
//		if (error2 = NO_ERROR)
//		{
//			switch (mensaje.identifier)
//			{
//			case ROAD:
//			{
//				sendRoad(coordenates coord, unsigned int coordQuant);
//			}
//			case CITY:
//			{
//				sendCity(coordenates coord, unsigned int coordQuant);
//			}
//			case SETTLEMENT:
//			{
//				sendSettlement(coordenates coord, unsigned int coordQuant);
//			}
//			}
//			message mensaje2;
//			mensaje2 = getMessage(void);
//			if (mensaje2.identifier != ACK)
//			{
//				//generar error
//			}
//		}
//		else
//		{
//			//avisar error, aunque esas funciones no generan error, se reserva lugar para posibles modificaciones
//		}
//	}
//
//	//actualizo display
//
//	return;
//}
//void FSMImplementation::verifyBuild(genericEvent * ev)
//{
//	cout << "el otro construyo algo" << endl;
//	//message getMessage(void)
//
//	//bool canBuildTown(Player *, Player *, Coordinates, bool);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo (bool en true si es el primer turno)
//	//bool canBuildCity(Player *, Coordinates); //idem pero sin bool
//	//bool canBuildRoad(Player *, Player*, Coordinates); //idem DEPENDE DEL BUILDING QUE QUIERA HACER CUAL LLAMO
//
//	//if (puede)
//	//{
//	//error buildTown(Coordinates Coordinates, Player * player); // construye un town, recibe el player que quiere construirla y donde quiere construirla, devuelve si hubo algun error en el proceso
//	//error buildCity(Coordinates Coordinates, Player * player); // se fija si hay una town en coordinates, de ser asi construye una city y les saca los recursos al player (ojo! canBuildCity se fija si tiene esos recursos) 
//	//error buildRoad(Coordinates Coordinates, Player * player); // construye una road y da el longestRoad si es correcto que esto pase 
//
//	// actualizo display
//
//	//	void sendAck(void)
//	// }
//	//else
//	//{
//	//	generar error
//	//no respondo nada, el otro se da cuenta por un time out
//	//}
//	return;
//}
//void FSMImplementation::endOfMyTurn(genericEvent * ev)
//{
//	cout << "termine mi turno" << endl;
//	void showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), *Map, Turno(false))
//		sendPass();
//	return;
//}
//void FSMImplementation::endOtherTurn(genericEvent * ev)
//{
//	cout << "Termino el turno del otro" << endl;
//	//int dado=catan.getPlayer1()->throwDice()
//
//	// si fue un siete pregunta al jugador a donde mover el robber? (showMoveRobber)
//
//	//void findNumber(dado, catan.getPlayer1(), resources resources[], Coordinates coordinates); //  encuentra todas las islas que tienen el numero tirado por el dado y si el numero era un 7 se encarga de llamar a la funcion que mueve al robber
//
//	//void sendDices (int dice1, int dice2)
//	return;
//}
//void FSMImplementation::dice(genericEvent * ev)
//{
//	cout << "dados" << endl;
//	return;
//}
//void FSMImplementation::victory(genericEvent * ev)
//{
//	cout << "gane" << endl;
//	void sendIWon(void);
//	message mensaje;
//
//	mensaje = getMessage(void);
//
//	if (mensaje.identifier == ACK)
//	{
//		void showIWon(void);
//		//generar quit
//	}
//	else
//	{
//		//generar error
//	}
//
//	return;
//}
//void FSMImplementation::victoryCheck(genericEvent * ev)
//{
//	cout << "gano?" << endl;
//	if ((catan.getPlayer2()->getVictoryPoints()) >= 10)
//	{
//		void sendAck(void)
//			void showILose(void)
//	}
//	else
//	{
//		//generar error
//	}
//	return;
//}
//void FSMImplementation::error(genericEvent * ev)
//{
//	cout << "La cagaron" << endl;
//	return;
//}