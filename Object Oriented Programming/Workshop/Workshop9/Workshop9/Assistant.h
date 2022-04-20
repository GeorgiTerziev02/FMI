#pragma once
class Assistant
{
private:
	char* name;
public:
	Assistant();
	Assistant(const char* name);
	Assistant(const Assistant& lectorer);
	Assistant& operator=(const Assistant& lectorer);
	~Assistant();

private:
	void copy(const Assistant& other);
	void free();
};

