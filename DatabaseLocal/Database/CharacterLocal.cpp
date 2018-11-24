
#include "CharacterLocal.h"



CharacterLocal::CharacterLocal(QByteArray nickname, uint16_t model, uint16_t cClass) :
	nickname(nickname), model(model), cClass(cClass)
{
	switch (cClass) {
		case 1:
			strength = 5; dexterity = 2; health = 3; soul = 0;
			break;
		case 2:
			strength = 5; dexterity = 2; health = 3; soul = 0;
			break;
		case 10:
			strength = 0; dexterity = 2; health = 3; soul = 5;
			break;
		case 4:
			strength = 2; dexterity = 7; health = 1; soul = 0;
			break;
		default:
			break;
	}
	life = (strength * 3) + (dexterity * 3) + (health * 24) + (soul * 3);
	mana = (soul * 5);
	level = 1;

}