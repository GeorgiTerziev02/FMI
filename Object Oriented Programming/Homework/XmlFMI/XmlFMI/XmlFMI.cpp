#include <iostream>
#include <fstream>

using namespace std;

const int FILE_BUFFER_SIZE = 5000;
const int INPUT_BUFFER_SIZE = 50;
const int FILE_NAME_SIZE = 50;
const int FIELD_MAX_SIZE = 25;
const int COMMAND_SIZE = 20;
const int STUDENTS_MAX_SIZE = 100;

const char OPEN_FILE_ERROR_MESSAGE[] = "Error opening the file";
const char SUCCESSFUL_OPERATION_MESSAGE[] = "Operation successfully executed!";
const char UNSUCCESSFUL_OPERATION_MESSAGE[] = "Operation didn't execute successfully!";
const char VALIDATION_ERROR_MESSAGE[] = "Error! Data not in correct format!";

const char EDIT_COMMAND[] = "edit";
const char SORT_COMMAND[] = "sort";
const char PRINT_COMMAND[] = "print";
const char SAVE_COMMAND[] = "save";

const char STUDENT_TAG[] = "student";
const char NAME_TAG[] = "name";
const char FN_TAG[] = "fn";
const char AGE_TAG[] = "age";
const char GENDER_TAG[] = "gender";
const char EMAIL_TAG[] = "email";
const char GRADE_TAG[] = "grade";

const char MALE[] = "Male";
const char FEMALE[] = "Female";

const int MIN_AGE = 15;
const int MAX_AGE = 65;
const int MIN_GRADE = 2;
const int MAX_GRADE = 6;

struct Student {
	char name[FIELD_MAX_SIZE];
	int fn;
	int age;
	bool gender;
	char email[FIELD_MAX_SIZE];
	double grade;
};

struct System {
	int size = 0;
	char fileName[FILE_NAME_SIZE];
	Student students[STUDENTS_MAX_SIZE];
};

void printInputCharacter() {
	cout << ">";
}

void printOperationResultMessage(bool result) {
	cout << (result ? SUCCESSFUL_OPERATION_MESSAGE : UNSUCCESSFUL_OPERATION_MESSAGE) << endl;
}

void printDataErrorMessage() {
	cout << VALIDATION_ERROR_MESSAGE << endl;
}

void my_strcpy(char* dest, const char* source)
{
	size_t index = NULL;
	while (source[index] != '\0')
	{
		dest[index] = source[index];
		index++;
	}
	dest[index] = '\0';
}

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

// Check if string is a valid integer
bool isInputInteger(const char* str) {
	int length = strLength(str);
	if (length < 1) {
		return false;
	}

	int index = str[0] == '-' ? 1 : 0;

	// input is "-"
	if (index == length) {
		return false;
	}

	for (; index < length; index++) {
		if (str[index] < '0' || str[index] > '9') {
			return false;
		}
	}

	return true;
}

bool isInputDouble(const char* str) {
	int length = strLength(str);
	if (length < 1) {
		return false;
	}

	int index = str[0] == '-' ? 1 : 0;
	// first symbol is .(after dash)
	if (str[index] == '.')
	{
		return false;
	}

	// input is "-"
	if (index == length) {
		return false;
	}

	bool hasDot = false;
	for (; index < length; index++) {
		if (str[index] == '.' && hasDot) {
			return false;
		}
		else if (str[index] == '.' && !hasDot) {
			hasDot = true;
		}
		else if ((str[index] < '0' || str[index] > '9') && str[index] != '.') {
			return false;
		}
	}

	return true;
}

int intParse(char* str) {
	int stringLength = strLength(str);
	if (stringLength < 1) {
		return 0;
	}

	int index = str[0] == '-' ? 1 : 0;

	int result = 0;
	for (; index < stringLength; index++) {
		result = result * 10 + (str[index] - '0');
	}

	return str[0] == '0' ? -result : result;
}

double myPow(double number, int degree) {
	int index = 1;
	double result = 1;

	while (index++ <= degree)
	{
		result *= number;
	}

	return result;
}

