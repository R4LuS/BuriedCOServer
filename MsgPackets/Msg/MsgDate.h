#pragma once

#include "Msg.h"

class MsgDate : public Msg
{
public:
	typedef struct {
		Msg::Header header;
		uint32_t padding;
		uint32_t year;
		uint32_t month;
		uint32_t dayOfYear;
		uint32_t day;
		uint32_t hour;
		uint32_t minute;
		uint32_t second;
	}MsgInfo;

public:
	MsgDate();

	uint8_t *getInfo() { return (uint8_t *)data; }
	uint16_t getSize() { return size; }

private:
	MsgInfo *data;
	uint16_t size;
};