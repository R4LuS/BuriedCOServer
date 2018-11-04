
#include "MsgTalk.h"

#include <string>

MsgTalk::MsgTalk(const char* aSpeaker, const char* aHearer, const char* aWords,
	Channel aChannel, uint32_t aColor)
	: Msg()
{
	size = sizeof(MsgInfo) + strlen(aSpeaker) + strlen(aHearer) + strlen(aWords) + 4;
	// size = 6 8 8
	mInfo = (MsgInfo *)new uint8_t[size];
	create(aSpeaker, aHearer, "", aWords, aChannel, aColor);
}



void
MsgTalk::create(const char* aSpeaker, const char* aHearer, const char* aEmotion,
	const char* aWords, Channel aChannel, uint32_t aColor)
{
	ASSERT(aSpeaker != nullptr && aSpeaker[0] != '\0');
	ASSERT(aHearer != nullptr && aHearer[0] != '\0');
	ASSERT(aEmotion != nullptr);
	ASSERT(aWords != nullptr && aWords[0] != '\0');

	if (strlen(aSpeaker) < MAX_NAMESIZE &&
		strlen(aHearer) < MAX_NAMESIZE &&
		strlen(aEmotion) < MAX_NAMESIZE &&
		strlen(aWords) < MAX_WORDSSIZE)
	{
		mInfo->Header.packetSize = size;
		mInfo->Header.packetID = 1004;
		
		mInfo->Color = aColor;
		mInfo->Channel = (uint16_t)aChannel;
		mInfo->Style = (int16_t)STYLE_NORMAL;
		mInfo->Timestamp = timeGetTime();
		mInfo->HearerLook = 0;
		mInfo->SpeakerLook = 0;

		mInfo->Buf[0] = 0;
		StringPacker packer(mInfo->Buf);
		packer.addString(aSpeaker);
		packer.addString(aHearer);
		packer.addString(aEmotion);
		packer.addString(aWords);


	}
	else
	{
		
	}
}