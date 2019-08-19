#pragma once

#include "evtypes.h"

class comuGen : public eventGenerator
{
private:
	io* GUI;
	client* COMU_c;
	server* COMU_s;
	message mensaje;
	int myStatus;		// Mi estado en la comunicacion
	bool messageExist;
	bool ackReceived;
	unsigned char input;

public:
	comuGen();
	genericEvent * getEvent();
	void setComuGen(io * GUI_i, client * COMUC_i, server * COMUS_i, int myStatus_i);
	~comuGen();
};

