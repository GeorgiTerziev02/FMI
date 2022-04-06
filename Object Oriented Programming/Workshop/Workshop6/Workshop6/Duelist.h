#pragma once

#include "Deck.h"
#include "MagicCard.h"
#include "MonsterCard.h"

class Duelist
{
private:
	char* name;
	Deck deck;

public:
	Duelist();
	Duelist(char* name, const Deck& deck);
	Duelist(const Duelist& duelist);
	Duelist& operator=(const Duelist& duelist);
	~Duelist();

	bool addMagicCardToDeck(const MagicCard& magicCard);
	bool addMonsterCardToDeck(const MonsterCard& monsterCard);
	bool changeMagicCardAtIndex(const int index, const MagicCard& magicCard);
	bool changeMonsterCardAtIndex(const int index, const MonsterCard& monsterCard);

private:
	void copy(const Duelist& duelist);
	void free();
};

