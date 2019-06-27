#pragma once
#include "defines.h"
#include "auxiliar.h"
#include "AbstractBuilding.h"
#include "Dock.h"
#include "Town.h"
#include "City.h"
#include "Road.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
class Player {

public:
    /** --------- Constructores --------- */
    Player();
    Player(string name); // constructor


    /** --------- Getters --------- */
    /** @return la cantidad de cada recurso que tiene el jugador */
    int getWood();
    int getClay();
    int getSheep();
    int getWheat();
    int getStone();

    int getVictoryPoints();

    /** @return cantidad de tokens de ese tipo que hay en el mapa */
    int getTownsBuilt();
    int getCitiesBuilt();
    int getRoadsBuilt();

    AbstractBuilding * getBuildings(); // devuelve un array con los edificios (towns y cities) que construyo el player
    Road * getRoads(); // devuelve un array con los caminos construidos por el player
	const char* getName();


    /** --------- Setters --------- */
    void setWood(int wood);
	void setName(string name);
    void setClay(int clay);
    void setSheep(int sheep);
    void setWheat(int wheat);
    void setStone(int stone);
    void setTownsBuilt(int towns);
    void setCitiesBuilt(int cities);
    void setRoadsBuilt(int roads);
    void setVictoryPoints(int victoryPoints);


    /** Tira un solo dado */
    int throwDice();

    /** Verifica que el jugador tenga todos los recursos de tradeIn */
	bool hasResources(tradeIn resources);// mira si tiene resources para tradear

	//void buyDevCard(void);// opcional
	//void throwDevelopment(developmentCard); // hacer clase development card

	

private:
    int victoryPoints;
    AbstractBuilding buildings[MAX_BUILDING_AMMOUNT];
    Road roads[MAX_ROAD_AMMOUNT];
	string name;
    int townsBuilt;
    int citiesBuilt;
    int roadsBuilt;
    int wood;
    int sheep;
    int clay;
    int stone;
    int wheat;
    //char development[MAX_DEV_CARDS]; // por si usamos development cards
};