double doubleParse(char* str) {
	int stringLength = strLength(str);
	if (stringLength < 1) {
		return 0;
	}

	int index = str[0] == '-' ? 1 : 0;

	int dotIndex = -1;
	for (size_t i = 0; i < stringLength; i++)
	{
		if (str[i] == '.')
		{
			dotIndex = i;
			break;
		}
	}

	double result = 0;
	if (dotIndex == -1)
	{
		for (size_t i = 0; i < stringLength; i++)
		{
			result = result * 10 + (str[index] - '0');
		}
	}
	else {
		for (size_t i = 0; i < dotIndex; i++)
		{
			result = result * 10 + (str[index] - '0');
		}

		// after decimal point
		for (size_t i = dotIndex + 1; i < stringLength; i++)
		{
			result += (str[i] - '0') * myPow(0.1, i - dotIndex);
		}
	}

	return str[0] == '0' ? -result : result;
}

int strCmp(const char* str1, const char* str2) {
	int length1 = strLength(str1);
	int length2 = strLength(str2);
	int smallerLength = length1 < length2 ? length1 : length2;

	for (size_t i = 0; i < smallerLength; i++)
	{
		if (str1[i] - str2[i] != 0) return str1[i] - str2[i];
	}

	return length1 - length2;
}

int indexOf(const char* str1, const int& fromIndex, const char& character) {
	int index = fromIndex;

	while (str1[index] != '\0')
	{
		if (str1[index] == character)
		{
			return index;
		}
		index++;
	}

	return -1;
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

int getStudentIndexByFn(const System& system, const int& fn) {
	for (size_t i = 0; i < system.size; i++)
	{
		if (system.students[i].fn == fn)
		{
			return i;
		}
	}

	return -1;
}

bool isNameValid(const char* name) {
	return strLength(name) <= FIELD_MAX_SIZE;
}

bool isFnValid(const System& system, const int& fn) {
	return getStudentIndexByFn(system, fn) == -1;
}

bool isAgeValid(const int& age) {
	return MIN_AGE <= age && age <= MAX_AGE;
}

bool isGenderValid(const char* gender) {
	return strCmp(gender, MALE) == 0 || strCmp(gender, FEMALE) == 0;
}

bool isEmailValid(const char* email) {
	if (strLength(email) > FIELD_MAX_SIZE)
	{
		return false;
	}

	int index = 0;
	while (email[index] != '\0')
	{
		if (email[index++] == '@')
		{
			return true;
		}
	}

	return false;
}

bool isGradeValid(const double& grade) {
	return MIN_GRADE <= grade && grade <= MAX_GRADE;
}

char* getTag(const char* buffer, int& startIndex) {
	int indexOfLeftArrowOfOpeningTag = indexOf(buffer, startIndex, '<');
	int indexOfRightArrowOfOpeningTag = indexOf(buffer, indexOfLeftArrowOfOpeningTag, '>');
	startIndex = indexOfRightArrowOfOpeningTag;
	return subStr(buffer, indexOfLeftArrowOfOpeningTag + 1, indexOfRightArrowOfOpeningTag - 1);
}

bool checkRequiredFields(bool validationArray[6]) {
	for (size_t i = 0; i < 6; i++)
	{
		if (!validationArray[i])
		{
			return false;
		}
	}

	return true;
}

bool readSystem(System& system) {
	ifstream file(system.fileName);

	if (!file.is_open())
	{
		cout << OPEN_FILE_ERROR_MESSAGE << endl;
		return false;
	}

	char fileBuffer[FILE_BUFFER_SIZE];
	//will be used as size later
	int length = 0;
	while (!file.eof())
	{
		file.get(fileBuffer[length++]);
	}
	fileBuffer[--length] = '\0';

	file.close();

	int currentIndex = 0;

	while (currentIndex < length)
	{
		int indexOfLeftArrow = indexOf(fileBuffer, currentIndex, '<');
		int indexOfRightArrow = indexOf(fileBuffer, indexOfLeftArrow, '>');

		if (indexOfLeftArrow != -1 && indexOfRightArrow != -1)
		{
			char* tag = subStr(fileBuffer, indexOfLeftArrow + 1, indexOfRightArrow - 1);

			currentIndex = indexOfRightArrow;

			if (strCmp(tag, STUDENT_TAG) == 0)
			{
				Student student{};

				// all values false
				bool validationArray[6];
				for (size_t i = 0; i < 6; i++)
				{
					validationArray[i] = false;
				}

				while (true)
				{
					int indexOfLeftArrowOfOpeningTag = indexOf(fileBuffer, currentIndex, '<');
					int indexOfRightArrowOfOpeningTag = indexOf(fileBuffer, indexOfLeftArrowOfOpeningTag, '>');

					char* innerOpeningTag = subStr(fileBuffer, indexOfLeftArrowOfOpeningTag + 1, indexOfRightArrowOfOpeningTag - 1);

					if (indexOf(innerOpeningTag, 0, '\\') != -1)
					{
						currentIndex = indexOfRightArrowOfOpeningTag;
						delete[] innerOpeningTag;
						break;
					}

					int indexOfLeftArrowOfClosingTag = indexOf(fileBuffer, indexOfRightArrowOfOpeningTag, '<');
					int indexOfRightArrowOfClosingTag = indexOf(fileBuffer, indexOfLeftArrowOfClosingTag, '>');

					char* value = subStr(fileBuffer, indexOfRightArrowOfOpeningTag + 1, indexOfLeftArrowOfClosingTag - 1);

					if (strCmp(innerOpeningTag, NAME_TAG) == 0) {
						if (isNameValid(value))
						{
							my_strcpy(student.name, value);
							validationArray[0] = true;
						}
					}
					else if (strCmp(innerOpeningTag, FN_TAG) == 0) {
						if (isInputInteger(value))
						{
							int fn = intParse(value);
							if (isFnValid(system, fn))
							{
								student.fn = fn;
								validationArray[1] = true;
							}
						}
					}
					else if (strCmp(innerOpeningTag, AGE_TAG) == 0) {
						if (isInputInteger(value))
						{
							int newValue = intParse(value);
							if (isAgeValid(newValue))
							{
								student.age = newValue;
								validationArray[2] = true;
							}
						}
					}
					else if (strCmp(innerOpeningTag, GENDER_TAG) == 0) {
						if (isGenderValid(value))
						{
							student.gender = strCmp(value, MALE) == 0;
							validationArray[3] = true;
						}
					}
					else if (strCmp(innerOpeningTag, EMAIL_TAG) == 0) {
						if (isEmailValid(value))
						{
							my_strcpy(student.email, value);
							validationArray[4] = true;
						}
					}
					else if (strCmp(innerOpeningTag, GRADE_TAG) == 0) {
						if (isInputDouble(value))
						{
							double doubleValue = doubleParse(value);
							if (isGradeValid(doubleValue))
							{
								student.grade = doubleValue;
								validationArray[5] = true;
							}
						}
					}

					currentIndex = indexOfRightArrowOfClosingTag;
					delete[] innerOpeningTag;
					delete[] value;
				}

				// check if student has all properties and they are valid
				if (!checkRequiredFields(validationArray))
				{
					continue;
				}

				system.students[system.size++] = student;
			}

			delete[] tag;
		}

		currentIndex++;
	}

	return true;
}

void writeStudentToFile(const Student& student, ofstream& file) {
	file << "<" << STUDENT_TAG << ">" << endl;

	file << "\t" << "<" << NAME_TAG << ">" << student.name << "<\\" << NAME_TAG << ">" << endl;
	file << "\t" << "<" << FN_TAG << ">" << student.fn << "<\\" << FN_TAG << ">" << endl;
	file << "\t" << "<" << AGE_TAG << ">" << student.age << "<\\" << AGE_TAG << ">" << endl;
	file << "\t" << "<" << GENDER_TAG << ">" << (student.gender ? MALE : FEMALE) << "<\\" << GENDER_TAG << ">" << endl;
	file << "\t" << "<" << EMAIL_TAG << ">" << student.email << "<\\" << EMAIL_TAG << ">" << endl;
	file << "\t" << "<" << GRADE_TAG << ">" << student.grade << "<\\" << GRADE_TAG << ">" << endl;

	file << "<\\" << STUDENT_TAG << ">" << endl;
	file << endl;
}

bool writeSystem(const System& system) {
	ofstream file(system.fileName);

	if (!file.is_open())
	{
		cout << OPEN_FILE_ERROR_MESSAGE << endl;
		return false;
	}

	for (size_t i = 0; i < system.size; i++)
	{
		writeStudentToFile(system.students[i], file);
	}

	file.close();
	return true;
}

void printStudent(const Student& student) {
	cout << NAME_TAG << ": " << student.name << endl;
	cout << FN_TAG << ": " << student.fn << endl;
	cout << AGE_TAG << ": " << student.age << endl;
	cout << GENDER_TAG << ": " << (student.gender ? MALE : FEMALE) << endl;
	cout << EMAIL_TAG << ": " << student.email << endl;
	cout << GRADE_TAG << ": " << student.grade << endl;
	cout << endl;
}

void printStudents(const System& system) {
	for (size_t i = 0; i < system.size; i++)
	{
		printStudent(system.students[i]);
	}
}

bool editValue(System& system, const char* inputData) {
	int index = indexOf(inputData, 0, ' ');
	char* fnString = subStr(inputData, 0, index - 1);
	int fn = intParse(fnString);
	delete[] fnString;

	int studentIndex = getStudentIndexByFn(system, fn);
	if (studentIndex == -1)
	{
		return false;
	}

	int endIndexOfProperty = indexOf(inputData, index + 1, ' ');
	char* property = subStr(inputData, index + 1, endIndexOfProperty - 1);

	int inputDataLength = strLength(inputData);
	char* newValue = subStr(inputData, endIndexOfProperty + 1, inputDataLength - 1);

	bool result = false;
	if (strCmp(property, NAME_TAG) == 0)
	{
		if (isNameValid(newValue))
		{
			my_strcpy(system.students[studentIndex].name, newValue);
			result = true;
		}
	}
	else if (strCmp(property, FN_TAG) == 0) {
		if (isInputInteger(newValue))
		{
			int newFn = intParse(newValue);
			if (isFnValid(system, fn))
			{
				system.students[studentIndex].fn = newFn;
				result = true;
			}
		}
	}
	else if (strCmp(property, AGE_TAG) == 0) {
		if (isInputInteger(newValue))
		{
			int newAge = intParse(newValue);
			if (isAgeValid(newAge))
			{
				system.students[studentIndex].age = newAge;
				result = true;
			}
		}
	}
	else if (strCmp(property, GENDER_TAG) == 0) {
		if (isGenderValid(newValue))
		{
			bool newGender = strCmp(newValue, MALE) == 0;
			system.students[studentIndex].gender = newGender;
			result = true;
		}
	}
	else if (strCmp(property, EMAIL_TAG) == 0) {
		if (isEmailValid(newValue))
		{
			my_strcpy(system.students[studentIndex].email, newValue);
			result = true;
		}
	}
	else if (strCmp(property, GRADE_TAG) == 0) {
		if (isInputDouble(newValue))
		{
			double doubleValue = doubleParse(newValue);
			if (isGradeValid(doubleValue))
			{
				system.students[studentIndex].grade = doubleValue;
				result = true;
			}
		}
	}

	delete[] newValue;
	delete[] property;

	return result;
}

void swapStudents(Student& firstStudent, Student& secondStudent) {
	Student temp = firstStudent;
	firstStudent = secondStudent;
	secondStudent = temp;
}

void sortBy(System& system, const char* sortingProperty) {
	if (strCmp(sortingProperty, NAME_TAG) == 0)
	{
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (strCmp(system.students[i].name, system.students[j].name) > 0)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, FN_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].fn > system.students[j].fn)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, AGE_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].age > system.students[j].age)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, GENDER_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].gender > system.students[j].gender)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, EMAIL_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (strCmp(system.students[i].email, system.students[j].email) > 0)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, GRADE_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].grade > system.students[j].grade)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
}

