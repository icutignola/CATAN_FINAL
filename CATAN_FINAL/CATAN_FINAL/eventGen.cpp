#include "eventGen.h"


eventGen::eventGen()
{

}

genericEvent *eventGen::
getEvent()
{
	genericEvent * reEV = nullptr;
	if (GUI->isInput() == EV_EXIST)
	{
		input = GUI->getInput();
		switch (input)
		{
		case OFFER_TRADE:
			reEV = new cTrade;
			break;
		case PORT_TRADE:
			reEV = new cPortTrade;
			break;
		case BANK_TRADE:
			reEV = new cBankTrade;
			break;
		case BUILD:
			reEV = new cBuild;
			break;
			/*case MaxScore:
				reEV = new cMaxScore;
				break;
			case Invalid:
				reEV = new cInvalid;
				break;*/
		case PASS:
			reEV = new cEndOfTurn;
			break;
		case DICES_ARE:
			reEV = new cDiceThrew;
			break;
		case QUIT:
			reEV = new cEventQuit;
			break;
		}
	}

	return reEV;
}

void eventGen::seteventGen(io * GUI_i, client * COMUC_i, server * COMUS_i, int myStatus_i)
{
	GUI = GUI_i;
	COMU_c = COMUC_i;
	COMU_s = COMUS_i;
	myStatus = myStatus_i;
}

eventGen::~eventGen()
{
}
