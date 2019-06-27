#pragma once
#include "AbstractBuilding.h"
class City :
        public AbstractBuilding
{
public:
    /** --------- Constructor --------- */

    /** Se construye en la coordenada pasada como parametro y se le asigna el identificador CITY_L */
    City(const Coordinates &coordinates);


    /** --------- Destructor --------- */
    ~City();
};
