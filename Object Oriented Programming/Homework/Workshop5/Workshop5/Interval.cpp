#include "Interval.h"
#include "Common.h"
#include <cmath>

Interval::Interval() {
	this->a = 0;
	this->b = 0;
}

Interval::Interval(const int& a, const int& b) {
	if (a > b)
	{
		Interval();
	}
	else {
		this->a = a;
		this->b = b;
	}
}

int Interval::getA() const {
	return this->a;
}

int Interval::getB() const {
	return this->b;
}

int Interval::getInterval() const {
	return this->b - this->a;
}

bool Interval::isInInterval(const int& number) const {
	return this->a <= number && number <= this->b;
}

int Interval::getPrimeNumbersCount() const {
	int counter = 0;
	for (int i = this->a; i <= this->b; i++)
	{
		if (i <= 1) continue;

		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime) counter++;
	}

	return counter;
}

int Interval::getPalindromesCount() const {
	int counter = 0;

	for (int i = this->a; i <= this->b; i++)
	{
		int temp = i;
		int reversed = 0;

		while (temp != 0)
		{
			reversed = reversed * 10 + temp % 10;
			temp /= 10;
		}

		if (i == reversed) counter++;
	}

	return counter;
}

int Interval::getUniqueNumbersCount() const {
	int counter = 0;

	for (int i = this->a; i <= this->b; i++)
	{
		int temp = i;
		bool isUnique = true;
		while (temp != 0)
		{
			int innerTemp = temp;
			while (innerTemp != 0)
			{
				innerTemp /= 10;
				if (innerTemp % 10 == temp % 10)
				{
					isUnique = false;
					break;
				}
			}

			if (!isUnique) break;
			temp /= 10;
		}

		if (isUnique) counter++;
	}

	return counter;
}

bool Interval::areEndsDegreeOfTwo() const {
	if (this->a == 0 || this->b == 0) return false;

	return (this->a & (this->a - 1)) == 0 && (this->b & (this->b - 1)) == 0;
}

Interval* Interval::getCommonInterval(const Interval& secondInterval) const {
	return new Interval(max(this->a, secondInterval.a), min(this->b, secondInterval.b));
}

bool Interval::isSuperinterval(const Interval& secondInterval) const {
	return this->a <= secondInterval.a && secondInterval.b <= this->b;
}