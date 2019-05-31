#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
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

using namespace std;

class client
{
public:

	client(char *ip);

	~client();

	bool startConnection(void);	//El cliente se fija si hay un server disponible, si existe se conecta y si no existe termina la funcion

	void sendName(void); //Le avisa que le va a mandar el nombre

	void sendDices(unsigned int dice1, unsigned int dice2); //Le envia el nombre y la longitud

	void sendNameIs(unsigned char lcount, const char* name); //Le envia el valor de los dados

	void sendAck(void);

	void sendYes(void);

	void sendNo(void);

	void sendIWon(void);

	void sendPlayAgain(void);

	void sendGameOver(void);

	void sendError(void);

	void sendQuit(void);

	void sendMapIs(char arr[MAX_NUMBER_PIECES]); //Le envia los tipos de islas

	void sendCircularTokens(char arr[MAX_NUMBER_TOKENS]); //Le envia los valores de cada isla

	void sendRobberCards(unsigned int ncard, const char *arr);

	void sendRobberMove(unsigned char terrain); 	//Le informa a donde se movio el robber

	void sendSettlement(coordenates coord, unsigned int coordQuant); //Le envia donde contruyo un settlement y cuantas coordenadas le envia

	void sendRoad(coordenates coord, unsigned int coordQuant); //Le envia donde contruyo un road y cuantas coordenadas le envia

	void sendCity(coordenates coord, unsigned int coordQuant); //Le envia donde contruyo una city y cuantas coordenadas le envia

	void sendYoutStart(void);

	void sendPass(void);

	void sendIStart(void);

	void sendBankTrade(unsigned char offerSource, unsigned char reciveSource, unsigned char cantSources);

	void sendOfferTrade(tradeIn myRes, tradeIn yourRes);

	bool isMessage(void);

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

	boost::asio::io_service* IO_handler;
	boost::asio::ip::tcp::socket* socketClient;
	boost::asio::ip::tcp::resolver* clientResolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;


	unsigned int inputMessageLen;

	bool reciveMessage(void);
	void sendMessage(void);



};
