#pragma once

#include "MagicCard.h"
#include "MonsterCard.h"

const int MAX_DECK_SIZE = 40;

class Deck {
private:
	MagicCard magicCards[MAX_DECK_SIZE / 2];
	MonsterCard monsterCards[MAX_DECK_SIZE / 2];

	size_t magicCardsSize;
	size_t monsterCardsSize;
public:
	Deck();

	Deck(const Deck& deck) = default;
	Deck& operator=(const Deck& deck) = default;
	~Deck() = default;

	size_t getMagicCardsSize() const;
	size_t getMonsterCardsSize() const;

	bool addMagicCardToDeck(const MagicCard& magicCard);
	bool addMonsterCardToDeck(const MonsterCard& monsterdrCard);

	bool addMagicCardToDeckAtIndex(const MagicCard& magicCard, const int index);
	bool addMonsterCardToDeckAtIndex(const MonsterCard& monsterdrCard, const int index);
};