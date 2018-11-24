#pragma once

#include "Common/common.h"

class Msg {

public:
	typedef struct {
		uint16_t packetSize;
		uint16_t packetID;
	}Header;


	Msg(uint16_t size, uint8_t *aBuf);
	const uint8_t *getBuf() const { return mBuf; }
	size_t getSize() const { return size; }
	void printBuf();
private:
	size_t size;
protected:
	uint8_t *mBuf;
};