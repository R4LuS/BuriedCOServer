#pragma once

#include "Msg.h"
#include "../../Security/blowfish.h"

#include <iostream>
#include <ctime>

class MsgLoginProofA : public Msg 
{
public:
	/** The number of bytes of the padding. */
	static const size_t PADDING_LEN = 11;
	/** The number of bytes of the junk. */
	static const size_t JUNK_LEN = 12;

public:
	/* Unused internally ! */
#pragma pack(push, 1)
	typedef struct
	{
		uint8_t Padding[MsgLoginProofA::PADDING_LEN];
		int32_t Size;
		int32_t JunkSize;
		uint8_t Junk[MsgLoginProofA::JUNK_LEN];
		int32_t EnIVSize;
		uint8_t EnIV[Blowfish::BLOCK_SIZE];
		int32_t DeIVSize;
		uint8_t DeIV[Blowfish::BLOCK_SIZE];
		int32_t PSize;
		char P[1];
		int32_t GSize;
		char G[1];
		int32_t ASize;
		char A[1];
	}MsgInfo;
#pragma pack(pop)

	MsgLoginProofA(const uint8_t* aEncryptIV, const uint8_t* aDecryptIV,
		const std::string& aP, const std::string& aG, const std::string& aA);

	uint8_t *getInfo() { return (uint8_t *)info; }
	uint16_t getSize() { return size; }
private:
	MsgInfo * info;
	uint16_t size;
};