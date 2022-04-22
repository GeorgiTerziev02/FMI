#pragma once
class Grade
{
private:
	double grade;
	char* task;
	char* from;
public:
	Grade();
	Grade(const double grade, const char* task, const char* from);
	Grade(const Grade& other);
	Grade& operator=(const Grade& other);
	~Grade();

	double getGrade() const;
	const char* getTask() const;
	const char* getFrom() const;
private:
	void copy(const Grade& other);
	void free();
};

