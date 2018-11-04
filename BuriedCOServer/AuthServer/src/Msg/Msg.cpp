#include "Msg.h"

#include <iostream>

Msg::Msg(uint16_t size, uint8_t *aBuf) {
	this->size = size;
	this->mBuf = aBuf;
}

void Msg::printBuf() {
	for (int i = 0; i < size; i++) {
		fprintf(stdout, "%20X ", mBuf[i]);
	}
	fprintf(stdout, "\n");
}