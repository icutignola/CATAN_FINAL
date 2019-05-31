#pragma once
#include <array>

#include "eventHandling.h"

//enum implEvent : eventTypes { EventA, EventB, EventC, EventD, EventQuit };
//
//class cEventA : public genericEvent
//{
//public:
//	eventTypes getType(void) { return EventA; }
//};
//
//class cEventB : public genericEvent
//{
//public:
//	eventTypes getType(void) { return EventB; }
//};
//
//class cEventC : public genericEvent
//{
//public:
//	eventTypes getType(void) { return EventC; }
//};
//
//class cEventD : public genericEvent
//{
//public:
//	eventTypes getType(void) { return EventD; }
//};

enum implEvent : eventTypes { Trade, PortTrade, BankTrade, Build, MaxScore, Invalid, EndOfTurn, DiceThrew, EventQuit };

class cTrade : public genericEvent
{
public:
	eventTypes getType(void) { return Trade; }
};

class cPortTrade : public genericEvent
{
public:
	eventTypes getType(void) { return PortTrade; }
};

class cBankTrade : public genericEvent
{
public:
	eventTypes getType(void) { return BankTrade; }
};

class cBuild: public genericEvent
{
public:
	eventTypes getType(void) { return Build; }
};

class cMaxScore : public genericEvent
{
public:
	eventTypes getType(void) { return MaxScore; }
};

class cInvalid : public genericEvent
{
public:
	eventTypes getType(void) { return Invalid; }
};

class cEndOfTurn : public genericEvent
{
public:
	eventTypes getType(void) { return EndOfTurn; }
};

class cDiceThrew : public genericEvent
{
public:
	eventTypes getType(void) { return DiceThrew; }
};

class cEventQuit : public genericEvent
{
public:
	eventTypes getType(void) { return EventQuit; }
};

class simpleEventGenerator : public eventGenerator
{

	public:
	simpleEventGenerator();
	genericEvent * getEvent(void);
	
	private:

	unsigned int pos;
	const std::array<implEvent, 14> testEvs = { Trade,Build,PortTrade,BankTrade,EndOfTurn,DiceThrew,Trade,PortTrade,BankTrade,Build,EndOfTurn,Build,MaxScore, EventQuit };

	//{ Trade, PortTrade, BankTrade, Build, MaxScore, Invalid, EndOfTurn, DiceThrew, EventQuit }
};
