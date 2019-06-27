#pragma once
#include "defines.h"
class Coordinates
{
public:
    /** --------- Constructor --------- */

    /** Crea coordenadas (EMPTY, EMPTY, EMPTY). */
    Coordinates();

    /** Crea coordenadas (x,y,z). */
    Coordinates(char x, char y, char z); //x y z

    /** Constructor copiador */
    Coordinates(const Coordinates &coordinates);

    /** --------- Getters --------- */
    char getX();
    char getY();
    char getZ();

    /** --------- Setters --------- */
    void setX(char x);
    void setY(char y);
    void setZ(char z);

    /** Sobrecarga del operador ==. @return true si coordinates tiene las misma coordanadas que this (sin importar el orden) */
    bool operator == (Coordinates coordinates); // sobrecarga operador == (compara todos con todos sin importar el orden)

    /** Sobrecarga del operador asignacion. Copia coordinates en this*/
    Coordinates& operator = (Coordinates coordinates);
private:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};