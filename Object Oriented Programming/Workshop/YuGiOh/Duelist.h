#pragma once
#include "Deck.h"

class Duelist {
	char* name;
	Deck deck;
	void copy(const Duelist& duelist);
	void free();
public:
	Duelist();
	Duelist(const char*, const Deck&);
	Duelist(const Duelist&);
	Duelist& operator=(const Duelist&);
	~Duelist();

	const char* getName() const;
	Deck getDeck() const;

	bool addMonsterCard(const MonsterCard& monsterCard);
	bool addMagicCard(const MagicCard& MagicCard);

	bool changeMonsterCardAtIndex(const MonsterCard& monsterCard, const int index);
	bool changeMagicCardAtIndex(const MagicCard& magicCard, const int index);
};