#pragma once
#include "defines.h"
class Coordinates
{
public:
    Coordinates();
    Coordinates(char , char , char); //x y z
    Coordinates(const Coordinates&); //copiador
    //self explaining
    char getX();
    char getY();
    char getZ();
    void setX(char );
    void setY(char );
    void setZ(char );

    bool operator == (Coordinates); // sobrecarga operador == (compara todos con todos sin importar el orden)
    Coordinates& operator = (Coordinates);// copiador
private:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};