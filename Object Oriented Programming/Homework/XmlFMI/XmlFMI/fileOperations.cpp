#include "fileOperations.h"
#include "stringHelperFunctions.h"
#include "validations.h"
#include "helperFunctions.h"
#include "parsingFunctions.h"

#include <iostream>

using namespace std;

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
				bool validationArray[FIELDS_COUNT];
				for (size_t i = 0; i < FIELDS_COUNT; i++)
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