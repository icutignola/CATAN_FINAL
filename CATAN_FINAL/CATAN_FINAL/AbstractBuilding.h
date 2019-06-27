#pragma once
#include "defines.h"
#include "AbstractToken.h"


/**
 * Clase abstracta para las construcciones dentro del juego (Town, City, Road)
*/

class AbstractBuilding:
	public AbstractToken 
{
public:
    /** --------- Constructor --------- */
	//AbstractBuilding(Coordinates); //Le pasas donde lo queres coonstruir

	/** Se construye en la coordenada (EMPTY, EMPTY, EMPTY) y tiene un identificador de 0 */
	AbstractBuilding();

	/** --------- Destructor --------- */
	~AbstractBuilding();

	/** Sobrecarga del operador asignacion, copia el parametro, no la referencia a él */
	AbstractBuilding& operator= (AbstractBuilding abstractBuilding); //sobrecarga del operador =
};