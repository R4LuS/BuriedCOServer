
#include "MsgAccount.h"


MsgAccount::MsgAccount() :
	Msg()
{

}


MsgAccount::MsgAccount(uint8_t *data) :
	Msg(), data((MsgInfo *)data)
{
}