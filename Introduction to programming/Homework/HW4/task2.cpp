#include <iostream>

using namespace std;

int strLength(const char* str) {
	int index = 0;
	while (str[index] != '\0') {
		index++;
	}

	return index;
}

int replace(char*& text, const char* const str1, const char* const str2) {
	if (str1 == nullptr || str2 == nullptr) {
		return -2;
	}

	if (text[0] == '\0') {
		return -3;
	}

	int index = 0;
	int operationsCount = 0;
	char firstCharacterOfStr1 = str1[0];

	int textLength = strLength(text);
	int str1Length = strLength(str1);
	int str2Length = strLength(str2);

	while (text[index] != '\0') {
		if (text[index] == firstCharacterOfStr1) {
			int tempTextIndex = index + 1;
			int tempStr1Index = 1;
			bool isMatched = true;

			while (text[tempTextIndex] != '\0'
				&& str1[tempStr1Index] != '\0') {
				if (text[tempTextIndex] != str1[tempStr1Index]) {
					isMatched = false;
					break;
				}

				tempTextIndex++;
				tempStr1Index++;
			}

			// str matched and we have passed the whole str
			if (isMatched && tempStr1Index == str1Length) {
				if (str1Length != str2Length) {
					// TODO: check if there is enough space in the initial text array
					int tempArrayLength = textLength - str1Length + str2Length;
					char* temp = new char[tempArrayLength + 1];
					temp[tempArrayLength] = '\0';

					for (int i = 0; i < index; i++)
					{
						temp[i] = text[i];
					}

					for (int i = 0; i < str2Length; i++)
					{
						temp[index + i] = str2[i];
					}

					for (int i = 0; i < textLength - index - str1Length; i++)
					{
						temp[index + str2Length + i] = text[index + str1Length + i];
					}

					operationsCount++;

					delete[] text;
					text = nullptr;

					textLength = textLength - str1Length + str2Length;

					text = new char[textLength + 1];
					text[textLength] = '\0';
					for (size_t i = 0; i < textLength; i++)
					{
						text[i] = temp[i];
					}

					delete[] temp;
					temp = nullptr;

					// TODO: Change index
				}
				else {
					tempStr1Index = 0;
					while (str2[tempStr1Index] != '\0') {
						text[index] = str2[tempStr1Index];
						tempStr1Index++;
						index++;
					}

					operationsCount++;

					continue;
				}
			}
		}

		index++;
	}

	text[textLength] = '\0';

	return operationsCount;
}


const int KB_SIZE = 1024;

int main()
{
	char* text = new char[4 * KB_SIZE];
	char* str1 = new char[KB_SIZE];
	char* str2 = new char[KB_SIZE];

	cin.getline(text, 4 * KB_SIZE);
	cin.getline(str1, KB_SIZE);
	cin.getline(str2, KB_SIZE);

	int operationsCount = replace(text, str1, str2);

	cout << operationsCount << endl;
	cout << text;

	delete[] text;
	delete[] str1;
	delete[] str2;

	return 0;
}