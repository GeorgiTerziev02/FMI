#pragma once
class Interval {
private:
	int a;
	int b;
public:
	Interval();

	Interval(const int& a, const int& b);

	int getA() const;

	int getB() const;

	int getInterval() const;

	bool isInInterval(const int& number) const;

	int getPrimeNumbersCount() const;

	int getPalindromesCount() const;

	int getUniqueNumbersCount() const;

	bool areEndsDegreeOfTwo() const;

	Interval* getCommonInterval(const Interval& secondInterval) const;

	bool isSuperinterval(const Interval& secondInterval) const;
};