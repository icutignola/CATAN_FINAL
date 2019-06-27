#pragma once

#include "defines.h"

class Dock
{
public:
    /** --------- Constructor --------- */

    /** Crea un puerto de tipo type, en la posicion coordinate */
    Dock(char coordinate, char type);

    /** Crea un puerto de tipo DESIERTO en la posicion EMPTY (Nunca dejar asi al puerto) */
    Dock();

    /** --------- Destructor --------- */
    ~Dock();

    /** --------- Getters --------- */
    char getPosition();
    char getTradeType();
private:
    char position; // Coordenada del puerto
    char tradeType; // Tipo de intercambio en el puerto


};
