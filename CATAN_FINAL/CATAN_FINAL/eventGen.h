#pragma once

#include "evtypes.h"

class eventGen : public eventGenerator
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
	eventGen();
	genericEvent * getEvent();
	void seteventGen(io * GUI_i, client * COMUC_i, server * COMUS_i, int myStatus_i);
	~eventGen();
};
