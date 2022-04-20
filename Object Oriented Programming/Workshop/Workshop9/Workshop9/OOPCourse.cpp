#include "OOPCourse.h"
#include <cstring>

OOPCourse::OOPCourse(const char* lName, const char* a1Name) {
	lectorer = Lectorer(lName);
	assistants[0] = Assistant(a1Name);
}

bool OOPCourse::addStudent(const char* name, const int fn) {
	if (studentsSize >= STUDENTS_MAX_SIZE) return false;

	this->students[studentsSize++] = new Student(name, fn);
	return true;
}

bool OOPCourse::addGrade(const int fn, const char* task, const short grade, const char* from) {
	Student student = getStudentByFn(fn);
	return student.addGrade(Grade(grade, task, from));
}

Student& OOPCourse::getStudentByFn(const int fn) {
	for (size_t i = 0; i < studentsSize; i++)
	{
		if ((*students[i]).getFn() == fn)
		{
			return *students[i];
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

double OOPCourse::getAverageGradePerTask(const char* task) {
	int count = 0;
	double sum = 0;

	for (size_t i = 0; i < studentsSize; i++)
	{
		const Grade* grades = (*students[i]).getGrades();
		short gradesCount = (*students[i]).getGradesCount();

		for (size_t i = 0; i < gradesCount; i++)
		{
			if (strcmp(grades[i].getTask(), task))
			{
				sum += grades[i].getGrade();
				count++;
			}
		}
	}

	// TODO: check division by 0
	return sum / count;
}

double OOPCourse::getAverageFromTeacher(const char* from) {
	int count = 0;
	double sum = 0;

	for (size_t i = 0; i < studentsSize; i++)
	{
		const Grade* grades = (*students[i]).getGrades();
		short gradesCount = (*students[i]).getGradesCount();

		for (size_t i = 0; i < gradesCount; i++)
		{
			if (strcmp(grades[i].getFrom(), from))
			{
				sum += grades[i].getGrade();
				count++;
			}
		}
	}

	// TODO: check division by 0
	return sum / count;
}