
#include "MsgLoginProofA.h"



MsgLoginProofA::MsgLoginProofA(const uint8_t* aEncryptIV, const uint8_t* aDecryptIV,
	const std::string& aP, const std::string& aG, const std::string& aA) :
	Msg()
{
	srand(time(NULL));
	info = new MsgInfo;
	for (size_t i = 0; i < MsgLoginProofA::PADDING_LEN; ++i)
	{
		info->Padding[i] = rand();
	}
	info->JunkSize = MsgLoginProofA::JUNK_LEN;
	for (size_t i = 0; i < MsgLoginProofA::JUNK_LEN; ++i)
	{
		info->Junk[i] = rand();
	}
	// Will include the TQServer seal (added by send())...
	info->Size = (int32_t)(sizeof(MsgInfo) + aP.length() + aG.length() + aA.length() - 3 - MsgLoginProofA::PADDING_LEN + 8);
	this->size = info->Size - 8 + MsgLoginProofA::PADDING_LEN;
	info->EnIVSize = Blowfish::BLOCK_SIZE;
	memcpy(info->EnIV, aEncryptIV, Blowfish::BLOCK_SIZE);
	info->DeIVSize = Blowfish::BLOCK_SIZE;
	memcpy(info->DeIV, aDecryptIV, Blowfish::BLOCK_SIZE);
	uint8_t* ptr = (uint8_t*)&info->PSize;

	*((int32_t*)(ptr)) = (int32_t)aP.length();
	ptr += sizeof(int32_t);
	memcpy(ptr, aP.c_str(), aP.length());
	ptr += aP.length();

	*((int32_t*)(ptr)) = (int32_t)aG.length();
	ptr += sizeof(int32_t);
	memcpy(ptr, aG.c_str(), aG.length());
	ptr += aG.length();

	*((int32_t*)(ptr)) = (int32_t)aA.length();
	ptr += sizeof(int32_t);
	memcpy(ptr, aA.c_str(), aA.length());
	ptr += aA.length();
}