
#include "MsgDate.h"

MsgDate::MsgDate(Date date) :
	Msg()
{
	//1033
	size = sizeof(MsgInfo);
	data = new MsgInfo;
	data->header.packetID = 1033;
	data->header.packetSize = size;
	data->padding = 0;
	data->year = date.year - 1900;
	data->month = date.month - 1;
	data->dayOfYear = 0;
	data->day = date.day;
	data->hour = date.hour;
	data->minute = date.min;
	data->second = date.second;
}