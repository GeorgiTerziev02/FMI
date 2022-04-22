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

	const char* getName() const;
private:
	void copy(const Lectorer& other);
	void free();
};

