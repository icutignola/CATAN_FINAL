#include "comuGen.h"

comuGen::comuGen()
{
}
genericEvent *comuGen::
getEvent()
{
	genericEvent * reEV = nullptr;
	
	//TENES QUE HACER DOS CASE, UNO PARA CASA SWITCH (CLIENTE Y SERVER)
	int n = 0;
	if (myStatus == IM_SERVER)
	{
		n = 0;
		while ((messageExist == false) && (n < 5)) //Que intente 5 veces, por las dudas
		{
			messageExist = COMU_s->isMessage();
			n++;
		}
		if (messageExist == true)
		{
			mensaje = COMU_s->getMessage(); //Obtengo el mensaje
			switch (mensaje.identifier)
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

	}
	else if (myStatus == IM_CLIENT)
	{
		n = 0;
		while (!messageExist || n < 5) //Que intente 5 veces, por las dudas
		{
			messageExist = COMU_c->isMessage();
			n++;
		}
		if (messageExist == true)
		{
			mensaje = COMU_c->getMessage(); //Obtengo el mensaje
			switch (mensaje.identifier)
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
	}

	return reEV;
}
void comuGen::setComuGen(io * GUI_i, client * COMUC_i, server * COMUS_i, int myStatus_i)
{
	GUI = GUI_i;
	COMU_c = COMUC_i;
	COMU_s = COMUS_i;
	myStatus = myStatus_i;
}

comuGen::~comuGen()
{
}
