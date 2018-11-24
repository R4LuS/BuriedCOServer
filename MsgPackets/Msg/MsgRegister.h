#pragma once

#include "Msg.h"

class MsgRegister : public Msg
{
public:
	typedef struct {
		Msg::Header header;
		uint8_t username[16];
		uint8_t nickname[16];
		uint8_t password[16];
		uint16_t model;
		uint16_t cClass;
		uint32_t clientID;
	}MsgInfo;

private:


};