
#include "MsgAccount.h"

MsgAccount::MsgAccount(uint8_t *data) :
	Msg(sizeof(MsgInfo), (uint8_t *)data), data((MsgInfo *)data)
{
}