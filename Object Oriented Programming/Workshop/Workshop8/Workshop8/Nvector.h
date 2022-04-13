#pragma once
#include <iostream>

class Nvector
{
private:
	int size;
	int* coordinates;
public:
	Nvector();
	Nvector(int size);
	Nvector(const Nvector& other);
	Nvector& operator=(const Nvector& other);
	~Nvector();

	int& operator[](int index); // get set
	int operator[](int index) const; // get

	Nvector& operator+=(const Nvector& other);
	Nvector& operator-=(const Nvector& other);
	Nvector& operator*=(const int number);
	
	friend Nvector operator+(const Nvector& v1, const Nvector& v2);
	friend Nvector operator-(const Nvector& v1, const Nvector& v2);
	friend Nvector operator*(const Nvector& v1, const int number);
	
	friend std::istream& operator>>(std::istream& in, Nvector& nvector);
	friend std::ostream& operator<<(std::ostream& out, const Nvector& nvector);

	bool isPerpendicular(const Nvector& other) const;
	double getLength() const;

private:
	void free();
	void copy(const Nvector& other);
};

