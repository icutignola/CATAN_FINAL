#include "Catan.h"


//Catan::Catan(Player * player1, Player* player2, char map[MAP_ITEMS_NUMBER], char numbers[ISLANDS_AMMOUNT]) {// constructor por si soy client que tenog que copiar el mapa
//	this->player1 = player1;
//	this->player2 = player2;
//	this->catanError = NO_ERROR_t;
//	this->map = Map(map, numbers);
//	Coordinates dessertCoord;
//	bool found = false;
//	for (int i = 0; i < ISLANDS_AMMOUNT && !found; i++) {
//		if (getMap()->getIslands()[i].getType() == DESIERTO) {
//			dessertCoord.setX(getMap()->getIslands()[i].getPosition());
//			getMap()->getIslands()[i].setBlock(true);
//			found = true;
//		}
//		else
//			getMap()->getIslands()[i].setBlock(false);
//	}
//	this->robber = Robber(dessertCoord);
//}

Catan::Catan(Player * player1, Player * player2)
{
	this->player1 = player1;
	this->player2 = player2;
	this->catanError = NO_ERROR_t;
	Coordinates dessertCoord;
	getMap()->setDocks();
	getMap()->setIslands();

	bool found = false;
	for (int i = 0; i < ISLANDS_AMMOUNT && !found; i++) {
		if (getMap()->getIslands()[i].getType() == DESIERTO) {
			dessertCoord.setX(getMap()->getIslands()[i].getPosition());
			getMap()->getIslands()[i].setBlock(true);
			found = true;
		}
	}
	this->robber = Robber(dessertCoord);
}

Catan::Catan() = default;

void Catan::randomize() {
	srand((unsigned int)time(nullptr));
}

Robber * Catan::getRobber() {
	return &robber;
}

void Catan::validTrade(tradeIn give, tradeIn request, Player *player, Player *other)//recibe el player que quiere hacer el cambio
{
	player->setWood(player->getWood() - give.wood);
	other->setWood(other->getWood() + give.wood);
	player->setClay(player->getClay() - give.clay);
	other->setClay(other->getClay() + give.clay);
	player->setSheep(player->getSheep() - give.sheep);
	other->setSheep(other->getSheep() + give.sheep);
	player->setWheat(player->getWheat() - give.wheat);
	other->setWheat(other->getWheat() + give.wheat);
	player->setStone(player->getStone() - give.stone);
	other->setStone(other->getStone() + give.stone);

	player->setWood(player->getWood() + request.wood);
	other->setWood(other->getWood() - request.wood);
	player->setClay(player->getClay() + request.clay);
	other->setClay(other->getClay() - request.clay);
	player->setSheep(player->getSheep() + request.sheep);
	other->setSheep(other->getSheep() - request.sheep);
	player->setWheat(player->getWheat() + request.wheat);
	other->setWheat(other->getWheat() - request.wheat);
	player->setStone(player->getStone() + request.stone);
	other->setStone(other->getStone() - request.stone);
}

errorT Catan::checkDockTrade(Player * player, tradeIn give, Coordinates coordinates) { // se fija que todos los resources de give sean iguales
	int coordenadasPosibleDock; //si esas coordinates tiene un port seria en esa coordenada
	if (coordinates.getY() >= '0' && coordinates.getY() <= '5') { //si la segunda es un numero, la primera tambien
		if (coordinates.getY() == (coordinates.getX() + 1) % 6) //si el Y esta a la derecha de X (siempre el que va primero en sentido anti horario es el que puede ser puerto)
			coordenadasPosibleDock = coordinates.getY();
		else
			coordenadasPosibleDock = coordinates.getX();
	}
	else if (coordinates.getX() >= '0' && coordinates.getX() <= '5') { //si la primera no fuera numero, no podria tener puerto
		coordenadasPosibleDock = coordinates.getX();
	}
	else
		return ERROR_TRADING_DOCK;

	if (getMap()->getDocks()[coordenadasPosibleDock].getTradeType() == 'P' || getMap()->getDocks()[coordenadasPosibleDock].getTradeType() == 'M' || getMap()->getDocks()[coordenadasPosibleDock].getTradeType() == 'N') { //los puertos solos
		for (int i = 0; i < SINGLE_PORT_VERTEX_AMMOUNT; i++) {
			if (singlePortVertexes[i] == coordinates) {
				return player->hasResources(give)? NO_ERROR_t:ERROR_NO_RESOURCES;
				/* switch(getMap()->getDocks()[coordenadasPosibleDock].getTradeType()){
					case 'P':
						if(give.stone == 2 && give.clay == 0 && give.sheep == 0 && give.wheat == 0 && give.wood == 0)
							return player->hasResources(give);
						else
							setError(ERROR_TRADING_PORT);
							return false;
					case 'M':
						if(give.stone == 0 && give.clay == 0 && give.sheep == 0 && give.wheat == 0 && give.wood == 2)
							return player->hasResources(give);
						else
							setError(ERROR_TRADING_PORT);
						return false;
						break;
					case 'N':
				}
				*/
			}
		}
		return ERROR_TRADING_DOCK;
	}
	else {// es un puerto doble
		for (int i = 0; i < DOUBLE_PORT_VERTEX_AMMOUNT; i++) {
			if (doublePortVertexes[i] == coordinates) {
				return player->hasResources(give)? NO_ERROR_t:ERROR_NO_RESOURCES;
			}
		}
		return ERROR_TRADING_DOCK;
	}
}

