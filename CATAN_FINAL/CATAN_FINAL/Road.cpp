#include "Road.h"

Road::Road()
{
    this->setAbstractToken(ROAD_L);
}

Road::Road(const Coordinates &coordinates)
{
    this->setAbstractToken(ROAD_L);
    this->setTokenCoordinates(coordinates);
}


Road::~Road() = default;

Road& Road :: operator= (Road road)
{
    getTokenCoordinates()->setX(road.getTokenCoordinates()->getX());
    getTokenCoordinates()->setY(road.getTokenCoordinates()->getY());
    getTokenCoordinates()->setZ(road.getTokenCoordinates()->getZ());
    return *this;
}