#include "Duelist.h"
#include <cstring>

#pragma warning(disable : 4996)

Duelist::Duelist() {
}

Duelist::Duelist(char* name, const Deck& deck) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->deck = deck;
}

Duelist::Duelist(const Duelist& duelist) {
	name = new char[strlen(duelist.name) + 1];
	strcpy(name, duelist.name);
	deck = duelist.deck;
}

Duelist& Duelist::operator=(const Duelist& duelist) {
	if (this != &duelist)
	{
		free();
		copy(duelist);
	}

	return *this;
}

Duelist::~Duelist() {
	free();
}

bool Duelist::addMagicCardToDeck(const MagicCard& magicCard) {
	return deck.addMagicCardToDeck(magicCard);
}

bool Duelist::addMonsterCardToDeck(const MonsterCard& monsterCard) {
	return deck.addMonsterCardToDeck(monsterCard);
}

bool Duelist::changeMagicCardAtIndex(const int index, const MagicCard& magicCard) {
	return deck.changeMagicCardAtIndex(index, magicCard);
}

bool Duelist::changeMonsterCardAtIndex(const int index, const MonsterCard& monsterCard) {
	return deck.changeMonsterCardAtIndex(index, monsterCard);
}

void Duelist::copy(const Duelist& duelist) {
	name = new char[strlen(duelist.name) + 1];
	strcpy(name, duelist.name);
	deck = duelist.deck;
}

void Duelist::free() {
	delete[] name;
}