#pragma once

#include "Msg.h"

class MsgAccount : public Msg
{
public:
	typedef struct {
		Msg::Header header;
		uint8_t name[16];
		uint8_t password[16];
		uint8_t server[16];
	}MsgInfo;

public:
	MsgAccount(uint8_t *);

	MsgInfo *getData() { return data; }
private:
	MsgInfo * data;
};