#pragma once

#include "Msg.h"

class MsgConnect : public Msg
{
public:
	typedef struct {
		Msg::Header header;
		uint32_t clientID;
		uint32_t additionalData;
		uint16_t clientBuildVersion;
		uint8_t language[8];
		uint32_t fileContent;
	}MsgInfo;

public:


private:

};