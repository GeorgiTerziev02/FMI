#pragma once
class Grade
{
private:
	short grade;
	char* task;
	char* from;
public:
	Grade();
	Grade(const short grade, const char* task, const char* from);
	Grade(const Grade& other);
	Grade& operator=(const Grade& other);
	~Grade();

	short getGrade() const;
	const char* getTask() const;
	const char* getFrom() const;
private:
	void copy(const Grade& other);
	void free();
};

