#include "MagicCard.h"
#include <cstring>
#pragma warning(disable : 4996)

MagicCard::MagicCard() {
}

MagicCard::MagicCard(const char* name, const char* effect, const MagicCardType type) {
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = type;
}

MagicCard::MagicCard(const MagicCard& magicCard) {
	strcpy(name, magicCard.name);
	strcpy(effect, magicCard.effect);
	type = magicCard.type;
}

MagicCard& MagicCard::operator=(const MagicCard& magicCard) {
	if (this != &magicCard)
	{
		copy(magicCard);
	}

	return *this;
}

MagicCard::~MagicCard() {
}

void MagicCard::copy(const MagicCard& magicCard) {
	strcpy(name, magicCard.name);
	strcpy(effect, magicCard.effect);
	type = magicCard.type;
}