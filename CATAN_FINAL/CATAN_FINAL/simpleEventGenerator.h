#pragma once
//#include <array>
//
//#include "eventHandling.h"
//
//enum implEvent : eventTypes { Trade, PortTrade, BankTrade, Build, MaxScore, Invalid, EndOfTurn, DiceThrew, EventQuit };
//
//class cTrade : public genericEvent
//{
//public:
//	eventTypes getType() override { return Trade; }
//};
//
//class cPortTrade : public genericEvent
//{
//public:
//	eventTypes getType() override { return PortTrade; }
//};
//
//class cBankTrade : public genericEvent
//{
//public:
//	eventTypes getType() override { return BankTrade; }
//};
//
//class cBuild: public genericEvent
//{
//public:
//	eventTypes getType() override { return Build; }
//};
//
//class cMaxScore : public genericEvent
//{
//public:
//	eventTypes getType() override { return MaxScore; }
//};
//
//class cInvalid : public genericEvent
//{
//public:
//	eventTypes getType() override { return Invalid; }
//};
//
//class cEndOfTurn : public genericEvent
//{
//public:
//	eventTypes getType() override { return EndOfTurn; }
//};
//
//class cDiceThrew : public genericEvent
//{
//public:
//	eventTypes getType() override { return DiceThrew; }
//};
//
//class cEventQuit : public genericEvent
//{
//public:
//	eventTypes getType() override { return EventQuit; }
//};
//
//class simpleEventGenerator : public eventGenerator
//{
//
//	public:
//	simpleEventGenerator();
//	genericEvent * getEvent() override;
//	
//	private:
//
//	unsigned int pos;
//	const std::array<implEvent, 9> testEvs = { DiceThrew,EndOfTurn,DiceThrew,Trade,Build,EndOfTurn,Build,MaxScore, EventQuit };
//
//	//{ Trade, PortTrade, BankTrade, Build, MaxScore, Invalid, EndOfTurn, DiceThrew, EventQuit }
//};
