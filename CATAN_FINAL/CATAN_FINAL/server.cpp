#include "server.h"
using namespace std;

//******************************  Constructor server  ******************************************
server::server(const char *ip)
{
	strcpy(ipReceived, ip);
	IO_handler = new boost::asio::io_service();
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::tcp::v4(), HELLO_PORT);
	socketServer = new boost::asio::ip::tcp::socket(*IO_handler);				//Crea un socket vacio
	server_acceptor = new boost::asio::ip::tcp::acceptor(*IO_handler, ep);
}
//**********************************************************************************************

//******************************  startConection  **********************************************
bool server::startConnection()
{
	bool answer = CONNECTION_SUCCESS;
	//server_acceptor->non_blocking(true);
	boost::system::error_code errConnect;

	//El server se queda "observando" si alguien se conecto
	do
	{
		server_acceptor->accept(*socketServer, errConnect);	//Si alguien se conecto lo cargo en socket

	} while ((errConnect.value() == WSAEWOULDBLOCK));
	if (errConnect)
	{
		errorConnection.setErrorNumber(errServerConnect);
		string errorMessage;
		string portS = HELLO_PORT_STR;
		errorMessage = "Error mientras se intento conectar el server" + portS;
		errorConnection.setErrorDescription(errorMessage);
		answer = CONNECTION_DECLINE;
	}
	socketServer->non_blocking(true);

	return answer;
}
//*********************************************************************************************

//********************************  recivedMessage  *******************************************
bool server::receiveMessage()
{
	boost::system::error_code errRecived;
	bool answer = true;
	lenInputMessage = 0;

	do
	{
		// Se lee el socket, se carga la informacion en messeageRecived y se carga el largo del mensaje
		lenInputMessage = socketServer->read_some(boost::asio::buffer(inputMessage), errRecived);

		if (!errRecived)
		{
			inputMessage[lenInputMessage] = '\0';
		}

	} while (errRecived.value() == WSAEWOULDBLOCK);

	if (errRecived)
	{

		errorReceived.setErrorNumber(errServerSend);
		string errorDescription = "Error mientras se intento cargar el mensaje";
		errorReceived.setErrorDescription(errorDescription);
		answer = false;
	}

	return answer;
}
//**********************************************************************************************

//*****************************  send Message  *************************************************
void server::sendMessage()
{
	unsigned int len;
	boost::system::error_code errSend;

	do
	{
		len = socketServer->write_some(boost::asio::buffer(outputMessage, strlen(outputMessage)), errSend);

	} while ((errSend.value() == WSAEWOULDBLOCK));

	if (errSend)
	{
		errorSend.setErrorNumber(errClientSend);
		string description = "Hubo un error a la hora de enviar el mensaje del server al puerto";
		errorSend.setErrorDescription(description);
	}
}
//**********************************************************************************************

