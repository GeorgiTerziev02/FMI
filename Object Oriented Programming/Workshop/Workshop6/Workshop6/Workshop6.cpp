#include <iostream>
#include "Deck.h"
#include "Duelist.h"

int main()
{
	char monsterName[] = "test1";
	char magicName[] = "test2";
	char effect[] = "effect";
	char name[] = "Ivan";
	MonsterCard monsterCard(monsterName, 100, 100);
	MagicCard magicCard(magicName, effect, MagicCardType::trap);

	Deck deck;
	Duelist duelist = { name , deck};

	duelist.addMagicCardToDeck(magicCard);
	duelist.addMonsterCardToDeck(monsterCard);

	std::cout << "test";
}