errorT Catan::getError() {
	return this->catanError;
}

void Catan::setError(errorT error) {
	this->catanError = error;
}

int Catan::resourcesQuantity(Player * player) {
	int suma = 0;
	suma += player->getWood();
	suma += player->getSheep();
	suma += player->getStone();
	suma += player->getClay();
	suma += player->getWheat();
	return suma;
}


void Catan::buildTown(const Coordinates &coordinates, Player * player)
{
	Town newTown(coordinates);
	player->getBuildings()[player->getTownsBuilt() + player->getCitiesBuilt()] = newTown;
	player->setVictoryPoints(player->getVictoryPoints() + 1);
	player->setTownsBuilt(player->getTownsBuilt() + 1);
}

void Catan::buildCity(const Coordinates &coordinates, Player * player) //se llama SIEMPRE despues de canBuildCity
{
	City newCity(coordinates);
	for (int i = 0; i < player->getTownsBuilt() + player->getCitiesBuilt(); i++) //recorro el array de buildings del player
	{
		if (*(player->getBuildings()[i].getTokenCoordinates()) == coordinates) // si encuentro un building en ese lugar
		{
			player->getBuildings()[i] = newCity;
		}
	}
	player->setTownsBuilt(player->getTownsBuilt() - 1);
	player->setCitiesBuilt(player->getCitiesBuilt() + 1);
	player->setVictoryPoints(player->getVictoryPoints() + 1);
	player->setWheat(player->getWheat() - 2); //para cobrarle si construyo
	player->setStone(player->getStone() - 3);
}

void Catan::buildRoad(const Coordinates &coordinates, Player * player) {
	Road newRoad(coordinates);
	player->getRoads()[player->getRoadsBuilt()] = newRoad;
	player->setRoadsBuilt(player->getRoadsBuilt() + 1);
	if (getLongestRoadPlayer() == nullptr) { //si nadie tenia longest road todavia
		if (player->getRoadsBuilt() >= LONGEST_ROAD_MIN) {
			setLongestRoadPlayer(player);
			player->setVictoryPoints(player->getVictoryPoints() + 2);
		}
	}
	else if ((getLongestRoadPlayer()->getRoadsBuilt()) < player->getRoadsBuilt()) { //si el que tenia el longest road tiene menos roads que el que acaba de construir
		getLongestRoadPlayer()->setVictoryPoints(getLongestRoadPlayer()->getVictoryPoints() - 2);
		player->setVictoryPoints(player->getVictoryPoints() + 2);
		setLongestRoadPlayer(player);
	}
}

bool Catan::canTrade(tradeIn give, tradeIn request, Player * player, Player * other) {
	return player->hasResources(give) && other->hasResources(request);
}

void Catan::tradeDock(tradeIn give, tradeIn request , Player * player) { //SIEMPRE se llama a checkDockTrade antes
    //CREO QUE DEBERIA VERIFICAR LA CANTIDAD DE RECURSOS
	player->setWood(player->getWood() - give.wood);
	player->setClay(player->getClay() - give.clay);
	player->setSheep(player->getSheep() - give.sheep);
	player->setWheat(player->getWheat() - give.wheat);
	player->setStone(player->getStone() - give.stone);

	player->setWood(player->getWood() + request.wood);
	player->setClay(player->getClay() + request.clay);
	player->setSheep(player->getSheep() + request.sheep);
	player->setWheat(player->getWheat() + request.wheat);
	player->setStone(player->getStone() + request.stone);
}

