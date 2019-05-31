#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "defines.h"
#include "auxiliar.h"
#include "errorC.h"
#include "Player.h"
#include "Map.h"
#include "Road.h"
#define _CRT_SECURE_NO_WARNINGS


/*
*******************************  BOTONES  ************************************************
*
*	ACCION = (BUTTON, ACCION, 0) = (254, #ACCION, 0)
*
*	dices =		(BUTTONS, DICES_A, 0);	//Boton para tirar dados
*	offer =		(BUTTONS, OFFER_A, 0);	//Boton para ofrecer intercambio
*	bank =		(BUTTONS, BANK_A, 0);	//Boton para intercambiar con el banco
*	quit =		(BUTTONS, QUIT_A, 0);	//Boton para salir
*	yes =		(BUTTONS, YES_A, 0);	//Boton para decir YES
*	no =		(BUTTONS, NO_A, 0);		//Boton para decir NO	
*	wood =		(BUTTONS, WOOD_A, 0);	//Btoton para seleccionar madera
*	wheat =		(BUTTONS, WHEAT_A, 0);	//Boton para seleccionar trigo
*	clay =		(BUTTONS, CLAY_A, 0);	//Boton para seleccionar arcilla
*	stone =		(BUTTONS, STONE_A, 0);	//Boton para seleccionar piedra
*	sheep =		(BUTTONS, SHEEP_A, 0);	//Boton para seleccionar oveja
*	reset =		(BUTTONS, RESET_A, 0);	//Boton de reset
*	ok =		(BUTTONS, OK_A, 0);		//Boton de OK
*	build =		(BUTTONS, BUILD_A, 0);	//Boton para construir
*	ciudadB =	(BUTTONS, CITY_A, 0);	//Bototn para contruir ciudad
*	casaB =		(BUTTONS, CASA_A, 0);	//Bototn para contruir casa
*	rutaB =		(BUTTONS, RUTA_A, 0);	//Bototn para contruir ruta
*
*/

typedef struct
{
	int x;
	int y;
}mouse_input;

class io
{
public:

	//*********** CONSTRUCTOR ************

	io();
	//~io();

	//************************************

	//******** METODOS DE INPUT **********

	bool isInput(void);	//Se fija en la cola de eventos de allegro si hay algo, devuelve IS_EVENT si hay un evento o NO_EVENT si no lo hay 
	
	unsigned char getInput(void);	//Cuando hay un evento, se fija que selecciono en la pantalla el jugador.
	
	genIn getBuildingInput(void);	//Cuando se quiere contruir, se fija que se quiere construir y en que coordenadas.
	
	char getYN(void); //Devuele un YES o NO, segun lo seleccionado por el jugador. No temrina el metodo hasta que no se seleccione o YES o NO.
	
	tradeIn getTradeInfo(int maxWood, int maxSheep, int maxStone, int maxClay, int maxWheat, bool pFlag);

	nameInfo getMyName(void); //Se llama al principio para recibir el nombre 
	
	char* getMyIp(void); //Se llama al principio para recibir la ip

	tradeBank getTradeBank(void); //Se llama para recibir que recursos quiere intercambiar el jugador con el banco

	unsigned char getSuprResource(void);

	//************************************

	//******** METODOS DE OUTPUT *********

	//showGeneralDisplay se llama depsues de cada cambio
	void showGeneralDisplay(Player* P1, Player* P2, Map* MapIs, bool Turn, unsigned char menuType); //Le envia la informacion de P1, P2, el mapa (tipo de islas y tokens) y MY_TURN o YOUR_TURN segun corresponda

	//showYN se llama antes de llamar a getYN
	void showYN(tradeIn trade1, tradeIn trade2);

	void showError(string errorDescription);

	//Se llama al principio cuando se intenta conectar como cliente
	void showTryToConnect(void);

	//Se llama al principio cuando se interta conectar como server
	void showWaitPlayer(void);

	//Se llama a la funcion con "true" si acepto yh con "false" si no acepto
	void showAnswer(bool answer);

	void showBankTradeOtherPlayer(unsigned char resP, unsigned char resB);

	//**************************** CARTELES ESTATICOS ***********************************************

	//Se llama para mostrar en la pantalla que se pudo realizar el trade
	void showTradeAccepted(void);

	//Se llama para mostrar en la pantalla que no se pudo realizar el intercambio
	void showCantTrade(void);

	//Se llama para mostrar que no hay suficientes recursos
	void showNoResource(void);

