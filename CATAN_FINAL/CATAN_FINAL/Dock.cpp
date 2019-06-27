#include "Dock.h"


Dock::Dock(char position, char type) {
    this->position = position;
    this->tradeType = type;
}

Dock::Dock(){
    position = EMPTY;
    tradeType = DESIERTO;
}

char Dock::getPosition() {
    return this->position;
}
char Dock::getTradeType() {
    return this->tradeType;
}

Dock::~Dock() = default;