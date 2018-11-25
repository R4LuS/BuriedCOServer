
#include "MsgDate.h"


MsgDate::MsgDate() :
	Msg()
{
	//1033
	size = sizeof(MsgInfo);
	data = new MsgInfo;
	data->header.packetID = 1033;
	data->header.packetSize = size;
	data->padding = 0;
	data->year = 2018;
	data->month = 11;
	data->dayOfYear = 0;
	data->day = 25;
	data->hour = 20;
	data->minute = 35;
	data->second = 50;
}