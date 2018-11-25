#pragma once

#include "Msg.h"

class MsgItem : public Msg
{
public:
	enum Action
	{
		/** No action specified. (Invalid) */
		ACTION_NONE = 0,
		/** Buy an item from a Npc shop. */
		ACTION_BUY = 1,             // to server, id: idNpc, data: idItemType
		/** Sell an item to a Npc shop. */
		ACTION_SELL = 2,            // to server, id: idNpc, data: idItem
		/** Drop an item on the ground. */
		ACTION_DROP = 3,            // to server, x, y
		/** Use an item (might equip). */
		ACTION_USE = 4,             // to server, data: position
		/** Equip an item at a specific position. */
		ACTION_EQUIP = 5,           // to client，通知装备物品
		/** Unequip an item at a specific position. */
		ACTION_UNEQUIP = 6,         // to server, data: position
		/** Split an item. */
		ACTION_SPLITITEM = 7,       // to server, data: num
		/** Combine an item. (Arrows ?) */
		ACTION_COMBINEITEM = 8,     // to server, data: id
		/** Query the saved money. */
		ACTION_QUERYMONEYSAVED = 9,	// to server/client, id: idNpc, data: nMoney
		/** Deposit money. */
		ACTION_SAVEMONEY = 10,      // to server, id: idNpc, data: nMoney
		/** Withdraw money. */
		ACTION_DRAWMONEY = 11,      // to server, id: idNpc, data: nMoney
		/** Drop money on the ground. */
		ACTION_DROPMONEY = 12,      // to server, x, y
		/** Spend money ??? */
		ACTION_SPENDMONEY = 13,     // 无意义，暂保留
		/** Repair an item at a Npc shop. */
		ACTION_REPAIR = 14,         // to server, return MsgItemInfo
		/** Repair all items. */
		ACTION_REPAIRALL = 15,      // to server, return ACTION_REPAIRAll, or not return if no money
		/** Ident an item. */
		ACTION_IDENT = 16,          // to server, return MsgItemInfo
		/** Update the durability of an item. */
		ACTION_DURABILITY = 17,     // to client, update durability
		/** Delete an equipment. */
		ACTION_DROPEQUIPMENT = 18,  // to client, delete equipment
		/** Improve the quality of an item. */
		ACTION_IMPROVE = 19,        // to server, improve equipment
		/** Upgrade the level of an item. */
		ACTION_UPLEV = 20,          // to server, upleve equipment
		/** Open a booth and request all items. */
		ACTION_BOOTH_QUERY = 21,    // to server, open booth, data is npc id
		/** Add an item to the booth. */
		ACTION_BOOTH_ADD = 22,      // to server/client(broadcast in table), id is idItem, data is money
		/** Delete an item from the booth. */
		ACTION_BOOTH_DEL = 23,      // to server/client(broadcast), id is idItem, data is npc id
		/** Buy an item from a booth. */
		ACTION_BOOTH_BUY = 24,      // to server, id is idItem, data is npc id
		/** Synchronise the amount (durability) of an item. */
		ACTION_SYNCHRO_AMOUNT = 25, // to client(data is amount)
		/** Use fireworks ??? */
		ACTION_FIREWORKS = 26,
		/** Ping evaluation */
		ACTION_COMPLETE_TASK = 27
	};
public:
	typedef struct {
		Msg::Header header;
		uint32_t pId;
		uint32_t argument;
		uint32_t action;
		uint32_t timestamp;
	}MsgInfo;

public:
	MsgItem();
	MsgItem(MsgInfo *);

	uint8_t *getInfo() { return (uint8_t *)data; }
	uint16_t getSize() { return size; }

private:
	MsgInfo *data;
	uint16_t size;
};