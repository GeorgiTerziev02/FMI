#include <iostream>
#include <fstream>

using namespace std;

// 10 kb
const int FILE_SIZE = 10 * 1024;
const int FILE_NAME_SIZE = 50;
const int INPUT_BUFFER_SIZE = 70;
const int COMMAND_SIZE = 20;
// MAX IS 255 - FF
const int HEX_SIZE = 3;

const char VIEW_COMMAND[] = "view";
const char CHANGE_COMMAND[] = "change";
const char REMOVE_COMMAND[] = "remove";
const char ADD_COMMAND[] = "add";
const char SAVE_COMMAND[] = "save";

const char OPEN_FILE_ERROR_MESSAGE[] = "Error opening the file";
const char SUCCESSFUL_OPERATION_MESSAGE[] = "Operation successfully executed!";
const char UNSUCCESSFUL_OPERATION_MESSAGE[] = "Operation didn't execute successfully!";

const int UPPERCASE_A_ASCII_CODE = 65;
const int UPPERCASE_F_ASCII_CODE = 70;
const int UPPERCASE_Z_ASCII_CODE = 90;
const int LOWERCASE_A_ASCII_CODE = 97;
const int LOWERCASE_Z_ASCII_CODE = 122;

struct File {
	unsigned int size = 0;
	char name[FILE_NAME_SIZE];
	char data[FILE_SIZE];
};

void flushStream() {
	cin.clear();
	cin.ignore(255, '\n');
}

void printInputCharacter() {
	cout << ">";
}

void printOperationResultMessage(bool result) {
	cout << (result ? SUCCESSFUL_OPERATION_MESSAGE : UNSUCCESSFUL_OPERATION_MESSAGE) << endl;
}

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

char* subStr(const char* str, const int& startIndex, const int& endIndex) {
	int resultSize = endIndex - startIndex + 2;
	char* result = new char[resultSize];

	int length = strLength(str);
	if (startIndex > endIndex || endIndex >= length)
	{
		return result;
	}

	for (size_t i = 0; i < resultSize - 1; i++)
	{
		result[i] = str[startIndex + i];
	}

	result[resultSize - 1] = '\0';

	return result;
}

bool isLetter(const char& character) {
	return (UPPERCASE_A_ASCII_CODE <= character && character <= UPPERCASE_Z_ASCII_CODE)
		|| (LOWERCASE_A_ASCII_CODE <= character && character <= LOWERCASE_Z_ASCII_CODE);
}

void printLetter(const char& byte) {
	if (isLetter(byte))
	{
		cout << byte;
	}
	else
	{
		cout << ".";
	}
	cout << "  ";
}

void moveIndexToNextSeparator(const char* str, int& startIndex, const char& separator) {
	while (str[startIndex] != separator && str[startIndex] != '\0')
	{
		startIndex++;
	}
}

void printHex(const char& byte) {
	char hex[HEX_SIZE];

	// definitely not the right way
	int quotient = byte / 16;
	int remainder = byte % 16;
	hex[0] = quotient > 9 ? (quotient - 10 + UPPERCASE_A_ASCII_CODE) : (quotient + '0');
	hex[1] = remainder > 9 ? (remainder - 10 + UPPERCASE_A_ASCII_CODE) : (remainder + '0');
	hex[2] = '\0';

	cout << hex << " ";
}

bool isValidHex(char* hex) {
	for (size_t i = 0; i < hex[i] != '\0'; i++)
	{
		if (!(('0' <= hex[i] && hex[i] <= '9') || (UPPERCASE_A_ASCII_CODE <= hex[i] && hex[i] <= UPPERCASE_F_ASCII_CODE)))
		{
			return false;
		}
	}

	return true;
}

int customPow(int number, int degree) {
	if (degree == 0)
	{
		return 1;
	}

	int result = 1;
	for (size_t i = 0; i < degree; i++)
	{
		result *= number;
	}

	return result;
}

int hexToDecimal(char* hex) {
	size_t length = strLength(hex);

	int result = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (UPPERCASE_A_ASCII_CODE <= hex[i])
		{
			int num = hex[i] - UPPERCASE_A_ASCII_CODE + 10;
			result += num * customPow(16, length - i - 1);
		}
		else {
			int num = hex[i] - '0';
			result += num * customPow(16, length - i - 1);
		}
	}

	return result;
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

