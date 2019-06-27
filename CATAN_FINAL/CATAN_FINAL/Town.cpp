#include "Town.h"



Town::Town(const Coordinates &coordinates)
{
    this->setAbstractToken(TOWN_L);
    this->setTokenCoordinates(coordinates);
}

Town::~Town() = default;