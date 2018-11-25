
#include "MsgItem.h"

MsgItem::MsgItem() :
	Msg()
{

}

MsgItem::MsgItem(MsgInfo *nData) :
	Msg()
{
	data = nData;
	size = sizeof(MsgInfo *);
}