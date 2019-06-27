#include "AbstractToken.h"

AbstractToken::AbstractToken() {
    value = 0;
}

//AbstractToken::AbstractToken(char value, Coordinates coordinates)
//{
//    this->value = value;
//    this->tokenCoordinates = coordinates;
//}

AbstractToken::~AbstractToken() = default;

Coordinates * AbstractToken::getTokenCoordinates() {
    return &tokenCoordinates;
}
void AbstractToken::setTokenCoordinates(const Coordinates &coordinates) {
    this->tokenCoordinates = coordinates;
}

void AbstractToken::setAbstractToken(char _value) {
    value = _value;
}
char AbstractToken::getAbstractToken() {
    return this->value;
}
