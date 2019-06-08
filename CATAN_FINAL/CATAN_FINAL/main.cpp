#include <iostream>
#include "defines.h"
#include "eventHandling.h"
#include "genericFSM.h"
#include "simpleEventGenerator.h"
#include "Catan.h"
#include "Player.h"
#include "io.h"
#include "client.h"
#include "server.h"
#include "auxiliar.h"
//#include "eventHandling.h"
//#include "genericFSM.h"
//#include "simpleEventGenerator.h"
//#include "FSMImplementation.h"

int main(int argc, char** argv)
{
	// Variable de FSM
	//FSMImplementation fsm;
	//simpleEventGenerator s;
	//mainEventGenerator eventGen;
	//eventGen.attach(&s);

	// Variable de salida para finalizar el juego
	bool quit = false;

	// Interfaz
	io GUI; 
	unsigned char input;
	genIn inputInfo;
	bool errInput = false;


	// Juego basico
	Catan catan(NULL, NULL);
	bool allowToBuild = false;
	unsigned char firstTurnsCompleted = 0;
	Coordinates coordinates;
	coordenates coordMessage;

	//Dados
	int dice1;
	int dice2;

	// Defino los tiempos
	int startTime = 0;	 // Tiempo de inicio
	int elapsedTime = 5; // Tiempo ocurrido
	int randTime;	     // Tiempo arbitrario
	bool turn;
	srand(time(NULL));
	randTime = rand() % (MAX_NUMBER_TIME - MIN_NUMBER_TIME + 1) + MIN_NUMBER_TIME;

	// Variables para establecer la comunicacion
	
	bool connectionStatus = CONNECTION_DECLINE;	// Estado de la conexion
	int myStatus;				// Mi estado en la comunicacion
	bool messageExist = false;	// Flag que indica la existencia del mensaje 
	message mensaje;			// Mensaje que se recibe a la entrada
	char* ip_playerAUX;			// IP para conectarse
	char ip_player[15];
	
	//*********************************** Empiezo a conectarme **********************************

	ip_playerAUX = GUI.getMyIp();	// Intefaz para ingresar la IP

	for (int i = 0; i < 15; i++)
	{
		ip_player[i] = ip_playerAUX[i];
	}

	GUI.showTryToConnect();		// Muestro que se quiere establecer la conexion

	client COMU_c(ip_player);	// Intento conectarme como CLIENTE
	connectionStatus = COMU_c.startConnection();	//BLOQUEANTE, se queda esperando a que aparezca un server (por un tiempo)
	
	server COMU_s(ip_player); // Intento conetarme como SERVER

	if (connectionStatus == CONNECTION_SUCCESS) // Exito al conectarse como cliente
	{
		myStatus = IM_CLIENT;
	}

	else if (connectionStatus == CONNECTION_DECLINE)
	{
		connectionStatus = COMU_s.startConnection(); //BLOQUEANTE, se queda esperando a que aparezca un cliente
		if (connectionStatus == CONNECTION_SUCCESS) // Exito al conectarse como servidor
		{
			myStatus = IM_SERVER;
		}
		else if (connectionStatus == CONNECTION_DECLINE)
		{
			myStatus = NO_CONNECTION;
		}
	}

	// Para esta altura ya esta definido el estado de la comunicacion
	// SERVER, CLIENTE o NO HAY CONEXION
	//*************************************************************************************

	//**************************** Empiezo a preparar el juego ****************************

	bool ackRecived = false;
	bool ackSended = false;
	bool myNameLoad = false;
	bool otherNameLoad = false;

	// Cargo mi nombre (local)
	nameInfo nameP1;			
	nameP1 = GUI.getMyName();		// Interfaz para ingresar el nombre
	nameP1.name[nameP1.longName] = '\0';
	Player player1(nameP1.name);	// Creo mi jugador (local)
	
	myNameLoad = true;

	// Cargo el nombre del otro jugador
	char player_name2[255];
	messageExist = false;
	Player player2;

	if (myStatus == IM_SERVER)	// Si soy server ordeno el juego
	{
		// Le pido al otro jugador su nombre
		COMU_s.sendName();

		// Espero a que me responda su nombre
		while (!messageExist)
		{
			messageExist = COMU_s.isMessage();
		}
		messageExist = false;
		mensaje = COMU_s.getMessage(); //Obtengo el mensaje

		// Le respondo que recibi su mensaje (ACK)
		if (mensaje.identifier == NAME_IS)	// Si el contenido del mensje es el nombre del otro jugador...
		{
			//player_name2 = mensaje.content;	// Obtengo el nobre del otro jugador
			for (int i = 0; i < mensaje.contentLong; i++)
			{
				player_name2[i] = mensaje.content[i];
			}
			player_name2[mensaje.contentLong] = '\0';
			player2.setName(player_name2);
			COMU_s.sendAck();				// Le respondo al otro jugador que se recibio el mensaje
			otherNameLoad = true;
		}

		// Espero a que el otro jugador me pida mi nombre
		while (!messageExist)
		{
			messageExist = COMU_s.isMessage();
		}
		messageExist = false;
		mensaje = COMU_s.getMessage(); //Obtengo el mensaje

		// Le envio mi nombre al otro jugador
		if (mensaje.identifier == NAME)	// Si el contenido del mensje es el pedido de nombre...
		{
			COMU_s.sendNameIs(nameP1.longName, nameP1.name);	// Le envio mi nombre (local)
		}

		// Eespero a que el otro jugador me diga que recibio su mensaje (ACK)
		while (!messageExist)
		{
			messageExist = COMU_s.isMessage();
		}
		messageExist = false;
		mensaje = COMU_s.getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
		{
			ackRecived = true;
		}
	}
	
	else if (myStatus == IM_CLIENT)
	{
		// Espero a que me pida el nombre
		while (!messageExist)	// Espero a que el otro jugador me pida mi nombre
		{
			messageExist = COMU_c.isMessage();
		}
		messageExist = false;
		mensaje = COMU_c.getMessage();

		// Le mando mi nombre
		if (mensaje.identifier == NAME)
		{
			COMU_c.sendNameIs(nameP1.longName, nameP1.name);
			
		}

		// Espero a que me diga que recibio mi mensaje (ACK)
		while (!messageExist)
		{
			messageExist = COMU_c.isMessage();
		}
		messageExist = false;
		mensaje = COMU_c.getMessage(); //Obtengo el mensaje

		// Le pido su nombre
		if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
		{
			COMU_c.sendName();
		}

		// Espero a que me diga su nombre
		while (!messageExist)	// Espero a que el otro jugador me pida mi nombre
		{
			messageExist = COMU_c.isMessage();
		}
		messageExist = false;
		mensaje = COMU_c.getMessage();

		// Le respondo que recibi su nombre (ACK)
		if (mensaje.identifier == NAME_IS)	// Si el contenido del mensje es el nombre del otro jugador...
		{
			//player_name2 = mensaje.content;	// Obtengo el nobre del otro jugador
			for (int i = 0; i < mensaje.contentLong; i++)
			{
				player_name2[i] = mensaje.content[i];
			}
			player_name2[mensaje.contentLong] = '\0';
			player2.setName(player_name2);
			COMU_c.sendAck();				// Le respondo al otro jugador que se recibio el mensaje
			otherNameLoad = true;
			ackSended = true;
		}

	}

	// Si SOY SERVER y los nombres estan cargados, creo un mapa
	if (myNameLoad && otherNameLoad && myStatus == IM_SERVER && ackRecived)
	{
		ackRecived = false;
	
		catan.setGame(&player1, &player2);
		
		char* types = catan.getMap()->getIslandTypeArray();
		char* tokens = catan.getMap()->getIslandTokensArray();
		char* docks = catan.getMap()->getDocksArray();

		// Le envio los tipos
		COMU_s.sendMapIs(types, docks);

		// Espero a que me responda que recibio los tipos
		while (!messageExist)
		{
			messageExist = COMU_s.isMessage();
		}
		messageExist = false;
		mensaje = COMU_s.getMessage(); //Obtengo el mensaje

		// Le envio los tokens
		if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
		{
			COMU_s.sendCircularTokens(tokens);
		}

		// Espero a que me esponda que recibio los tokens
		while (!messageExist)
		{
			messageExist = COMU_s.isMessage();
		}
		messageExist = false;
		mensaje = COMU_s.getMessage(); //Obtengo el mensaje
		if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
		{
			ackRecived = true;
		}

	}

	// Si SOY CLIENTE y los nombres estan cargados, pido el mapa
	else if (myNameLoad && otherNameLoad && myStatus == IM_CLIENT && ackSended)
	{
		char types[ISLANDS_AMMOUNT];
		char tokens[ISLANDS_AMMOUNT - 1];
		char docks[DOCKS_AMMOUNT];

		// Espero a que me envie los tipos de isla
		while (!messageExist)
		{
			messageExist = COMU_c.isMessage();
		}
		messageExist = false;
		mensaje = COMU_c.getMessage(); //Obtengo el mensaje

		// Le envio que recivi los tipos de islas 
		if (mensaje.identifier == MAP_IS)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < DOCKS_AMMOUNT; i++)
			{
				docks[i] = mensaje.content[i];
			}
			for (; i < (ISLANDS_AMMOUNT + DOCKS_AMMOUNT); i++, j++)
			{
				types[j] = mensaje.content[i];
			}
			COMU_c.sendAck();
		}

		// Espero a que me envie los tokens
		while (!messageExist)
		{
			messageExist = COMU_c.isMessage();
		}
		messageExist = false;
		mensaje = COMU_c.getMessage(); //Obtengo el mensaje
	
		// Le envio que recivi los tokes
		if (mensaje.identifier == CIRCULAR_TOKENS)
		{
			for (int i = 0; i < (ISLANDS_AMMOUNT - 1); i++)
			{
				tokens[i] = mensaje.content[i];
			}
			COMU_c.sendAck();
		}

		catan.setGame(&player1, &player2, types, tokens, docks);

	}

	// Defino de forma aleatoria quien empieza
	Player * starter = &player1;
	Player * other = &player2;

	if (myStatus == IM_SERVER)
	{
		// Tiro los dados, para elegir de forma aleatoria quien empieza
		do
		{
			dice1 = player1.throwDice();
			dice2 = player2.throwDice();
		} while (dice1 == dice2);

		// El dado mas grande empieza
		if (dice2 > dice1)
		{



			COMU_s.sendYoutStart();

			// Espero a que me responda que recibio quien empieza
			while (!messageExist)
			{
				messageExist = COMU_s.isMessage();
			}
			messageExist = false;
			mensaje = COMU_s.getMessage(); //Obtengo el mensaje
			if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
			{
				ackRecived = true;
			}

			turn = YOUR_TURN_M;	//El primer turno es del otro jugador
		}
		else
		{
			COMU_s.sendIStart();

			// Espero a que me responda que recibio quien empieza
			while (!messageExist)
			{
				messageExist = COMU_s.isMessage();
			}
			messageExist = false;
			mensaje = COMU_s.getMessage(); //Obtengo el mensaje
			if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
			{
				ackRecived = true;
			}

			turn = MY_TURN_M;
		}
	}

	else if (myStatus == IM_CLIENT)
	{
		// Espero a que me diga quien empieza
		while (!messageExist)
		{
			messageExist = COMU_c.isMessage();
		}
		messageExist = false;
		mensaje = COMU_c.getMessage();

		if (mensaje.identifier == YOU_START)
		{
			turn = MY_TURN_M;
		}
		else if (mensaje.identifier == I_START)
		{
			Player * aux = starter;
			starter = other;
			other = aux;
			turn = YOUR_TURN_M;
		}

		COMU_c.sendAck();
	}

	// Para esta altura ambos jugadores tienen los juegos cargados, listos para jugar!
	//*************************************************************************************
	
	//************************ Primeros dos turnos (uno cada uno) *************************

	while (firstTurnsCompleted != 4)
	{
	    allowToBuild=false;
		if (turn == MY_TURN_M)
		{
			GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, GENERAL_MENU);
			//**************** CONSTRUYO UN SETTLEMENT (LOCAL) ****************
			do
			{
				while (GUI.isInput() != EV_EXIST);
				input = GUI.getInput();

				if (input == BUILD)
				{
					GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, BUILDING_MENU);
					inputInfo = GUI.getBuildingInput();

					coordinates.setX(inputInfo.x);
					coordinates.setY(inputInfo.y);
					coordinates.setZ(inputInfo.z);


					if (inputInfo.identifier == SETTLEMENT)
					{
						errInput = !catan.canBuildTown(catan.getPlayer1(), catan.getPlayer2(), coordinates, true);

						if (!errInput)//creo que es asi
						{
							allowToBuild = true;
						}

					}

				}

			} while (!allowToBuild);
			catan.buildTown(coordinates, catan.getPlayer1());
			GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, GENERAL_MENU);
			coordMessage.x = coordinates.getX();
			coordMessage.y = coordinates.getY();
			coordMessage.z = coordinates.getZ();

			//**************** DISTRIBUCION ****************
			if (isalpha(coordinates.getX())) {
				switch (catan.getMap()->getIslands()[toupper(coordinates.getX()) - 'A'].getType()) {
				case BOSQUE:
					catan.getPlayer1()->setWood(catan.getPlayer1()->getWood() + 1);
					break;
				case COLINA:
					catan.getPlayer1()->setClay(catan.getPlayer1()->getClay() + 1);
					break;
				case MONTANIA:
					catan.getPlayer1()->setStone(catan.getPlayer1()->getStone() + 1);
					break;
				case CAMPO:
					catan.getPlayer1()->setWheat(catan.getPlayer1()->getWheat() + 1);
					break;
				case PASTO:
					catan.getPlayer1()->setSheep(catan.getPlayer1()->getSheep() + 1);
					break;
				case DESIERTO:
					//Nada
					break;
				}
			}
			if (isalpha(coordinates.getY())) {
				switch (catan.getMap()->getIslands()[toupper(coordinates.getY()) - 'A'].getType()) {
				case BOSQUE:
					catan.getPlayer1()->setWood(catan.getPlayer1()->getWood() + 1);
					break;
				case COLINA:
					catan.getPlayer1()->setClay(catan.getPlayer1()->getClay() + 1);
					break;
				case MONTANIA:
					catan.getPlayer1()->setStone(catan.getPlayer1()->getStone() + 1);
					break;
				case CAMPO:
					catan.getPlayer1()->setWheat(catan.getPlayer1()->getWheat() + 1);
					break;
				case PASTO:
					catan.getPlayer1()->setSheep(catan.getPlayer1()->getSheep() + 1);
					break;
				case DESIERTO:
					//Nada
					break;
				}
			}
			if (isalpha(coordinates.getZ())) {
				switch (catan.getMap()->getIslands()[toupper(coordinates.getZ()) - 'A'].getType()) {
				case BOSQUE:
					catan.getPlayer1()->setWood(catan.getPlayer1()->getWood() + 1);
					break;
				case COLINA:
					catan.getPlayer1()->setClay(catan.getPlayer1()->getClay() + 1);
					break;
				case MONTANIA:
					catan.getPlayer1()->setStone(catan.getPlayer1()->getStone() + 1);
					break;
				case CAMPO:
					catan.getPlayer1()->setWheat(catan.getPlayer1()->getWheat() + 1);
					break;
				case PASTO:
					catan.getPlayer1()->setSheep(catan.getPlayer1()->getSheep() + 1);
					break;
				case DESIERTO:
					//Nada
					break;
				}
			}

			//**************** ENVIO SETTLEMENT ****************
			if (myStatus == IM_SERVER)
			{
				// Le envio el settlement
				COMU_s.sendSettlement(coordMessage, 3);

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_s.isMessage();
				}
				messageExist = false;
				mensaje = COMU_s.getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
				{
					ackRecived = true;
				}

			}
			else if (myStatus == IM_CLIENT)
			{
				// Le envio el settlement
				COMU_c.sendSettlement(coordMessage, 3);

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_c.isMessage();
				}
				messageExist = false;
				mensaje = COMU_c.getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
				{
					ackRecived = true;
				}
			}

			//**************** IMPRIMO ****************
			GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, GENERAL_MENU);

			//**************** CONTRUYO UN ROAD (LOCAL) ****************
			allowToBuild = false;
			do
			{
				while (GUI.isInput() != EV_EXIST);
				input = GUI.getInput();

				if (input == BUILD)
				{
					GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, BUILDING_MENU);
					inputInfo = GUI.getBuildingInput();

					coordinates.setX(inputInfo.x);
					coordinates.setY(inputInfo.y);
					coordinates.setZ(inputInfo.z);

					if (inputInfo.identifier == ROAD)
					{
						errInput = !catan.canBuildRoad(catan.getPlayer1(), catan.getPlayer2(), coordinates, true);

						if (!errInput)//creo que es asi
						{
							allowToBuild = true;
						}

					}

				}

			} while (!allowToBuild);
			catan.buildRoad(coordinates, catan.getPlayer1());
			GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), false, GENERAL_MENU);
			coordMessage.x = coordinates.getX();
			coordMessage.y = coordinates.getY();
			coordMessage.z = coordinates.getZ();

			//**************** ENVIO ROAD ****************
			if (myStatus == IM_SERVER)
			{
				// Le envio el settlement
				COMU_s.sendRoad(coordMessage, 3);

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_s.isMessage();
				}
				messageExist = false;
				mensaje = COMU_s.getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
				{
					ackRecived = true;
				}

			}
			else if (myStatus == IM_CLIENT)
			{
				// Le envio el settlement
				COMU_c.sendRoad(coordMessage, 3);

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_c.isMessage();
				}
				messageExist = false;
				mensaje = COMU_c.getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
				{
					ackRecived = true;
				}
			}

			//**************** IMPRIMO ****************
			GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, GENERAL_MENU);

			//**************** ENVIO EL PASE ****************
			if (myStatus == IM_SERVER)
			{
				// Le envio el settlement
				COMU_s.sendPass();

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_s.isMessage();
				}
				messageExist = false;
				mensaje = COMU_s.getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
				{
					ackRecived = true;
					turn = YOUR_TURN_M;
					firstTurnsCompleted++;
				}

			}
			else if (myStatus == IM_CLIENT)
			{
				// Le envio el settlement
				COMU_c.sendPass();

				// Espero a que me esponda que recibio los tokens
				while (!messageExist)
				{
					messageExist = COMU_c.isMessage();
				}
				messageExist = false;
				mensaje = COMU_c.getMessage(); //Obtengo el mensaje
				if (mensaje.identifier == ACK)	// Si el contenido del mensje es el ACK del otro jugador...
				{
					ackRecived = true;
					turn = YOUR_TURN_M;
					firstTurnsCompleted++;
				}
			}
			
			//**************** IMPRIMO ****************
			GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), false, GENERAL_MENU);
		}
		else if (turn == YOUR_TURN_M) {
            GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), false, GENERAL_MENU);
            //**************** RECIBO UN SETTLEMENT ****************
            errInput = false;
            allowToBuild = false;
            do {
                if (myStatus == IM_SERVER) {
                    while (!messageExist) {
                        messageExist = COMU_s.isMessage();
                    }
                    messageExist = false;
                    mensaje = COMU_s.getMessage(); //Obtengo el mensaje
                } else if (myStatus == IM_CLIENT) {
                    while (!messageExist) {
                        messageExist = COMU_c.isMessage();
                    }
                    messageExist = false;
                    mensaje = COMU_c.getMessage(); //Obtengo el mensaje
                }

                if (mensaje.identifier == SETTLEMENT)    // Si el contenido del mensje es el ACK del otro jugador...
                {
                    coordinates.setX(mensaje.x);
                    coordinates.setY(mensaje.y);
                    coordinates.setZ(mensaje.z);

                    errInput = !catan.canBuildTown(catan.getPlayer2(), catan.getPlayer1(), coordinates,
                                                   true); //hace diferencia?

                    if (!errInput) //creo que es asi
                    {
                        allowToBuild = true;
                    }
                }

            } while (!allowToBuild);
            catan.buildTown(coordinates, catan.getPlayer2());

            //**************** DISTRIBUCION ****************V
            if (isalpha(coordinates.getX())) {
                switch (catan.getMap()->getIslands()[toupper(coordinates.getX()) - 'A'].getType()) {
                    case BOSQUE:
                        catan.getPlayer2()->setWood(catan.getPlayer2()->getWood() + 1);
                        break;
                    case COLINA:
                        catan.getPlayer2()->setClay(catan.getPlayer2()->getClay() + 1);
                        break;
                    case MONTANIA:
                        catan.getPlayer2()->setStone(catan.getPlayer2()->getStone() + 1);
                        break;
                    case CAMPO:
                        catan.getPlayer2()->setWheat(catan.getPlayer2()->getWheat() + 1);
                        break;
                    case PASTO:
                        catan.getPlayer2()->setSheep(catan.getPlayer2()->getSheep() + 1);
                        break;
                    case DESIERTO:
                        //Nada
                        break;
                }
            }
            if (isalpha(coordinates.getY())) {
                switch (catan.getMap()->getIslands()[toupper(coordinates.getY()) - 'A'].getType()) {
                    case BOSQUE:
                        catan.getPlayer2()->setWood(catan.getPlayer2()->getWood() + 1);
                        break;
                    case COLINA:
                        catan.getPlayer2()->setClay(catan.getPlayer2()->getClay() + 1);
                        break;
                    case MONTANIA:
                        catan.getPlayer2()->setStone(catan.getPlayer2()->getStone() + 1);
                        break;
                    case CAMPO:
                        catan.getPlayer2()->setWheat(catan.getPlayer2()->getWheat() + 1);
                        break;
                    case PASTO:
                        catan.getPlayer2()->setSheep(catan.getPlayer2()->getSheep() + 1);
                        break;
                    case DESIERTO:
                        //Nada
                        break;
                }
            }
            if (isalpha(coordinates.getZ())) {
                switch (catan.getMap()->getIslands()[toupper(coordinates.getZ()) - 'A'].getType()) {
                    case BOSQUE:
                        catan.getPlayer2()->setWood(catan.getPlayer2()->getWood() + 1);
                        break;
                    case COLINA:
                        catan.getPlayer2()->setClay(catan.getPlayer2()->getClay() + 1);
                        break;
                    case MONTANIA:
                        catan.getPlayer2()->setStone(catan.getPlayer2()->getStone() + 1);
                        break;
                    case CAMPO:
                        catan.getPlayer2()->setWheat(catan.getPlayer2()->getWheat() + 1);
                        break;
                    case PASTO:
                        catan.getPlayer2()->setSheep(catan.getPlayer2()->getSheep() + 1);
                        break;
                    case DESIERTO:
                        //Nada
                        break;
                }
            }

            //**************** ENVIO ACK ****************
            if (myStatus == IM_SERVER) {
                COMU_s.sendAck();
            } else if (myStatus == IM_CLIENT) {
                COMU_c.sendAck();
            }

            GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), false, GENERAL_MENU);

            //**************** RECIBO UN ROAD ****************
            errInput = false;
            allowToBuild = false;
            do {
                if (myStatus == IM_SERVER) {
                    while (!messageExist) {
                        messageExist = COMU_s.isMessage();
                    }
                    messageExist = false;
                    mensaje = COMU_s.getMessage(); //Obtengo el mensaje
                } else if (myStatus == IM_CLIENT) {
                    while (!messageExist) {
                        messageExist = COMU_c.isMessage();
                    }
                    messageExist = false;
                    mensaje = COMU_c.getMessage(); //Obtengo el mensaje
                }

                if (mensaje.identifier == ROAD)    // Si el contenido del mensje es el ACK del otro jugador...
                {
                    coordinates.setX(mensaje.x);
                    coordinates.setY(mensaje.y);
                    coordinates.setZ(mensaje.z);

                    errInput = !catan.canBuildRoad(catan.getPlayer2(), catan.getPlayer1(), coordinates, true);

                    if (!errInput)//creo que es asi
                    {
                        allowToBuild = true;
                    }
                }

            } while (!allowToBuild);
            catan.buildRoad(coordinates, catan.getPlayer2());

            //**************** ENVIO ACK ****************
            if (myStatus == IM_SERVER) {
                COMU_s.sendAck();
            } else if (myStatus == IM_CLIENT) {
                COMU_c.sendAck();
            }

            //**************** IMPRIMO ****************
            GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), false, GENERAL_MENU);

            //**************** RECIBO EL PASS ****************
            if (myStatus == IM_SERVER) {
                while (!messageExist) {
                    messageExist = COMU_s.isMessage();
                }
                messageExist = false;
                mensaje = COMU_s.getMessage(); //Obtengo el mensaje
                COMU_s.sendAck();
            } else if (myStatus == IM_CLIENT) {
                while (!messageExist) {
                    messageExist = COMU_c.isMessage();
                }
                messageExist = false;
                mensaje = COMU_c.getMessage(); //Obtengo el mensaje
                COMU_c.sendAck();
            }
            if (mensaje.identifier == PASS) {

                turn = MY_TURN_M;
                firstTurnsCompleted++;
            }

            //**************** IMPRIMO ****************
            GUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, GENERAL_MENU);

        }

		if(firstTurnsCompleted == 2) {
            if (turn == MY_TURN_M)
                turn = YOUR_TURN_M;
            else
                turn = MY_TURN_M;
        }
	}

	// Ya se completaron los primeros turnos de cada jugador
	//*************************************************************************************

	////FSM
	//do
	//{
	//	//if(askClick)
	//	//generateClickEvent;
	//	//if(askMessage)
	//	//generateMessageEvent;


	//	genericEvent * ev;
	//	ev = eventGen.getNextEvent();
	//	if (ev->getType() == EventQuit)
	//	{
	//		quit = true;
	//		delete ev;
	//	}
	//	else
	//		fsm.cycle(ev);
	//} while (!quit);

	//system("pause");
	return 0;
}











//Player player1("Ignacio"); //insert name
//Player player2("Carola"); //pide el nombre de la otra computadora

//player1.setTownsBuilt(3);

//player1.setSheep(3);
//player1.setStone(3);
//player1.setWheat(3);
//player1.setWood(3);
//player1.setClay(3);

//player2.setSheep(3);
//player2.setStone(3);
//player2.setWheat(3);
//player2.setWood(3);
//player2.setClay(3);

//char types[MAP_ITEMS_NUMBER]; //recibo el array de types
//char number[ISLANDS_AMMOUNT]; //recibo el array de circular tokens

//unsigned char input;

////genIn mensaje;

////Catan catan(&player1, &player2, types, number); //CLIENTE

//Catan catan(&player1, &player2); //SERVER

//io AllGUI;

////AllGUI.showGeneralDisplay(catan.getPlayer1(), catan.getPlayer2(), catan.getMap(), true, GENERAL_MENU);
//	
//return 0;
