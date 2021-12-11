/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

short leapYearMonthsWithDates[] = { 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
short normalYearMonthsWithDates[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

bool isLeapYear(unsigned int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}

	return false;
}

short getYearFromDays(int days) {
	short year = 1970;

	days += 1;
	while (days > 365)
	{
		if (days == 366 && isLeapYear(year)) {
			break;
		}

		isLeapYear(year) ? days -= 366 : days -= 365;
		if (days >= 0) {
			year++;
		}
	}

	return year;
}


short getMonth(int days) {
	short year = 1970;

	days += 1;
	while (days > 365)
	{
		if (days == 366 && isLeapYear(year)) {
			break;
		}

		isLeapYear(year) ? days -= 366 : days -= 365;
		if (days >= 0) {
			year++;
		}
	}

	if (isLeapYear(year)) {
		for (int i = 0; i < 12; i++)
		{
			if (days <= leapYearMonthsWithDates[i]) {
				return i + 1;
			}
		}
	}
	else {
		for (int i = 0; i < 12; i++)
		{
			if (days <= normalYearMonthsWithDates[i]) {
				return i + 1;
			}
		}
	}
}

short getMonthDate(int days) {
	short year = 1970;

	days += 1;
	while (days > 365)
	{
		if (days == 366 && isLeapYear(year)) {
			break;
		}

		isLeapYear(year) ? days -= 366 : days -= 365;
		if (days >= 0) {
			year++;
		}
	}

	if (days <= 31) {
		return days;
	}

	if (isLeapYear(year)) {
		for (int i = 1; i < 12; i++)
		{
			if (days <= leapYearMonthsWithDates[i]) {
				return days - leapYearMonthsWithDates[i - 1];
			}
		}
	}
	else {
		for (int i = 1; i < 12; i++)
		{
			if (days <= normalYearMonthsWithDates[i]) {
				return days - normalYearMonthsWithDates[i - 1];
			}
		}
	}
}

void consoleZeroIfNeeded(short number) {
	if (number < 10) {
		cout << "0";
	}

	cout << number;
}

int main()
{
	unsigned int seconds;
	cin >> seconds;

	int days = seconds / (60 * 60 * 24);

	short monthDate = getMonthDate(days);
	short month = getMonth(days);

	int leftSeconds = seconds % (60 * 60 * 24);
	short timeHours = leftSeconds / (60 * 60);
	short timeMinutes = (leftSeconds % (60 * 60)) / 60;
	short timeSeconds = leftSeconds % 60;

	consoleZeroIfNeeded(monthDate);
	cout << ".";
	consoleZeroIfNeeded(month);
	cout << ".";
	cout << getYearFromDays(days);
	cout << " ";
	consoleZeroIfNeeded(timeHours);
	cout << ":";
	consoleZeroIfNeeded(timeMinutes);
	cout << ":";
	consoleZeroIfNeeded(timeSeconds);
	cout << endl;
}