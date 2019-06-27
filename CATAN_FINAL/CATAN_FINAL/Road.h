#pragma once
#include "AbstractToken.h"
#include "defines.h"
class Road :
        public AbstractToken
{
public:
    /** --------- Constructores --------- */

    /** Crea un camino en las coordenadas (EMPTY, EMPTY, EMPTY) e identificador ROAD_L*/
    Road();

    /** Crea un camino en las coordenadas coordinates e identificador ROAD_L */
    Road(const Coordinates &coordinates); //crea una road en coordinates

    /** --------- Destructor --------- */
    ~Road();

    /** Sobrecarga del operador asignacion, copia las coordenadas del parametro */
    Road& operator= (Road road);
};
