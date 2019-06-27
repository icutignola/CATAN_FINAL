#pragma once
#include "Island.h"
#include "Dock.h"
#include <iostream>
#include <time.h>

#include "defines.h"

class Map
{
public:

    /** --------- Constructores --------- */
    Map();

    /** --------- Destructor --------- */
    ~Map();

    /** --------- Getters --------- */
    Island * getIslands(); //devuelve un array de las islas
    Dock * getDocks(); //devuelve un array de los puertos
    char* getIslandTypeArray(); // Devuelve el arreglo de los posibles tipos de islas
    char* getIslandTokensArray(); // Devuelve el arreglo de los posible numeros de islas
    char* getDocksArray(); // Devuelve el arreglo de los posibles tipos de puertos

    /** --------- Setters --------- */
    void setIslands();// (PARA SERVER)
    void setDocks(); // (PARA SERVER)
	void setIslands(char* types, char* nums); // (PARA CLIENT)
	void setDocks(char* numbers); // (PARA CLIENT)

private:
	char islandsTypeArray[ISLANDS_AMMOUNT]; //arreglo de tipo de islas
	char numbers[ISLANDS_AMMOUNT - 1]; //Desierto no tiene numero
	char dockArray[DOCKS_AMMOUNT];
    Island islands[ISLANDS_AMMOUNT]; // arreglo de islas
    Dock docks[DOCKS_AMMOUNT]; // arreglo de puertos
};