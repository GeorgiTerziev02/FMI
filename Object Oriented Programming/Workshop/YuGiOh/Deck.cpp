#include<cstring>
#include "Deck.h"

Deck::Deck() : magicCardsSize(0), monsterCardsSize(0) {}

size_t Deck::getMagicCardsSize() const{
	return magicCardsSize;
}

size_t Deck::getMonsterCardsSize() const{
	return monsterCardsSize;
}

bool Deck::addMagicCardToDeck(const MagicCard& magicCard) {
	if(magicCardsSize >= MAX_DECK_SIZE / 2)
		return false;

	magicCards[magicCardsSize++] = magicCard;
	return true;
}

bool Deck::addMonsterCardToDeck(const MonsterCard& monsterdrCard) {
	if(monsterCardsSize >= MAX_DECK_SIZE / 2)
		return false;

	monsterCards[monsterCardsSize++] = monsterdrCard;
	return true;
}

bool Deck::addMagicCardToDeckAtIndex(const MagicCard& magicCard, const int index) {
	if(index < 0 || index >= magicCardsSize)
		return false;

	magicCards[index] = magicCard;
	return true;
}

bool Deck::addMonsterCardToDeckAtIndex(const MonsterCard& monsterdrCard, const int index) {
	if(index < 0 || index >= monsterCardsSize)
		return false;

	monsterCards[index] = monsterdrCard;
	return true;
}
