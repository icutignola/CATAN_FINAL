#pragma once

// Coordenadas
typedef struct
{
	unsigned char x;
	unsigned char y;
	unsigned char z;
}coordenates;

// Respuesta para el trablero principal
typedef struct
{
	unsigned char	identifier;		//IDENTIFICADOR
	unsigned char	x;				//VALOR 1 (COORDENADA X, DADO1, ETC)
	unsigned char	y;				//VALOR 2 (COORDENADA Y, DADO2, ETC)
	unsigned char	z;				//VALOR 3 (COORDENADA Z)
}genIn;

// Respuesta para el intercambio
typedef struct
{
	unsigned char wood;		
	unsigned char wheat;	
	unsigned char clay;		
	unsigned char stone;	
	unsigned char sheep;	

}tradeIn;

//Respuesta del intercambio con el banco
typedef struct
{
	unsigned char give;
	unsigned char recive;

}tradeBank;

//Estructura para obtener el nombre
typedef struct
{
	char name [255];
	unsigned int longName;

}nameInfo;


// Mensaje
typedef struct
{
	unsigned char	identifier;		//IDENTIFICADOR
	unsigned char	contentLong;	//LARGO DEL MENSAJE PRIMARIO
	char	content[255];	// MENSAJE (NOMBRE, LISTA DE TOKENS, LISTA DE RECURSOS, ETC)
	unsigned char	contentLongBIS;	//LARGO DEL MENSAJE SECUNDARIO
	unsigned char	contentBIS[9];  //MENSAJE SECUNDARIO (LISTA DE RECURSOS PARA HACER INTERCAMBIO, ETC)
	unsigned char	x;				//VALOR 1 (COORDENADA X, DADO1, ETC)
	unsigned char	y;				//VALOR 2 (COORDENADA Y, DADO2, ETC)
	unsigned char	z;				//VALOR 3 (COORDENADA Z)
}message;
