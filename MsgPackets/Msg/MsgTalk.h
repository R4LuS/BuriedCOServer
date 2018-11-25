#pragma once

#include "Msg.h"
#include "ThirdParty/third/stringpacker.h"

const size_t MAX_NAMESIZE = 16;
const size_t MAX_WORDSSIZE = 255;


class MsgTalk : public Msg
{

public:
	enum Channel
	{
		CHANNEL_NORMAL = 2000,
		CHANNEL_PRIVATE = CHANNEL_NORMAL + 1,
		CHANNEL_ACTION = CHANNEL_NORMAL + 2,
		CHANNEL_TEAM = CHANNEL_NORMAL + 3,
		CHANNEL_SYNDICATE = CHANNEL_NORMAL + 4,
		CHANNEL_SYSTEM = CHANNEL_NORMAL + 5,
		CHANNEL_FAMILY = CHANNEL_NORMAL + 6,
		CHANNEL_TALK = CHANNEL_NORMAL + 7,
		CHANNEL_YELP = CHANNEL_NORMAL + 8,
		CHANNEL_FRIEND = CHANNEL_NORMAL + 9,
		CHANNEL_GLOBAL = CHANNEL_NORMAL + 10,
		CHANNEL_GM = CHANNEL_NORMAL + 11,
		CHANNEL_WHISPER = CHANNEL_NORMAL + 12,
		CHANNEL_GHOST = CHANNEL_NORMAL + 13,
		CHANNEL_SERVE = CHANNEL_NORMAL + 14,
		CHANNEL_MY = CHANNEL_NORMAL + 15,

		CHANNEL_REGISTER = CHANNEL_NORMAL + 100,
		CHANNEL_ENTRANCE = CHANNEL_NORMAL + 101,
		CHANNEL_SHOP = CHANNEL_NORMAL + 102,
		CHANNEL_PETTALK = CHANNEL_NORMAL + 103,
		CHANNEL_CRYOUT = CHANNEL_NORMAL + 104,
		CHANNEL_WEBPAGE = CHANNEL_NORMAL + 105,

		CHANNEL_NEWMESSAGE = CHANNEL_NORMAL + 106,
		CHANNEL_TASK = CHANNEL_NORMAL + 107,

		CHANNEL_SYNWAR_FIRST = CHANNEL_NORMAL + 108,
		CHANNEL_SYNWAR_NEXT = CHANNEL_NORMAL + 109,

		CHANNEL_LEAVEWORD = CHANNEL_NORMAL + 110,
		CHANNEL_SYNANNOUNCEG = CHANNEL_NORMAL + 111,
		CHANNEL_SYNANNOUNCEL = CHANNEL_NORMAL + 114,

		CHANNEL_MESSAGEBOX = CHANNEL_NORMAL + 112,
		CHANNEL_REJECT = CHANNEL_NORMAL + 113,

		CHANNEL_TRACE = CHANNEL_NORMAL + 115,

		CHANNEL_MSG_TRAGE = CHANNEL_NORMAL + 201,
		CHANNEL_MSG_FRIEND = CHANNEL_NORMAL + 202,
		CHANNEL_MSG_TEAM = CHANNEL_NORMAL + 203,
		CHANNEL_MSG_SYN = CHANNEL_NORMAL + 204,
		CHANNEL_MSG_OTHER = CHANNEL_NORMAL + 205
	};

	enum Style
	{
		STYLE_NORMAL = 0,
		STYLE_SCROLL = 0x0001,
		STYLE_FLASH = 0x0002,
		STYLE_BLAST = 0x0008
	};

	/* basic colors ARGB code */
	static const uint32_t COLOR_RED = 0x00FF0000;
	static const uint32_t COLOR_MAGENTA = 0x00FF00FF;
	static const uint32_t COLOR_BLUE = 0x000000FF;
	static const uint32_t COLOR_CYAN = 0x0000FFFF;
	static const uint32_t COLOR_GREEN = 0x0000FF00;
	static const uint32_t COLOR_YELLOW = 0x00FFFF00;
	static const uint32_t COLOR_WHITE = 0x00FFFFFF;

#pragma pack(push, 1)
	typedef struct
	{
		Msg::Header Header;
		uint32_t Color; // ARGB code
		int16_t Channel;
		int16_t Style;
		int32_t Timestamp;
		uint32_t HearerLook;
		uint32_t SpeakerLook;
		uint8_t Buf[1]; // Speaker, Hearer, Emotion, Words
		/*uint8_t speakerLen;
		uint8_t aSpeaker[MAX_NAMESIZE];
		uint8_t hearerLen;
		uint8_t aHearer[MAX_NAMESIZE];
		uint8_t emotionLen;
		uint8_t aEmotion[MAX_NAMESIZE];
		uint8_t wordsLen;
		uint8_t aWords[MAX_WORDSSIZE];*/
	}MsgInfo;
#pragma pack(pop)

	MsgTalk(const char* aSpeaker, const char* aHearer, const char* aWords,
		Channel aChannel, uint32_t aColor = COLOR_WHITE);

	/*MsgTalk(const Player& aSpeaker, const Player& aHearer, const char* aWords,
		Channel aChannel, uint32_t aColor = COLOR_WHITE);*/

	uint8_t *getInfo() { return (uint8_t *)mInfo; }
	uint16_t getSize() { return size; }

private:
	void create(const char* aSpeaker, const char* aHearer, const char* aEmotion,
			const char* aWords, Channel aChannel, uint32_t aColor);

private:
	MsgInfo *mInfo;
	uint16_t size;
};