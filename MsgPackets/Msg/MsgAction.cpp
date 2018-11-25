
#include "MsgAction.h"

MsgAction::MsgAction() :
	Msg()
{

}

MsgAction::MsgAction(MsgInfo *nData) :
	Msg(), data(nData)
{
	size = sizeof(MsgInfo);
}