#include "MonsterCard.h"
#include <cstring>

#pragma warning(disable : 4996)

MonsterCard::MonsterCard()
{
	attPoints = 0;
	defPoints = 0;
}

MonsterCard::MonsterCard(const char* name, const int attPoints, const int defPoints) {
	strcpy(this->name, name);
	this->attPoints = attPoints;
	this->defPoints = defPoints;
}

MonsterCard::MonsterCard(const MonsterCard& monster) {
	copy(monster);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& monster) {
	if (this != &monster)
	{
		strcpy(name, monster.name);
		attPoints = monster.attPoints;
		defPoints = monster.defPoints;
	}
	return *this;
}

MonsterCard::~MonsterCard()
{
}

void MonsterCard::copy(const MonsterCard& monster) {
	strcpy(name, monster.name);
	attPoints = monster.attPoints;
	defPoints = monster.defPoints;
}