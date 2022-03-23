#include <iostream>
#include <fstream>

using namespace std;

const int ARGUMENTS_START_INDEX = 2;
const int INPUT_MAX_SIZE = 35;
const int COMPANY_NAME_MAX_SIZE = 25;
const char FILE_PATH[] = "file.bin";

struct Offer {
	char companyName[COMPANY_NAME_MAX_SIZE];
	int coWorkers;
	int paidLeave;
	long long salary;
};

void clearConsole() {
	cin.clear();
	cin.ignore(255, '\n');
}

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

bool strCmp(const char* str1, const char* str2) {
	int length1 = strLength(str1);
	int length2 = strLength(str2);

	if (length1 != length2) return false;

	for (size_t i = 0; i < length1; i++)
	{
		if (str1[i] != str2[i]) return false;
	}

	return true;
}

char* subStr(const char* str, const int startIndex, const int endIndex) {
	int resultSize = endIndex - startIndex + 2;
	char* result = new char[resultSize];

	int length = strLength(str);
	if (startIndex > endIndex || endIndex >= length)
	{
		return result;
	}

	for (size_t i = 0; i < resultSize; i++)
	{
		result[i] = str[startIndex + i];
	}

	result[resultSize - 1] = '\0';

	return result;
}

bool addOfferToFile(const Offer& offer) {
	ofstream myFile(FILE_PATH, std::ios::binary | std::ios::app);
	if (!myFile.is_open()) {
		return false;
	}
	myFile.write((const char*)&offer, sizeof(Offer));
	myFile.close();
	return true;
}

//bool addOffersToFile(const Offer* offers, int length) {
//	ofstream myFile(FILE_PATH, std::ofstream::app);
//	myFile.write((const char*)&offers, length * sizeof(Offer));
//	myFile.close();
//	return true;
//}

int getFileSize(ifstream& myFile) {
	int current = myFile.tellg();
	myFile.seekg(0, ios::end);
	int size = myFile.tellg();
	myFile.seekg(current, ios::beg);

	return size;
}

void printOffer(const Offer& offer) {
	cout << offer.companyName << " " << offer.coWorkers << " " << offer.paidLeave << " " << offer.salary << endl;
}

void printOffers() {
	ifstream myFile(FILE_PATH, std::ios::binary);
	if (!myFile.is_open())
	{
		return;
	}

	int fileSize = getFileSize(myFile);
	int arraySize = fileSize / sizeof(Offer);

	for (size_t i = 0; i < arraySize; i++)
	{
		Offer offer;
		myFile.read((char*)&offer, sizeof(Offer));
		printOffer(offer);
	}

	myFile.close();
}

void filterOffers(const char* filePath, long long minSalary) {
	ifstream myFile(filePath, std::ios::binary);

	if (!myFile.is_open())
	{
		return;
	}

	int fileSize = getFileSize(myFile);
	int arraySize = fileSize / sizeof(Offer);

	for (size_t i = 0; i < arraySize; i++)
	{
		Offer offer;
		myFile.read((char*)&offer, sizeof(Offer));

		if (offer.salary >= minSalary)
		{
			cout << offer.companyName << endl;
		}
	}

	myFile.close();
}

bool existOffer(const char* filePath, const char* name) {
	ifstream myFile(filePath, std::ios::binary);

	if (!myFile.is_open())
	{
		return false;
	}

	int fileSize = getFileSize(myFile);
	int arraySize = fileSize / sizeof(Offer);

	for (size_t i = 0; i < arraySize; i++)
	{
		Offer offer;
		myFile.read((char*)&offer, sizeof(Offer));

		if (strCmp(offer.companyName, name))
		{
			myFile.close();
			return true;
		}
	}

	myFile.close();
	return false;
}

//void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
//	ifstream myFile(filePath, std::ios::binary);
//
//	if (!myFile.is_open())
//	{
//		return;
//	}
//
//	int fileSize = getFileSize(myFile);
//	int arraySize = fileSize / sizeof(Offer);
//}

void startMenu() {
	while (true)
	{
		char inputBuffer[INPUT_MAX_SIZE];
		cin.getline(inputBuffer, INPUT_MAX_SIZE);

		switch (inputBuffer[0])
		{
		case 'a': {
			int inputLength = strLength(inputBuffer);
			char* offerArgs = subStr(inputBuffer, ARGUMENTS_START_INDEX, inputLength - 1);

			cout << offerArgs << endl;

			delete offerArgs;
		}break;
		case 'i': printOffers(); break;
		case 's': {
			int inputLength = strLength(inputBuffer);
			char* companyName = subStr(inputBuffer, ARGUMENTS_START_INDEX, inputLength - 1);

			cout << existOffer(FILE_PATH, companyName) << endl;
			delete companyName;
		}; break;
		case 'f': {
			int inputLength = strLength(inputBuffer);
			char* inputNumber = subStr(inputBuffer, ARGUMENTS_START_INDEX, inputLength - 1);

			filterOffers(FILE_PATH, atoi(inputNumber));
			delete inputNumber;
		}; break;
		case 'q': return; break;
		default:break;
		}
	}
}

int main()
{
	startMenu();
}