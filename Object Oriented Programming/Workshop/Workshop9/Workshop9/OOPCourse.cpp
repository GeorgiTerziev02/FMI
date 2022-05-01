#include "OOPCourse.h"
#include <cstring>

OOPCourse::OOPCourse(const char* lName, const char* a1Name) {
	lectorer = Lectorer(lName);
	assistants[0] = Assistant(a1Name);
}

OOPCourse::OOPCourse(const char* lName, const char* a1Name, const char* a2Name) {
	assistants[1] = Assistant(a2Name);
	OOPCourse(lName, a1Name);
}

OOPCourse::OOPCourse(const char* lName, const char* a1Name, const char* a2Name, const char* a3Name) {
	assistants[2] = Assistant(a3Name);
	OOPCourse(lName, a1Name, a2Name);
}

OOPCourse::~OOPCourse() {
	for (size_t i = 0; i < studentsSize; i++)
		delete students[i];
}

bool OOPCourse::addStudent(const char* name, const int fn) {
	if (studentsSize >= STUDENTS_MAX_SIZE) return false;

	this->students[studentsSize++] = new Student(name, fn);
	return true;
}

bool OOPCourse::addGrade(const int fn, const char* task, const double grade, const char* from) {
	Student* student = getStudentByFn(fn);
	return (*student).addGrade(Grade(grade, task, from));
}

bool OOPCourse::editGrade(const int fn, const char* task, const double grade, const char* from) {
	Student* student = getStudentByFn(fn);
	return (*student).editGrade(Grade(grade, task, from));
}

Student* OOPCourse::getStudentByFn(const int fn) const {
	for (size_t i = 0; i < studentsSize; i++)
	{
		if ((*students[i]).getFn() == fn)
		{
			return students[i];
		}
	}

	throw "Student not found";
}

bool OOPCourse::removeStudent(const int fn) {
	short studentToRemoveIndex = -1;
	for (size_t i = 0; i < studentsSize; i++)
	{
		if ((*students[i]).getFn() == fn)
		{
			studentToRemoveIndex = i;
			delete students[i];
			students[i] = nullptr;
			break;
		}
	}

	if (studentToRemoveIndex == -1) return false;

	students[studentToRemoveIndex] = students[--studentsSize];
	students[studentsSize] = nullptr;

	return true;
}

double OOPCourse::getAverageForCourse() const {
	int count = 0;
	double sum = 0;

	for (size_t i = 0; i < studentsSize; i++)
	{
		const Grade* grades = (*students[i]).getGrades();
		short gradesCount = (*students[i]).getGradesCount();

		for (size_t i = 0; i < gradesCount; i++)
		{
			sum += grades[i].getGrade();
			count++;
		}
	}

	return count == 0 ? 0 : sum / count;
}

double OOPCourse::getAverageGradePerTask(const char* task) const {
	int count = 0;
	double sum = 0;

	for (size_t i = 0; i < studentsSize; i++)
	{
		const Grade* grades = (*students[i]).getGrades();
		short gradesCount = (*students[i]).getGradesCount();

		for (size_t i = 0; i < gradesCount; i++)
		{
			if (strcmp(grades[i].getTask(), task) == 0)
			{
				sum += grades[i].getGrade();
				count++;
			}
		}
	}

	return count == 0 ? 0 : sum / count;
}

double OOPCourse::getAverageFromTeacher(const char* from) const {
	int count = 0;
	double sum = 0;

	for (size_t i = 0; i < studentsSize; i++)
	{
		const Grade* grades = (*students[i]).getGrades();
		short gradesCount = (*students[i]).getGradesCount();

		for (size_t i = 0; i < gradesCount; i++)
		{
			if (strcmp(grades[i].getFrom(), from) == 0)
			{
				sum += grades[i].getGrade();
				count++;
			}
		}
	}

	return count == 0 ? 0 : sum / count;
}