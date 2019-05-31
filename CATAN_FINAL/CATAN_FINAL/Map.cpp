#include "Map.h"


Map::Map()
{
	//NUMEROS: 2 3 3 4 4 5 5 6 6 8 8 9 9 10 10 11 11 12
	numbers[0] = 2;
	for (int i = 1; i <= 2; i++)
	{
		numbers[i] = 3;
	}
	for (int i = 3; i <= 4; i++)
	{
		numbers[i] = 4;
	}
	for (int i = 5; i <= 6; i++)
	{
		numbers[i] = 5;
	}
	for (int i = 7; i <= 8; i++)
	{
		numbers[i] = 6;
	}
	for (int i = 9; i <= 10; i++)
	{
		numbers[i] = 8;
	}
	for (int i = 11; i <= 12; i++)
	{
		numbers[i] = 9;
	}
	for (int i = 13; i <= 14; i++)
	{
		numbers[i] = 10;
	}
	for (int i = 15; i <= 16; i++)
	{
		numbers[i] = 11;
	}
	numbers[17] = 12;

	//ISLA: DESIERTO BOSQUE BOSQUE BOSQUE BOSQUE PASTO PASTO PASTO COLINA COLINA COLINA MONTANIA MONTANIA MONTANIA CAMPO CAMPO CAMPO CAMPO
	islandsTypeArray[0] = DESIERTO;
	for (int i = 1; i <= 4; i++)
	{
		islandsTypeArray[i] = BOSQUE;
	}
	for (int i = 5; i <= 7; i++)
	{
		islandsTypeArray[i] = PASTO;
	}
	for (int i = 8; i <= 10; i++)
	{
		islandsTypeArray[i] = COLINA;
	}
	for (int i = 11; i <= 15; i++)
	{
		islandsTypeArray[i] = MONTANIA;
	}
	for (int i = 15; i <= 19; i++)
	{
		islandsTypeArray[i] = CAMPO;
	}

	//DOCKS: N T O L P M
	dockArray[0] = 'N';
	dockArray[1] = 'T';
	dockArray[2] = 'O';
	dockArray[3] = 'L';
	dockArray[4] = 'P';
	dockArray[5] = 'M';



}

Map::Map(char map[MAP_ITEMS_NUMBER], char numbers[ISLANDS_AMMOUNT]) { //por si soy client, copio el mapa
    //for (int i = DOCKS_AMMOUNT; i < MAP_ITEMS_NUMBER; i++) {
    //    switch (map[i])
    //    {
    //        case WOOD:
    //            islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], BOSQUE);
    //            break;
    //        case WHEAT:
    //            islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], CAMPO);
    //            break;
    //        case STONE:
    //            islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], MONTANIA);
    //            break;
    //        case CLAY:
    //            islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], COLINA);
    //            break;
    //        case SHEEP:
    //            islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], PASTO);
    //            break;
    //        case DESIERTO:
    //            islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], DESIERTO);
    //            break;
    //    }
    //}

    //for (int i = 0; i < DOCKS_AMMOUNT; i++) {
    //    docks[i] = Dock(i, map[i]);
    //}
}

Map::~Map()
{
}

// PARA CUANDO ES "SERVER" Y TIENE QUE CREAR EL JUEGO
void Map::setIslands()
{
    srand((unsigned int) time(NULL));

	char aux;

    for (int i = 0; i < ISLANDS_AMMOUNT; i++) {
        int index = rand() % ISLANDS_AMMOUNT;
        aux = islandsTypeArray[i];
        islandsTypeArray[i] = islandsTypeArray[index];
		islandsTypeArray[index] = aux;
    }
    for (int i = 0; i < ISLANDS_AMMOUNT-1; i++) {
        int index = rand() % (ISLANDS_AMMOUNT -1);
        aux = numbers[i];
        numbers[i] = numbers[index];
        numbers[index] = aux;
    }
    for ( int i = 0, j = 0; i < ISLANDS_AMMOUNT; i++)	//Inicializo la tierra vacia
    {
        if (islandsTypeArray[i] == DESIERTO) {
            islands[i] = Island('A' + i, 0, islandsTypeArray[i]);
        }
        else
        {
            islands[i] = Island('A' + i, numbers[j], islandsTypeArray[i]);
            j++;
        }
    }
}
void Map::setDocks()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < DOCKS_AMMOUNT; i++) {
        int index = rand() % DOCKS_AMMOUNT;
        char aux = dockArray[i];
		dockArray[i] = dockArray[index];
		dockArray[index] = aux;
    }

    for (int j = 0; j < DOCKS_AMMOUNT; j++)
    {
        docks[j] = Dock(j, dockArray[j]);
    }
}

// PARA CUANDO ES "CLIENTE" Y TTIENE QUE COPIAR EL JUEGO
void Map::setIslands(char * types, char * nums)
{
	for (int i = 0; i < ISLANDS_AMMOUNT; i++)
	{
		islandsTypeArray[i] = types[i];
	}

	for (int i = 0; i < ISLANDS_AMMOUNT - 1; i++)
	{
		numbers[i] = nums[i];
	}

	for (int i = 0, j = 0; i < ISLANDS_AMMOUNT; i++)	//Inicializo la tierra vacia
	{
		if (islandsTypeArray[i] == DESIERTO) {
			islands[i] = Island('A' + i, 0, islandsTypeArray[i]);
		}
		else
		{
			islands[i] = Island('A' + i, numbers[j], islandsTypeArray[i]);
			j++;
		}
	}


}
void Map::setDocks(char * dockIn)
{
	for (int i = 0; i < DOCKS_AMMOUNT; i++)
	{
		dockArray[i] = dockIn[i];
	}

	for (int j = 0; j < DOCKS_AMMOUNT; j++)
	{
		docks[j] = Dock(j, dockArray[j]);
	}
}



char * Map::getIslandTypeArray()
{
	return islandsTypeArray;
}

char * Map::getIslandTokensArray()
{
	return numbers;
}

char * Map::getDocksArray(void)
{
	return dockArray;
}



Island * Map::getIslands(void) {
    return islands;
}
Dock * Map::getDocks(void) {
    return docks;
}

