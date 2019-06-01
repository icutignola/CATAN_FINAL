#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/function.hpp>
#include <boost/operators.hpp>
#include <boost/date_time/compiler_config.hpp>
//#include <boost/date_time/year_month_day.hpp>
#include <boost/date_time/special_defs.hpp>
#include <boost/cerrno.hpp>
#include <boost/bind.hpp>
#include "controller.h"
#include "defines.h"
#include "auxiliar.h"
#include "errorC.h"

#define WSAEWOULDBLOCK EWOULDBLOCK
#define ERROR ERROR_T

using namespace std;

class server
{
public:

	server(const char *ip);

	bool startConnection(void);	//El server se queda en esta funcion esperando a que alguien se conecte, si se apreta la tecla Q o alguien se conecto, se termina de ejecutar la funcion

	void sendName(void);	//Le avisa que le va a mandar el nombre

	void sendDices(unsigned int dice1, unsigned int dice2); //Le envia el valor de los dados

	void sendNameIs(unsigned char lcount, const char* name); //Le envia el nombre y la longitud

	void sendAck(void);

	void sendYes(void);

	void sendNo(void);

	void sendIWon(void);

	void sendPlayAgain(void);

	void sendGameOver(void);

	void sendError(void);

	void sendQuit(void);

	void sendMapIs(char arr[MAX_NUMBER_PIECES], char docks[DOCKS_AMMOUNT]); //Le envia los tipos de islas

	void sendCircularTokens(char arr[MAX_NUMBER_TOKENS]); //Le envia los valores de cada isla

	void sendRobberCards(unsigned int ncard, const char *arr);

	void sendRobberMove(unsigned char terrain);	//Le informa a donde se movio el robber

	void sendSettlement(coordenates coord, unsigned int coordQuant); //Le envia donde contruyo un settlement y cuantas coordenadas le envia

	void sendRoad(coordenates coord, unsigned int coordQuant); //Le envia donde contruyo un road y cuantas coordenadas le envia

	void sendCity(coordenates coord, unsigned int coordQuant); //Le envia donde contruyo una city y cuantas coordenadas le envia

	void sendYoutStart(void);

	void sendIStart(void);

	void sendBankTrade(unsigned char offerSource, unsigned char reciveSource, unsigned char cantSources);

	void sendOfferTrade(tradeIn myRes, tradeIn yourRes);

	bool isMessage(void);

	void sendPass(void);

	message cleanMessage(void);

	message getMessage(void); //Carga la informacion recibida por parte del otro jugador en una variable "message"

	//typedef struct
	//{
	//	unsigned char	identifier;		//IDENTIFICADOR
	//	unsigned char	contentLong;	//LARGO DEL MENSAJE PRIMARIO
	//	unsigned char	content[255];	// MENSAJE (NOMBRE, LISTA DE TOKENS, LISTA DE RECURSOS, ETC)
	//	unsigned char	contentLongBIS;	//LARGO DEL MENSAJE SECUNDARIO
	//	unsigned char	contentBIS[9];  //MENSAJE SECUNDARIO (LISTA DE RECURSOS PARA HACER INTERCAMBIO, ETC)
	//	unsigned char	x;				//VALOR 1 (COORDENADA X, DADO1, ETC)
	//	unsigned char	y;				//VALOR 2 (COORDENADA Y, DADO2, ETC)
	//	unsigned char	z;				//VALOR 3 (COORDENADA Z)
	//}message;

	//Depende de lo que este cargado en "identifier", decidis si fijarse en los otros campor
	//Si en identifier recibis un YES, no sirve de nada que te fijes en los otros campos
	//Si en identifier recibis un TOWN, te fijas en los campor x,y,z las coordenadas
	//Si en identifier recibis un NAME_IS, te fijas en content el nombre y en contentLong el larog del mensaje


	unsigned char inputMessage[257];
	char outputMessage[257];

	errorC errorConnection;
	errorC errorSend;
	errorC errorRecived;

	char ipRecived[15];

private:

	boost::asio::io_service*  IO_handler;
	boost::asio::ip::tcp::socket* socketServer;
	boost::asio::ip::tcp::acceptor* server_acceptor;

	unsigned int lenInputMessage;


	bool reciveMessage(void);
	void sendMessage(void);
};