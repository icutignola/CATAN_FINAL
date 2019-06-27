#pragma once
#include "Coordinates.h"

class AbstractToken
{
public:
    /** --------- Constructor --------- */

    /** Se posiciona el token en la coordenada (EMPTY, EMPTY, EMPTY) y tiene un identificador = 0 */
    AbstractToken();
    //AbstractToken(char _value, Coordinates coordinates); //Se manda el identificador de la pieza (ver defines.h) y las coordenadas donde la quiero poner


    /** --------- Getters --------- */

    /** Devuelve el identificador asignado a la pieza (los identificadores estan definidos en defines.h) */
    char getAbstractToken();

    /** Devuelve una referencia a las coordenadas de la pieza */
    Coordinates * getTokenCoordinates();


    /** --------- Setters --------- */

    /** Cambia el identificador de la pieza a "value" */
    void setAbstractToken(char value);

    /** Cambia las coordenadas donde esta posicionado el token */
    void setTokenCoordinates(const Coordinates &coordinates);


    /** --------- Destructor --------- */

    ~AbstractToken();


private:
    Coordinates tokenCoordinates;
    char value;
};