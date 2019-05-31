#pragma once
#include "AbstractToken.h"
#include "defines.h"
class Road :
        public AbstractToken
{
public:
    Road();
    Road(Coordinates); //crea una road en coordinates
    ~Road();
    Road& operator= (Road road); //sobrecarga del operador =
};
