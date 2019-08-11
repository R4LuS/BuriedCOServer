#pragma once

#include "Common/common.h"

class Msg {

public:
	typedef struct {
		uint16_t packetSize;
		uint16_t packetID;
	}Header;


	Msg();
	virtual uint8_t *getInfo() { return 0; }
	virtual uint16_t getSize() { return 0; }
private:
	
protected:
};