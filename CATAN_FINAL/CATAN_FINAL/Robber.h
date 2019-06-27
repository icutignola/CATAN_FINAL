#pragma once
#include "AbstractToken.h"
#include "defines.h"

class Robber :
        public AbstractToken
{
public:
    /** --------- Constructores --------- */
    /** Crea el robber en la coordenada (EMPTY, EMPTY, EMPTY) e identificador ROBBER_L */
    Robber();

    /** Crea el robber en la coordenada coordinates e identificador ROBBER_L */
    Robber(const Coordinates &coordinates);

    /** --------- Destructor --------- */
    ~Robber();
};