errorT Catan::tradeBank(char give, char take, Player * player) {
	bool hasResources = false;
	switch (give) {
	case WOOD:
		if (player->getWood() >= MAX_RESOURCE_AMMOUNT) {
			hasResources = true;
			player->setWood(player->getWood() - MAX_RESOURCE_AMMOUNT);
		}
		break;
	case CLAY:
		if (player->getClay() >= MAX_RESOURCE_AMMOUNT) {
			hasResources = true;
			player->setClay(player->getClay() - MAX_RESOURCE_AMMOUNT);
		}
		break;
	case WHEAT:
		if (player->getWheat() >= MAX_RESOURCE_AMMOUNT) {
			hasResources = true;
			player->setWheat(player->getWheat() - MAX_RESOURCE_AMMOUNT);
		}
		break;
	case SHEEP:
		if (player->getSheep() >= MAX_RESOURCE_AMMOUNT) {
			hasResources = true;
			player->setSheep(player->getSheep() - MAX_RESOURCE_AMMOUNT);
		}
		break;
	case STONE:
		if (player->getStone() >= MAX_RESOURCE_AMMOUNT) {
			hasResources = true;
			player->setStone(player->getStone() - MAX_RESOURCE_AMMOUNT);
		}
		break;
	}
    if (hasResources){

        switch (take) {
            case WOOD:
                player->setWood(player->getWood() + 1);
                break;
            case CLAY:
                player->setClay(player->getClay() + 1);
                break;
            case WHEAT:
                player->setWheat(player->getWheat() + 1);
                break;
            case STONE:
                player->setStone(player->getStone() + 1);
                break;
            case SHEEP:
                player->setSheep(player->getSheep() + 1);
                break;
        }
    }
    return hasResources? NO_ERROR_t: ERROR_NO_RESOURCES;

}

void Catan::takeResources(Player * player, tradeIn resources) {// te saca la cantidad de recursos que dice tradeIn resources (cuando sale el robber)
	player->setWood(player->getWood() - resources.wood);
	player->setClay(player->getClay() - resources.clay);
	player->setSheep(player->getSheep() - resources.sheep);
	player->setWheat(player->getWheat() - resources.wheat);
	player->setStone(player->getStone() - resources.stone);
}

errorT Catan::getResourceBuildings(Player* player, char type, int qty)
{
	switch (type) {
	case BOSQUE:
		player->setWood(player->getWood() + qty);
		break;
	case COLINA:
		player->setClay(player->getClay() + qty);
		break;
	case PASTO:
		player->setSheep(player->getSheep() + qty);
		break;
	case CAMPO:
		player->setWheat(player->getWheat() + qty);
		break;
	case MONTANIA:
		player->setStone(player->getStone() + qty);
		break;
	case DESIERTO:
		return ERROR_GET_RESOURCE;
	}
	return NO_ERROR_t;
}

void Catan::moveRobber(Player * player, Player * other, const Coordinates &newRobberCoordinates) {
	getRobber()->setTokenCoordinates(newRobberCoordinates);
	bool hasBuilding = false;
	for (int i = 0; i < MAX_BUILDING_AMMOUNT && !hasBuilding; i++) {
		Coordinates * coord = other->getBuildings()[i].getTokenCoordinates();
		if ((coord->getX() == getRobber()->getTokenCoordinates()->getX()) || (coord->getY() == getRobber()->getTokenCoordinates()->getX()) || (coord->getZ() == getRobber()->getTokenCoordinates()->getX())) {
			hasBuilding = true;
		}
	}
	if (hasBuilding && ((other->getClay() + other->getWood() + other->getWheat() + other->getSheep() + other->getStone()) > 0)) {
		char * resource = nullptr;
		int dim = 0;
		for (int i = 0; i < player->getWood(); i++) {
			if (dim % BLOCK == 0) {
				resource = (char *)realloc(resource, (dim + BLOCK) * sizeof(char));
			}
			resource[dim++] = WOOD;
		}
		for (int i = 0; i < player->getClay(); i++) {
			if (dim % BLOCK == 0) {
				resource = (char *)realloc(resource, (dim + BLOCK) * sizeof(char));
			}
			resource[dim++] = CLAY;
		}
		for (int i = 0; i < player->getSheep(); i++) {
			if (dim % BLOCK == 0) {
				resource = (char *)realloc(resource, (dim + BLOCK) * sizeof(char));
			}
			resource[dim++] = SHEEP;
		}
		for (int i = 0; i < player->getWheat(); i++) {
			if (dim % BLOCK == 0) {
				resource = (char *)realloc(resource, (dim + BLOCK) * sizeof(char));
			}
			resource[dim++] = WHEAT;
		}
		for (int i = 0; i < player->getStone(); i++) {
			if (dim % BLOCK == 0) {
				resource = (char *)realloc(resource, (dim + BLOCK) * sizeof(char));
			}
			resource[dim++] = STONE;
		}

		switch (resource[rand() % dim]) {
		case CLAY:
			other->setClay(other->getClay() - 1);
			player->setClay(player->getClay() + 1);
			break;
		case SHEEP:
			other->setSheep(other->getSheep() - 1);
			player->setSheep(player->getSheep() + 1);
			break;
		case WHEAT:
			other->setWheat(other->getWheat() - 1);
			player->setWheat(player->getWheat() + 1);
			break;
		case STONE:
			other->setStone(other->getStone() - 1);
			player->setStone(player->getStone() + 1);
			break;
		case WOOD:
			other->setWood(other->getWood() - 1);
			player->setWood(player->getWood() + 1);
			break;
		}
		free(resource);
	}
}

