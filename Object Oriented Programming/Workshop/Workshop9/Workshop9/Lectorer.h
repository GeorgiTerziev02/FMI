#pragma once
class Lectorer
{
private:
	char* name;
public:
	Lectorer();
	Lectorer(const char* name);
	Lectorer(const Lectorer& lectorer);
	Lectorer& operator=(const Lectorer& lectorer);
	~Lectorer();

private:
	void copy(const Lectorer& other);
	void free();
};

