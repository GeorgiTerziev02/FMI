#pragma once
#include "Lectorer.h"
#include "Assistant.h"
#include "Student.h"

const short ASSISTANTS_MAX_SIZE = 3;
const short STUDENTS_MAX_SIZE = 50;

class OOPCourse
{
	Lectorer lectorer;
	Assistant assistants[ASSISTANTS_MAX_SIZE];
	Student* students[STUDENTS_MAX_SIZE];
	size_t studentsSize = 0;
public:
	OOPCourse() = default;
	OOPCourse(const char* lName, const char* a1Name);
	OOPCourse(const char* lName, const char* a1Name, const char* a2Name);
	OOPCourse(const char* lName, const char* a1Name, const char* a2Name, const char* a3Name);
	OOPCourse(const OOPCourse& other) = default;
	OOPCourse& operator=(const OOPCourse& other) = default;
	~OOPCourse() = default;

	bool addStudent(const char* name, const int fn);
	bool addGrade(const int fn, const char* task, const double grade, const char* from);
	bool editGrade(const int fn, const char* task, const double grade, const char* from);
	bool removeStudent(const int fn);
	double getAverageForCourse() const;
	double getAverageGradePerTask(const char* task) const;
	double getAverageFromTeacher(const char* from) const;

private:
	Student* getStudentByFn(const int fn) const;
};

