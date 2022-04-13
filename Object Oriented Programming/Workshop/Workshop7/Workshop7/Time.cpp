#include "Time.h"

Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(const unsigned short hours, const unsigned short minutes, const unsigned short seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time& Time::getTimeToMidnight() {

}

bool Time::isDinnerTime() {
	return (Time{ 20, 29, 59 }).isLater(*this) && (* this).isLater(Time{23, 0, 1});
}

bool Time::isPartyTime() {
	//return 23 <= hours &&
}

Time& Time::difference(const Time& otherTime) {

}

/// <summary>
/// returns if the given time is later
/// </summary>
/// <param name="time"></param>
/// <returns></returns>
bool Time::isLater(const Time& time) {
	if (this->hours < time.hours) return true;
	if (this->hours > time.hours) return false;
	
	if (this->minutes < time.minutes) return true;
	if (this->minutes > time.minutes) return true;

	return this->seconds < time.seconds;
}