#pragma once

#include "MagicCard.h"
#include "MonsterCard.h"

const short DECK_MAX_SIZE = 20;

class Deck
{
private:
	MonsterCard monsterCards[DECK_MAX_SIZE];
	unsigned short monsterCardsSize;
	MagicCard magicCards[DECK_MAX_SIZE];
	unsigned short magicCardsSize;

public:
	Deck();
	Deck(const Deck& deck);
	Deck& operator=(const Deck& deck);
	~Deck();

	unsigned short getMonsterCardsSize() const;
	unsigned short getMagicCardsSize() const;

	bool addMagicCardToDeck(const MagicCard& magicCard);
	bool addMonsterCardToDeck(const MonsterCard& monsterCard);
	bool changeMagicCardAtIndex(const int index, const MagicCard& magicCard);
	bool changeMonsterCardAtIndex(const int index, const MonsterCard& monsterCard);

private:
	void copy(const Deck& deck);
};

