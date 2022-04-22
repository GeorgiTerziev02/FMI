#pragma once
#include "Grade.h"

const int MAX_GRADES_SIZE = 7;

class Student
{
private:
	int fn;
	char* name;
	Grade grades[MAX_GRADES_SIZE];
	short gradesCount = 0;
public:
	Student();
	Student(const char* name, const int fn);
	Student(const Student& student);
	Student& operator=(const Student& student);
	~Student();

	int getFn() const;
	const char* getName() const;
	const Grade* getGrades() const;
	short getGradesCount() const;

	bool addGrade(const Grade& grade);
	bool editGrade(const Grade& grade);
private:
	void copy(const Student& student);
	void free();
};

