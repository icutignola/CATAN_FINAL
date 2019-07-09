
#pragma once
#include "eventHandling.h"
#include "defines.h"
#include "auxiliar.h"
#include "io.h"
#include "client.h"
#include "server.h"


enum implEvent : eventTypes { Trade, PortTrade, BankTrade, Build, MaxScore, Invalid, EndOfTurn, DiceThrew, EventQuit };

class cTrade : public genericEvent
{
public:
	eventTypes getType() { return Trade; }
};

class cPortTrade : public genericEvent
{
public:
	eventTypes getType() { return PortTrade; }
};

class cBankTrade : public genericEvent
{
public:
	eventTypes getType() { return BankTrade; }
};

class cBuild : public genericEvent
{
public:
	eventTypes getType() { return Build; }
};

class cMaxScore : public genericEvent
{
public:
	eventTypes getType() { return MaxScore; }
};

class cInvalid : public genericEvent
{
public:
	eventTypes getType() { return Invalid; }
};

class cEndOfTurn : public genericEvent
{
public:
	eventTypes getType() { return EndOfTurn; }
};

class cDiceThrew : public genericEvent
{
public:
	eventTypes getType() { return DiceThrew; }
};

class cEventQuit : public genericEvent
{
public:
	eventTypes getType() { return EventQuit; }
};
