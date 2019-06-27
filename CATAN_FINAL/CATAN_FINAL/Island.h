#pragma once

class Island
{
public:
    /** --------- Constructores --------- */

    /** Crea una isla en EMPTY, de tipo DESIERTO, no bloqueada, con dado 0 */
	Island();

	/** Crea una isla en coordinate de tipo type, no bloqueada con dado diceNumber */
	Island(char coordinate, int diceNumber, char type);

    /** --------- Destructor --------- */
	~Island();

    /** --------- Getters --------- */
	char getType(); //tipo de recurso de la isla
	char getPosition(); //posicion de la isla
	char getNumber(); //numero de dado para activar isla
	bool getIsBlocked(); //si esta bloqueada por el robber

    /** --------- Setters --------- */
    void setBlock(bool blocked); //true si tiene el robber encima

private:
	char position;
	char islandNumber;
	char type;
	bool isBlocked;

};