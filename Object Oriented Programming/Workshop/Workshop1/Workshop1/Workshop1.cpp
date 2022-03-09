#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE_PAIRS = 25;
const char FILE_NAME[] = "Relation.txt";

struct Pair {
	size_t x, y;
};

struct Relation {
	int size = 0;
	Pair pairs[MAX_SIZE_PAIRS];
};

Pair createPair(size_t x, size_t y) {
	return Pair{ x,y };
}

Pair readPairFromFile(ifstream& file) {
	size_t x, y;
	file >> x >> y;

	return createPair(x,y);
}

void writePairToFile(const Pair& pair, ofstream& file) {
	file << pair.x << " " << pair.y << endl;
}

bool addPairToRelation(const Pair& pair, Relation& relation) {
	if (relation.size == MAX_SIZE_PAIRS)
	{
		return false;
	}

	relation.pairs[relation.size++] = pair;

	return true;
}

Relation readRelationFromFile(const char* fileName) {
	ifstream file(fileName);

	Relation relation;
	if (!file.is_open())
	{
		return relation;
	}

	size_t size;
	file >> size;

	for (size_t i = 0; (i < size) && !file.eof(); i++)
	{
		Pair pair = readPairFromFile(file);
		addPairToRelation(pair, relation);
	}

	file.close();

	return relation;
}

bool writeRelationToFile(const char* fileName, const Relation& relation) {
	ofstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file << relation.size << endl;
	for (size_t i = 0; i < relation.size; i++)
	{
		writePairToFile(relation.pairs[i], file);
	}

	file.close();

	return true;
}

void printRelation(const Relation& relation) {
	for (size_t i = 0; i < relation.size; i++)
	{
		cout << relation.pairs[i].x << " " << relation.pairs[i].y << endl;
	}
}

int main()
{
	int n;
	cin >> n;

	Relation relation;
	for (size_t i = 0; i < n; i++)
	{
		size_t x, y;
		cin >> x >> y;
		addPairToRelation(createPair(x, y), relation);
	}

	writeRelationToFile(FILE_NAME, relation);

	Relation test = readRelationFromFile(FILE_NAME);
	printRelation(test);
}