void viewFile(const File& file) {
	int index = 0;
	while (index < file.size)
	{
		printHex(file.data[index++]);
	}

	cout << endl;

	index = 0;
	while (index < file.size)
	{
		printLetter(file.data[index++]);
	}

	cout << endl;
}

bool changeByteAtIndex(File& file, const char& character, int index) {
	if (index >= file.size)
	{
		return false;
	}

	file.data[index] = character;
	return true;
}

bool removeByteFromEnd(File& file) {
	if (file.size == 0)
	{
		return false;
	}

	file.data[--file.size] = '\0';
	return true;
}

bool addByteToEnd(File& file, const char& character) {
	if (file.size == FILE_SIZE)
	{
		return false;
	}

	file.data[file.size++] = character;
	return true;
}

bool saveToFile(const File& file, const char* fileName) {
	ofstream outputFile(fileName);

	if (!outputFile.is_open())
	{
		cout << OPEN_FILE_ERROR_MESSAGE << endl;
		return false;
	}

	for (size_t i = 0; i < file.size; i++)
	{
		outputFile.write((char*)&file.data[i], sizeof(char));
	}

	outputFile.close();
	return true;
}

void startMenu(File& file) {
	while (true)
	{
		char input[INPUT_BUFFER_SIZE];
		printInputCharacter();
		cin.getline(input, INPUT_BUFFER_SIZE);

		char command[COMMAND_SIZE];
		int index = 0;

		while (input[index] != ' ' && input[index] != '\0')
		{
			command[index] = input[index++];
		}
		command[index++] = '\0';

		if (strCmp(command, VIEW_COMMAND))
		{
			viewFile(file);
		}
		else if (strCmp(command, CHANGE_COMMAND))
		{
			int indexToChange = 0;
			while (input[index] != ' ')
			{
				indexToChange += input[index++] - '0';
			}
			index++;
			int inputLength = strLength(input);
			char* hexStr = subStr(input, index, inputLength - 1);
			if (!isValidHex(hexStr))
			{
				printOperationResultMessage(false);
				delete[] hexStr;
				continue;
			}

			int newValue = hexToDecimal(hexStr);
			delete[] hexStr;

			bool result = changeByteAtIndex(file, newValue, indexToChange);
			printOperationResultMessage(result);
		}
		else if (strCmp(command, REMOVE_COMMAND))
		{
			bool result = removeByteFromEnd(file);
			printOperationResultMessage(result);
		}
		else if (strCmp(command, ADD_COMMAND))
		{
			int inputLength = strLength(input);
			char* hexStr = subStr(input, index, inputLength - 1);
			if (!isValidHex(hexStr))
			{
				printOperationResultMessage(false);
				delete[] hexStr;
				continue;
			}
			int newValue = hexToDecimal(hexStr);
			delete[] hexStr;

			bool result = addByteToEnd(file, newValue);
			printOperationResultMessage(result);
		}
		else if (strCmp(command, SAVE_COMMAND))
		{
			int inputLength = strLength(input);
			bool result = false;

			// check if just save
			if (input[index - 1] == '\0')
			{
				result = saveToFile(file, file.name);
			}
			else
			{
				moveIndexToNextSeparator(input, index, ' ');
				moveIndexToNextSeparator(input, index, ' ');

				char* newFileName = subStr(input, ++index, inputLength - 1);
				result = saveToFile(file, newFileName);
				delete[] newFileName;
			}

			printOperationResultMessage(result);
			if (result) return;
		}
	}
}

int getFileSize(ifstream& file) {
	int current = file.tellg();
	file.seekg(0, ios::end);
	int size = file.tellg();
	file.seekg(current, ios::beg);

	return size;
}

bool readFile(File& file) {
	ifstream inputFile(file.name, ios::binary);

	if (!inputFile.is_open())
	{
		cout << OPEN_FILE_ERROR_MESSAGE << endl;
		return false;
	}

	int size = getFileSize(inputFile);
	file.size = size;

	int index = 0;
	while (!inputFile.eof())
	{
		inputFile.read((char*)&file.data[index++], sizeof(char));
	}

	inputFile.close();
	return true;
}

int main()
{
	File file;
	cout << "Enter a file path:" << endl;
	printInputCharacter();
	cin.getline(file.name, FILE_NAME_SIZE);

	bool success = readFile(file);
	if (!success) return 0;

	cout << "File loaded successfully! Size: " << file.size << " bytes" << endl;

	startMenu(file);

	return 0;
}