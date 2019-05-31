#include "client.h"

using namespace std;

client::client(char * ip)
{
	strcpy(ipRecived, ip);

	IO_handler = new boost::asio::io_service();
	socketClient = new boost::asio::ip::tcp::socket(*IO_handler);
	clientResolver = new boost::asio::ip::tcp::resolver(*IO_handler);
}

client::~client()
{
	socketClient->close();
	delete clientResolver;
	delete socketClient;
	delete IO_handler;
}

//******************************  startConection  **********************************************
// 1 ----> exito
// 0 ----> error
bool client::startConnection(void)
{
	bool answer = CONNECTION_SUCCESS;
	endpoint = clientResolver->resolve(boost::asio::ip::tcp::resolver::query(ipRecived, HELLO_PORT_STR));

	boost::system::error_code errConnect;
	boost::asio::connect(*socketClient, endpoint, errConnect);
	if (errConnect)
	{
		errorConnection.setErrorNumber(errClientConnect);
		string errorDescription = "Error al intentar conectarse a " + string(ipRecived);
		errorConnection.setErrorDescription(errorDescription);
		answer = CONNECTION_DECLINE;
	}
	socketClient->non_blocking(true);
	return answer;
}
//**********************************************************************************************

//******************************  receiveMessage  **********************************************
// 1 ----> exito
// 0 ----> error
bool client::reciveMessage(void)
{
	boost::system::error_code errRecived;

	bool answer = MESSAGE_RECIVED;

	inputMessageLen = 0;

	do
	{
		inputMessageLen = socketClient->read_some(boost::asio::buffer(inputMessage), errRecived);

		if (!errRecived)
		{
			inputMessage[inputMessageLen] = '\0';
		}

	} while (errRecived.value() == WSAEWOULDBLOCK);

	if (errRecived)
	{

		errorRecived.setErrorNumber(errClientRecived);
		string errorDescription = "Error mientras se intento recibir el mensaje";
		errorRecived.setErrorDescription(errorDescription);
		answer = MESSAGE_NOT_RECIVED;
	}

	return answer;
}
//**********************************************************************************************

//*****************************  send Message  *************************************************
void client::sendMessage(void)
{
	unsigned int len;
	boost::system::error_code errSend;
	do
	{
		len = socketClient->write_some(boost::asio::buffer(outputMessage, strlen(outputMessage)), errSend);

	} while ((errSend.value() == WSAEWOULDBLOCK));

	if (errSend)
	{
		errorSend.setErrorNumber(errClientSend);
		string description = "Hubo un error a la hora de enviar el mensaje";
		errorSend.setErrorDescription(description);
	}
}
//**********************************************************************************************

//*****************************  send Name  ****************************************************
void client::sendName(void)
{
	outputMessage[0] = NAME;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Dices  ***************************************************
void client::sendDices(unsigned int dice1, unsigned int dice2)
{
	outputMessage[0] = DICES_ARE;
	outputMessage[1] = dice1;
	outputMessage[2] = dice2;
	sendMessage();

}
//**********************************************************************************************

//*****************************  send Name is  *************************************************
void client::sendNameIs(unsigned char lcount, const char * name)
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
void client::sendAck(void)
{
	outputMessage[0] = ACK;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Yes  *****************************************************
void client::sendYes(void)
{
	outputMessage[0] = YES;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send No  *****************************************************
void client::sendNo(void)
{
	outputMessage[0] = NO;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send I Won  ***************************************************
void client::sendIWon(void)
{
	outputMessage[0] = I_WON;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Play Again  **********************************************
void client::sendPlayAgain(void)
{
	outputMessage[0] = PLAY_AGAIN;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Game Over   **********************************************
void client::sendGameOver(void)
{
	outputMessage[0] = GAME_OVER;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send ERROR  ***************************************************
void client::sendError(void)
{
	outputMessage[0] = ERROR;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Quit  *****************************************************
void client::sendQuit(void)
{
	outputMessage[0] = QUIT;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Map is  **************************************************
void client::sendMapIs(char arr[MAX_NUMBER_PIECES])
{
	outputMessage[0] = MAP_IS;
	for (int i = 0; i < MAX_NUMBER_PIECES; i++)
	{
		outputMessage[1 + i] = arr[i];
	}
	sendMessage();
}
//**********************************************************************************************

//*****************************  send CircularTokens  ******************************************
void client::sendCircularTokens(char arr[MAX_NUMBER_TOKENS])
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
void client::sendRobberCards(unsigned int ncard, const char * arr)
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
void client::sendRobberMove(unsigned char terrain)	//terrain es la coordenada dosne mover el robber(A,B,C,...,S)
{
	outputMessage[0] = ROBBER_MOVE;
	outputMessage[0] = terrain;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Settlement  *********************************************
void client::sendSettlement(coordenates coord, unsigned int coordQuant)
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
void client::sendRoad(coordenates coord, unsigned int coordQuant)
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
void client::sendCity(coordenates coord, unsigned int coordQuant)
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

//*****************************  send Bank Trade  **********************************************
void client::sendBankTrade(unsigned char offerSource, unsigned char reciveSource, unsigned char cantSources)
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

	//Recursos que recive del banco
	outputMessage[i] = reciveSource;

	sendMessage();
}
//**********************************************************************************************

//*****************************  send Offer Trade  *********************************************
void client::sendOfferTrade(tradeIn myRes, tradeIn yourRes)
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

//*****************************  send You Start  ***********************************************
void client::sendYoutStart(void)
{
	outputMessage[0] = YOU_START;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send Pass   ***************************************************
void client::sendPass(void)
{
	outputMessage[0] = PASS;
	sendMessage();
}
//**********************************************************************************************

//*****************************  send I Start  *************************************************
void client::sendIStart(void)
{
	outputMessage[0] = I_START;
	sendMessage();
}
//**********************************************************************************************

bool client::isMessage(void)
{
	boost::system::error_code errRecived;
	bool answer = false;
	inputMessageLen = 0;

	do
	{
		// Se lee el socket, se carga la informacion en messeageRecived y se carga el largo del mensaje
		inputMessageLen = socketClient->read_some(boost::asio::buffer(inputMessage), errRecived);

		if (!errRecived)
		{
			inputMessage[inputMessageLen] = '\0';
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

//***********************************  Get Message  *********************************************
message client::getMessage(void)
{
	message answer;
	bool messageStatus;

	//messageStatus = reciveMessage();
	messageStatus = MESSAGE_RECIVED;
	if (messageStatus == MESSAGE_RECIVED)
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
			answer.identifier = NULL;
			answer.contentLong = NULL;
			answer.x = NULL;
			answer.y = NULL;
			answer.z = NULL;
		}

		}

	}

	else if (messageStatus == MESSAGE_NOT_RECIVED)
	{
		answer.identifier = NULL;
		answer.contentLong = NULL;
		answer.x = NULL;
		answer.y = NULL;
		answer.z = NULL;
	}

	return answer;

}
//***********************************************************************************************

message client::cleanMessage(void)
{
	message answer;
	answer.identifier = NULL;
	answer.contentLong = NULL;
	for (int i = 0; i < 255; i++)
	{
		answer.content[i] = NULL;
	}
	answer.contentLongBIS = NULL;
	for (int i = 0; i < 255; i++)
	{
		answer.contentBIS[i] = NULL;
	}
	answer.x = NULL;
	answer.y = NULL;
	answer.z = NULL;

	return answer;
}