//*****************************  send Name  ****************************************************
void server::sendName(void)
{
	outputMessage[0] = NAME;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Dices  ***************************************************
void server::sendDices(unsigned int dice1, unsigned int dice2)
{
	outputMessage[0] = DICES_ARE;
	outputMessage[1] = dice1;
	outputMessage[2] = dice2;
	sendMessage();

}
//**********************************************************************************************

//*****************************  send Name is  *************************************************
void server::sendNameIs(unsigned char lcount, const char * name)
{
	outputMessage[0] = NAME_IS;					//Paquete
	outputMessage[1] = lcount;					//Contador
	for (int i = 0; i < lcount; i++)			//Nombre
	{
		outputMessage[2 + i] = name[i];
	}
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Ack  *****************************************************
void server::sendAck(void)
{
	outputMessage[0] = ACK;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Yes  *****************************************************
void server::sendYes(void)
{
	outputMessage[0] = YES;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send No  *****************************************************
void server::sendNo(void)
{
	outputMessage[0] = NO;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send I Won  ***************************************************
void server::sendIWon(void)
{
	outputMessage[0] = I_WON;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Play Again  **********************************************
void server::sendPlayAgain(void)
{
	outputMessage[0] = PLAY_AGAIN;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Game Over   **********************************************
void server::sendGameOver(void)
{
	outputMessage[0] = GAME_OVER;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send ERROR  ***************************************************
void server::sendError(void)
{
	outputMessage[0] = ERROR;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Quit  *****************************************************
void server::sendQuit(void)
{
	outputMessage[0] = QUIT;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Map is  **************************************************
void server::sendMapIs(char arr[ISLANDS_AMMOUNT], char docks[DOCKS_AMMOUNT])
{
	outputMessage[0] = MAP_IS;
	int i = 0;
	int j = 0;
	for (i = 0; i < DOCKS_AMMOUNT; i++)
	{
		outputMessage[1 + i] = docks[i];

	}
	for (; i < (ISLANDS_AMMOUNT+DOCKS_AMMOUNT); i++, j++)
	{
		outputMessage[1 + i] = arr[j];
	}

	sendMessage();
}
//**********************************************************************************************

//*****************************  send CircularTokens  ******************************************
void server::sendCircularTokens(char arr[MAX_NUMBER_TOKENS])
{
	outputMessage[0] = CIRCULAR_TOKENS;
	for (int i = 0; i < MAX_NUMBER_TOKENS; i++)
	{
		outputMessage[1 + i] = arr[i];
	}
	sendMessage();
}
//**********************************************************************************************

//*****************************  send RobberCards  *********************************************
void server::sendRobberCards(unsigned int ncard, const char * arr)
{
	outputMessage[0] = MAP_IS;
	outputMessage[1] = ncard;
	for (int i = 0; i < ncard; i++)
	{
		outputMessage[2 + i] = arr[i];
	}

	sendMessage();
}
//**********************************************************************************************

//*****************************  send RobberMove  **********************************************
void server::sendRobberMove(unsigned char terrain)	//terrain es la coordenada dosne mover el robber(A,B,C,...,S)
{
	outputMessage[0] = ROBBER_MOVE;
	outputMessage[1] = terrain;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Settlement  *********************************************
void server::sendSettlement(coordenates coord, unsigned int coordQuant)
{
	outputMessage[0] = SETTLEMENT;
	if (coordQuant == 2)
	{
		outputMessage[1] = coordQuant;
		outputMessage[2] = coord.x;
		outputMessage[3] = coord.y;
	}
	else if (coordQuant == 3)
	{
		outputMessage[1] = coordQuant;
		outputMessage[2] = coord.x;
		outputMessage[3] = coord.y;
		outputMessage[4] = coord.z;
	}
	sendMessage();
}
//**********************************************************************************************

//*********************************  send Road  ************************************************
void server::sendRoad(coordenates coord, unsigned int coordQuant)
{
	outputMessage[0] = ROAD;
	if (coordQuant == 2)
	{
		outputMessage[1] = coordQuant;
		outputMessage[2] = coord.x;
		outputMessage[3] = coord.y;
	}
	else if (coordQuant == 3)
	{
		outputMessage[1] = coordQuant;
		outputMessage[2] = coord.x;
		outputMessage[3] = coord.y;
		outputMessage[4] = coord.z;
	}
	sendMessage();

}
//**********************************************************************************************

//*********************************  send City  ************************************************
void server::sendCity(coordenates coord, unsigned int coordQuant)
{
	outputMessage[0] = CITY;
	if (coordQuant == 2)
	{
		outputMessage[1] = coordQuant;
		outputMessage[2] = coord.x;
		outputMessage[3] = coord.y;
	}
	else if (coordQuant == 3)
	{
		outputMessage[1] = coordQuant;
		outputMessage[2] = coord.x;
		outputMessage[3] = coord.y;
		outputMessage[4] = coord.z;
	}
	sendMessage();
}
//**********************************************************************************************

//*****************************  send You Start  ***********************************************
void server::sendYoutStart(void)
{
	outputMessage[0] = YOU_START;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send I Start  *************************************************
void server::sendIStart(void)
{
	outputMessage[0] = I_START;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Bank Trade  **********************************************
void server::sendBankTrade(unsigned char offerSource, unsigned char reciveSource, unsigned char cantSources)
{

	//Identificador
	outputMessage[0] = BANK_TRADE;

	//Cantidad de recursos
	outputMessage[1] = cantSources;

	//Recursos que le da al banco
	int i;
	for (i = 0; i < cantSources; i++)
	{
		outputMessage[1 + i] = offerSource;
	}

	//Recursos que receive del banco
	outputMessage[i] = reciveSource;

	sendMessage();
}
//**********************************************************************************************

//*****************************  send Offer Trade  *********************************************
void server::sendOfferTrade(tradeIn myRes, tradeIn yourRes)
{
	int myCant = (myRes.clay + myRes.sheep + myRes.stone + myRes.wheat + myRes.wood);
	int yourCant = (yourRes.clay + yourRes.sheep + yourRes.stone + yourRes.wheat + yourRes.wood);

	// Identificador
	outputMessage[0] = OFFER_TRADE;

	// Cantidades
	outputMessage[1] = myCant;
	outputMessage[2] = yourCant;


	// Recursos que ofreces (myRes)

	int i = 0;

	if (myRes.clay != 0)
	{
		for (; i <= myRes.clay; i++)
		{
			outputMessage[3 + i] = CLAY;
		}

	}

	if (myRes.sheep != 0)
	{
		for (; i <= myRes.sheep; i++)
		{
			outputMessage[3 + i] = SHEEP;
		}

	}

	if (myRes.stone != 0)
	{
		for (; i <= myRes.stone; i++)
		{
			outputMessage[3 + i] = STONE;
		}

	}

	if (myRes.wheat != 0)
	{
		for (; i <= myRes.wheat; i++)
		{
			outputMessage[3 + i] = WHEAT;
		}

	}

	if (myRes.wood != 0)
	{
		for (; i <= myRes.wood; i++)
		{
			outputMessage[3 + i] = WOOD;
		}

	}


	if (yourRes.clay != 0)
	{
		for (; i <= yourRes.clay; i++)
		{
			outputMessage[3 + i] = CLAY;
		}

	}

	if (yourRes.sheep != 0)
	{
		for (; i <= yourRes.sheep; i++)
		{
			outputMessage[3 + i] = SHEEP;
		}

	}

	if (yourRes.stone != 0)
	{
		for (; i <= yourRes.stone; i++)
		{
			outputMessage[3 + i] = STONE;
		}

	}

	if (yourRes.wheat != 0)
	{
		for (; i <= yourRes.wheat; i++)
		{
			outputMessage[3 + i] = WHEAT;
		}

	}

	if (yourRes.wood != 0)
	{
		for (; i <= yourRes.wood; i++)
		{
			outputMessage[3 + i] = WOOD;
		}

	}

	sendMessage();
}
//**********************************************************************************************

//*****************************  send Is Message   *********************************************
bool server::isMessage(void)
{
	boost::system::error_code errRecived;
	bool answer = false;
	lenInputMessage = 0;

	do
	{
		// Se lee el socket, se carga la informacion en messeageRecived y se carga el largo del mensaje
		lenInputMessage = socketServer->read_some(boost::asio::buffer(inputMessage), errRecived);

		if (!errRecived)
		{
			inputMessage[lenInputMessage] = '\0';
		}

		//timer

	} while (errRecived.value() == WSAEWOULDBLOCK /* || timer == timeput */);

	if (errRecived)
	{

		answer = false; // No hay mensaje
	}

	else if (!errRecived)
	{
		answer = true; // Hay mensaje
	}

	return answer;
}
//**********************************************************************************************

//*****************************  send Pass   ***************************************************
void server::sendPass(void)
{
	outputMessage[0] = PASS;
	sendMessage();
}

//***********************************  Get Message  *********************************************
message server::getMessage(void)
{
	message answer;
	bool messageStatus;

	//messageStatus = receiveMessage();
	messageStatus = MESSAGE_RECEIVED;
	if (messageStatus == MESSAGE_RECEIVED)
	{
		answer.identifier = inputMessage[0];
		unsigned char coordQuant;
		switch (answer.identifier)
		{
		case CITY:
		case ROAD:
		case SETTLEMENT:
		{
			coordQuant = inputMessage[1];
			if (coordQuant == 2)
			{
				answer.x = inputMessage[2];
				answer.y = inputMessage[3];
				answer.z = NO_VALUE;
			}
			else if (coordQuant == 3)
			{
				answer.x = inputMessage[2];
				answer.y = inputMessage[3];
				answer.z = inputMessage[4];
			}
			break;
		}

		case ROBBER_MOVE:
		{
			answer.x = inputMessage[1];
			answer.y = NO_VALUE;
			answer.z = NO_VALUE;
			break;
		}

		case ROBBER_CARDS:
		case NAME_IS:
		{
			answer.contentLong = inputMessage[1];
			for (int i = 0; i < answer.contentLong; i++)
			{
				answer.content[i] = inputMessage[i + 2];
			}
			break;
		}

		case CIRCULAR_TOKENS:
		{
			for (int i = 0; i < MAX_NUMBER_TOKENS; i++)
			{
				answer.content[i] = inputMessage[i + 1];
			}
			break;
		}

		case MAP_IS:
		{
			for (int i = 0; i < MAX_NUMBER_PIECES; i++)
			{
				answer.content[i] = inputMessage[i + 1];
			}
			break;
		}

		case ACK:
		case YES:
		case NO:
		case QUIT:
		case ERROR:
		case GAME_OVER:
		case PLAY_AGAIN:
		case PASS:
		case I_START:
		case I_WON:
		case YOU_START:
		{
			break;
		}

		case DICES_ARE:
		{
			answer.x = inputMessage[1];
			answer.y = inputMessage[2];
			answer.z = NO_VALUE;
			break;
		}

		case NAME:
		{
			break;
		}

		case BANK_TRADE:
		{
			answer.contentLong = inputMessage[1];

			int i = 0;

			for (; i < answer.contentLong; i++)
			{
				answer.content[i] = inputMessage[i + 2];
			}

			answer.contentBIS[0] = inputMessage[i + 2];

			break;
		}

		case OFFER_TRADE:
		{
			answer.contentLong = inputMessage[1];
			answer.contentLongBIS = inputMessage[2];

			int i = 0;

			for (; i < answer.contentLong; i++)
			{
				answer.content[i] = inputMessage[i + 2];
			}

			for (; i < (answer.contentLongBIS + i); i++)
			{
				answer.contentBIS[i] = inputMessage[i + 2];
			}

			break;
		}

		default:
		{
			answer.identifier = NULL_CHAR;
			answer.contentLong = NULL_CHAR;
			answer.x = NULL_CHAR;
			answer.y = NULL_CHAR;
			answer.z = NULL_CHAR;
		}

		}

	}

	else if (messageStatus == MESSAGE_NOT_RECEIVED)
	{
		answer.identifier = NULL_CHAR;
		answer.contentLong = NULL_CHAR;
		answer.x = NULL_CHAR;
		answer.y = NULL_CHAR;
		answer.z = NULL_CHAR;
	}

	return answer;

}
//**********************************************************************************************

message server::cleanMessage()
{
	message answer;
	answer.identifier = NULL_CHAR;
	answer.contentLong = NULL_CHAR;
	for (int i = 0; i < 255; i++)
	{
		answer.content[i] = NULL_CHAR;
	}
	answer.contentLongBIS = NULL_CHAR;
	for (int i = 0; i < 255; i++)
	{
		answer.contentBIS[i] = NULL_CHAR;
	}
	answer.x = NULL_CHAR;
	answer.y = NULL_CHAR;
	answer.z = NULL_CHAR;

	for (int i = 0; i < 257; i++)
	{
		outputMessage[i] = NULL_CHAR;
	}

	return answer;
}
