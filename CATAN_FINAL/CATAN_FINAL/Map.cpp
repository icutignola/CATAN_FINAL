#include "Map.h"


Map::Map()
{
	//NUMEROS: 2 3 3 4 4 5 5 6 6 8 8 9 9 10 10 11 11 12
	numbers[0] = 2;
	for(int i = 0, number = 2; i<ISLANDS_AMMOUNT - 1; i++){
	    numbers[i] = number;
	    if(i%2 == 0)
	        number++;
        if(number == 7)
            number++;
	}

	//ISLA: DESIERTO BOSQUE BOSQUE BOSQUE BOSQUE PASTO PASTO PASTO PASTO COLINA COLINA COLINA MONTANIA MONTANIA MONTANIA CAMPO CAMPO CAMPO CAMPO
	int desiertoQty, bosqueQty, pastoQty, colinaQty, montaniaQty, campoQty;
	desiertoQty = 1;
	bosqueQty = pastoQty = campoQty = 4;
	colinaQty = montaniaQty = 3;
	//NOTA: Todas las variables anteriores, deben sumar ISLANDS_AMMOUNT
	int i = 0;
	while(i< desiertoQty){
	    islandsTypeArray[i] = DESIERTO;
	    i++;
	}
    while(i< bosqueQty){
        islandsTypeArray[i] = BOSQUE;
        i++;
    }
    while(i< pastoQty){
        islandsTypeArray[i] = PASTO;
        i++;
    }
    while(i< campoQty){
        islandsTypeArray[i] = CAMPO;
        i++;
    }
    while(i< colinaQty){
        islandsTypeArray[i] = COLINA;
        i++;
    }
    while(i< montaniaQty){
        islandsTypeArray[i] = MONTANIA;
        i++;
    }

	//DOCKS: N T O L P M
	dockArray[0] = 'N';
	dockArray[1] = 'T';
	dockArray[2] = 'O';
	dockArray[3] = 'L';
	dockArray[4] = 'P';
	dockArray[5] = 'M';



}

Map::~Map() = default;

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

char * Map::getDocksArray()
{
	return dockArray;
}



Island * Map::getIslands() {
    return islands;
}
Dock * Map::getDocks() {
    return docks;
}

