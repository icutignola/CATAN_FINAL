#pragma once
#include "Island.h"
#include "Dock.h"
#include <iostream>
#include <time.h>

#include "defines.h"

class Map
{
public:
    Map();
    Map(char[MAP_ITEMS_NUMBER], char[ISLANDS_AMMOUNT]);
    ~Map();
    Island * getIslands(void); //devuelve un array de las islas
    Dock * getDocks(void); //devuelve un array de los puertos
    void setIslands(void);// para poner las islas al principio
    void setDocks(void); //para mezclar los puertos al principio

	char* getIslandTypeArray(void);
	char* getIslandTokensArray(void);
	char* getDocksArray(void);

	void setIslands(char* types, char* nums);
	void setDocks(char* numbers);

private:
	char islandsTypeArray[ISLANDS_AMMOUNT]; //arreglo de tipo de islas
	char numbers[ISLANDS_AMMOUNT - 1]; //Desierto no tiene numero
	char dockArray[DOCKS_AMMOUNT];
    Island islands[ISLANDS_AMMOUNT]; // arreglo de islas
    Dock docks[DOCKS_AMMOUNT]; // arreglo de puertos
};