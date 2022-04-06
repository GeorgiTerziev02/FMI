#include "Deck.h"

#pragma warning(disable : 4996)

Deck::Deck() {
	magicCardsSize = 0;
	monsterCardsSize = 0;
}

Deck::Deck(const Deck& deck) {
	monsterCardsSize = deck.monsterCardsSize;
	for (size_t i = 0; i < deck.monsterCardsSize; i++)
	{
		monsterCards[i] = deck.monsterCards[i];
	}

	magicCardsSize = deck.magicCardsSize;
	for (size_t i = 0; i < deck.magicCardsSize; i++)
	{
		magicCards[i] = deck.magicCards[i];
	}
}

Deck& Deck::operator=(const Deck& deck) {
	if (this != &deck)
	{
		copy(deck);
	}

	return *this;
}

Deck::~Deck() {

}

unsigned short Deck::getMonsterCardsSize() const {
	return monsterCardsSize;
}

unsigned short Deck::getMagicCardsSize() const {
	return magicCardsSize;
}

bool Deck::addMagicCardToDeck(const MagicCard& magicCard) {
	if (magicCardsSize >= DECK_MAX_SIZE) return false;

	magicCards[magicCardsSize++] = magicCard;
	return true;
}

bool Deck::addMonsterCardToDeck(const MonsterCard& monsterCard) {
	if (monsterCardsSize >= DECK_MAX_SIZE) return false;

	monsterCards[monsterCardsSize++] = monsterCard;
	return true;
}

bool Deck::changeMagicCardAtIndex(const int index, const MagicCard& magicCard) {
	if (index < 0 || magicCardsSize <= index) return false;

	magicCards[index] = magicCard;
	return true;
}

bool Deck::changeMonsterCardAtIndex(const int index, const MonsterCard& monsterCard) {
	if (index < 0 || monsterCardsSize <= index) return false;

	monsterCards[index] = monsterCard;
	return true;
}


void Deck::copy(const Deck& deck) {
	monsterCardsSize = deck.monsterCardsSize;
	for (size_t i = 0; i < deck.monsterCardsSize; i++)
	{
		monsterCards[i] = deck.monsterCards[i];
	}

	magicCardsSize = deck.magicCardsSize;
	for (size_t i = 0; i < deck.magicCardsSize; i++)
	{
		magicCards[i] = deck.magicCards[i];
	}
}