void Catan::getResource(int dice, Player * player) {
	for (int i = 0; i < 19; i++) {
		if ((map.getIslands()[i].getNumber() == dice) && (!map.getIslands()[i].getIsBlocked()))
		{
			for (int j = 0; j < player->getCitiesBuilt() + player->getTownsBuilt(); j++) {
				if ((player->getBuildings()[j].getTokenCoordinates()->getX() == map.getIslands()[i].getPosition()) || (player->getBuildings()[j].getTokenCoordinates()->getY() == map.getIslands()[i].getPosition()) || (player->getBuildings()[j].getTokenCoordinates()->getZ() == map.getIslands()[i].getPosition())) {
					if (player->getBuildings()[j].getAbstractToken() == TOWN_L) {
						getResourceBuildings(player, map.getIslands()[i].getType(), 1);
					}
					else { //deberia ser city
                        getResourceBuildings(player, map.getIslands()[i].getType(), 2);
					}
				}
			}
		}
	}
}

Map * Catan::getMap() {
	return &map;
}
//Catan::~Catan()
//{
//}

Player * Catan::getPlayer1() {
	return player1;
}
Player * Catan::getPlayer2() {
	return player2;
}

Rules Catan::getRules() {
	return rules;
}

Player * Catan::getLongestRoadPlayer() {
	return longestRoad;
}

void Catan::setLongestRoadPlayer(Player * player) {
	this->longestRoad = player;
}

bool Catan::canBuildTown(Player * player, Player * other, const Coordinates &coordinates, bool isFirstTurn) {
	setError(rules.canBuildTown(player, other, coordinates, isFirstTurn));
    return (catanError == NO_ERROR_t);
}
bool Catan::canBuildCity(Player *player, const Coordinates &coordinates) {
	setError(rules.canBuildCity(player, coordinates));
    return (catanError == NO_ERROR_t);

}
bool Catan::canBuildRoad(Player * player, Player * other, const Coordinates &coordinates, bool isFirstTurn){
    if(isFirstTurn)
        setError(rules.firstCanBuildRoad(player, coordinates));
    else
        setError(rules.canBuildRoad(player, other, coordinates));
    return catanError == NO_ERROR_t;
}

void Catan::setGame(Player * P1, Player * P2, char types[ISLANDS_AMMOUNT], char numbers[ISLANDS_AMMOUNT - 1], char dock[DOCKS_AMMOUNT])
{
	this->player1 = P1;
	this->player2 = P2;
	this->catanError = NO_ERROR_t;
	//this->map = Map(types, numbers);

	//this->map.setIslands(types, numbers);
	//this->map.setDocks(dock);

	map.setDocks(dock);
	map.setIslands(types, numbers);


	Coordinates dessertCoord;
	bool found = false;
	for (int i = 0; i < ISLANDS_AMMOUNT && !found; i++) {
		if (map.getIslands()[i].getType() == DESIERTO)
		{
			dessertCoord.setX(map.getIslands()[i].getPosition());
			map.getIslands()[i].setBlock(true);
			found = true;
		}
		else
			map.getIslands()[i].setBlock(false);
	}
	this->robber = Robber(dessertCoord);
}

void Catan::setGame(Player * P1, Player * P2)
{
	this->player1 = P1;
	this->player2 = P2;
	this->catanError = NO_ERROR_t;
	Coordinates dessertCoord;
	map.setDocks();
	map.setIslands();

	bool found = false;
	for (int i = 0; i < ISLANDS_AMMOUNT && !found; i++)
	{
		if (map.getIslands()[i].getType() == DESIERTO)
		{
			dessertCoord.setX(map.getIslands()[i].getPosition());
			map.getIslands()[i].setBlock(true);
			found = true;
		}
		else
		{
			map.getIslands()[i].setBlock(false);
		}
	}
	this->robber = Robber(dessertCoord);
}
