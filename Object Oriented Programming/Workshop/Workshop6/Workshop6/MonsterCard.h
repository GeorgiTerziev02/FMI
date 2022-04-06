#pragma once

const short NAME_MAX_SIZE = 26;

class MonsterCard
{
private:
	char name[NAME_MAX_SIZE];
	unsigned int attPoints;
	unsigned int defPoints;

public:
	MonsterCard();
	MonsterCard(char* name, int attPoints, int defPoints);
	MonsterCard(const MonsterCard& monster);
	MonsterCard& operator=(const MonsterCard& monster);
	~MonsterCard();

private:
	void copy(const MonsterCard& monster);
};

