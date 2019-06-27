#include "Island.h"
#include "defines.h"

Island::Island()
{
    position = EMPTY;
    islandNumber = 0;
    type = DESIERTO;
	isBlocked = false;
}

Island::Island(char position, int islandNumber, char type) {
	this->position = position;
	this->islandNumber = islandNumber;
	this->type = type;
	this->isBlocked = false; // todas las islas empiezan desbloqueadas
}


Island::~Island() = default;

char Island::getNumber() {
	return islandNumber;
}

bool Island::getIsBlocked() {
	return isBlocked;
}

char Island::getPosition() {
	return position;
}
void Island::setBlock(bool _isBlocked) {
	isBlocked = _isBlocked;
}


char Island::getType()
{
	return this->type;
}