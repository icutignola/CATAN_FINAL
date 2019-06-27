#pragma once
#include "AbstractBuilding.h"
class Town :
        public AbstractBuilding
{
public:
    /** --------- Constructor --------- */
    /** Crea un town posicionado en coordinates con identificador TOWN_L */
    Town(const Coordinates &coordinates);

    /** --------- Destructor --------- */
    ~Town();
};