void startMenu(System& system) {
	while (true)
	{
		char input[INPUT_BUFFER_SIZE];
		printInputCharacter();
		cin.getline(input, INPUT_BUFFER_SIZE);

		int index = indexOf(input, 0, ' ');
		int inputLength = strLength(input);
		char* command = subStr(input, 0, index == -1 ? inputLength - 1 : index - 1);

		if (strCmp(command, EDIT_COMMAND) == 0)
		{
			char* inputData = subStr(input, index + 1, inputLength - 1);
			bool result = editValue(system, inputData);
			if (!result) printDataErrorMessage();
			else printOperationResultMessage(result);
			delete[] inputData;
		}
		else if (strCmp(command, SORT_COMMAND) == 0)
		{
			char* sortingProperty = subStr(input, index + 1, inputLength - 1);
			sortBy(system, sortingProperty);

			delete[] sortingProperty;
		}
		else if (strCmp(command, PRINT_COMMAND) == 0)
		{
			printStudents(system);
		}
		else if (strCmp(command, SAVE_COMMAND) == 0)
		{
			bool result = writeSystem(system);

			printOperationResultMessage(result);
			if (result) {
				delete[] command;
				return;
			}
		}

		delete[] command;
	}
}

int main()
{
	System system;
	cout << "Enter a file path:" << endl;
	printInputCharacter();
	cin.getline(system.fileName, FILE_NAME_SIZE);

	bool success = readSystem(system);
	if (!success) return 0;
	cout << "File loaded successfully!" << endl;

	startMenu(system);

	return 0;
}