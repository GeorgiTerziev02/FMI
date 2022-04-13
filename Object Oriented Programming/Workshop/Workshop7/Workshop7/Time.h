#pragma once

class Time
{
private:
	unsigned short hours;
	unsigned short minutes;
	unsigned short seconds;
public:
	Time();
	Time(const unsigned short hours, const unsigned short minutes, const unsigned short seconds);

	Time& getTimeToMidnight();
	bool isDinnerTime();
	bool isPartyTime();
	Time& difference(const Time& otherTime);
	bool isLater(const Time& time);
};