	//Se llama para mostrar que las coordenadas son invalidas
	void showInvalidCooord(void);

	//Se llama para mostrar en pantalla que el jugador local gano
	void showIWon(void);

	//Se llama para mostrar en pantalla que el ugador local perdio
	void showILose(void);

	//***********************************************************************************************

	//************************************

	//************* ERROR ****************

	bool isError(void);
	errorC getInitError(void);

	//************************************
private:

	//******** VARIABLES Y METODOS DE INPUT **********

	mouse_input myMouse;

	ALLEGRO_BITMAP* generalInput;
	ALLEGRO_BITMAP* buildingInput;
	ALLEGRO_BITMAP* ynInput;
	ALLEGRO_BITMAP* tradeInput;
	ALLEGRO_BITMAP* coordInput;


	ALLEGRO_COLOR inputColor;

	coordenates getCoordenates(unsigned int buildFlag);

	//**************************************

	ALLEGRO_EVENT_QUEUE *colaEvAllegro;
	ALLEGRO_EVENT evAllegro;

	//******* VARIABLES DE OUTPUT **********

	//Display
	ALLEGRO_DISPLAY* showDisplay;

	//Numeros
	ALLEGRO_BITMAP* twoBmp;
	ALLEGRO_BITMAP* threeBmp;
	ALLEGRO_BITMAP*	fourBmp;
	ALLEGRO_BITMAP* fiveBmp;
	ALLEGRO_BITMAP* sixBmp;
	ALLEGRO_BITMAP* sevenBmp;
	ALLEGRO_BITMAP* eightBmp;
	ALLEGRO_BITMAP* nineBmp;
	ALLEGRO_BITMAP* tenBmp;
	ALLEGRO_BITMAP* elevenBmp;
	ALLEGRO_BITMAP* twelveBmp;

	//Materiales
	ALLEGRO_BITMAP* woodBmp;
	ALLEGRO_BITMAP* clayBmp;
	ALLEGRO_BITMAP* wheatBmp;
	ALLEGRO_BITMAP* stoneBmp;
	ALLEGRO_BITMAP* sheepBmp;
	ALLEGRO_BITMAP* seaBmp;

	//Indicador de turno
	ALLEGRO_BITMAP* OnBmp;
	ALLEGRO_BITMAP* OffBmp;

	//Robber
	ALLEGRO_BITMAP* RobberBmp;

	//"Pantallas"
	ALLEGRO_BITMAP* generalOutput;
	ALLEGRO_BITMAP* buildingOutput;
	ALLEGRO_BITMAP* tradeOutput1;
	ALLEGRO_BITMAP* tradeOutput2;
	ALLEGRO_BITMAP* bankTradeOutput;
	ALLEGRO_BITMAP* ynOutput;
	ALLEGRO_BITMAP* nameOutput;
	ALLEGRO_BITMAP* ipOutput;
	ALLEGRO_BITMAP* waitOutput;
	ALLEGRO_BITMAP* tryOutput;
	ALLEGRO_BITMAP* wonOutput;
	ALLEGRO_BITMAP* loseOutput;
	ALLEGRO_BITMAP* noResourseOutput;
	ALLEGRO_BITMAP* notTradeOutput;
	ALLEGRO_BITMAP* aceptOutput;
	ALLEGRO_BITMAP* notAcceptOutput;
	ALLEGRO_BITMAP* invalidCoordOutput;
	ALLEGRO_BITMAP* TradeAcceptedOutput;
	ALLEGRO_BITMAP* suprOutput;
	ALLEGRO_BITMAP* otherBankOutput;

	//Error
	ALLEGRO_BITMAP* errorOutput;

	//Colores
	ALLEGRO_COLOR colorP1;
	ALLEGRO_COLOR colorP2;
	ALLEGRO_COLOR colorFont;

	//Fuente
	ALLEGRO_FONT* fuente;
	ALLEGRO_FONT* fuenteTrade;
	ALLEGRO_FONT* fuenteName;

	Coordinates coordArray[MAX_COORDENATES_AMMOUNT_V];
	Coordinates coordRoadArray[MAX_COORDENATES_AMMOUNT_R];

	//Metodos auxiliares
	void showTrade(int woodCant, int sheepCant, int stoneCant, int clayCant, int wheatCnat, bool Pflag);
	int getNumberV(Coordinates coord);
	int getNumberA(Coordinates coord);
	void setCoordArray(void);
	void setCoordRoadArray(void);
	//**************************************

	errorC errInit;
	bool errorFlag;

 




};