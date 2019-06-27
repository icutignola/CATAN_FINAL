#include "City.h"



City::City(const Coordinates &coordinates)
{
    this->setAbstractToken(CITY_L);
    this->setTokenCoordinates(coordinates);
}

City::~City() = default;