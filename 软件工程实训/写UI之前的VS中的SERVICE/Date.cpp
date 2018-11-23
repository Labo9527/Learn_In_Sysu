#include <iostream>
#include "Date.hpp"

Date::Date() {
	m_year = 0;
	m_month = 0;
	m_day = 0;
	m_hour = 0;
	m_minute = 0;
}

Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute) {
	m_year = t_year;
	m_month = t_month;
	m_day = t_day;
	m_hour = t_hour;
	m_minute = t_minute;
}
//"2002-12-01/12:12"
bool check_str(std::string str) {
	int len = str.length();
	if (len != 16)
		return false;
	if (str[4] != '-' || str[7] != '-' || str[10] != '/' || str[13] != ':')
		return false;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 7 || i == 10 || i == 13)
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

Date::Date(const std::string& dateString) {
	if (!check_str(dateString)) {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_hour = 0;
		m_minute = 0;
	}
	else {
		m_year = (dateString[0] - 48) * 1000 + (dateString[1] - 48) * 100 + (dateString[2] - 48) * 10 + (dateString[3] - 48) * 1;
		m_month = (dateString[5] - 48) * 10 + (dateString[6] - 48);
		m_day = (dateString[8] - 48) * 10 + (dateString[9] - 48);
		m_hour = (dateString[11] - 48) * 10 + (dateString[12] - 48);
		m_minute = (dateString[14] - 48) * 10 + (dateString[15] - 48);
	}
}

int Date::getYear() const {
	return m_year;
}

int Date::getHour() const{
	return m_hour;
}

int Date::getMinute() const {
	return m_minute;
}

void Date::setDay(const int t_day) {
	m_day = t_day;
}

void Date::setHour(const int t_hour) {
	m_hour = t_hour;
}

void Date::setMinute(const int t_minute) {
	m_minute = t_minute;
}

int Date::getDay() const {
	return m_day;
}

void Date::setMonth(const int t_month) {
	m_month = t_month;
}

void Date::setYear(const int t_year) {
	m_year = t_year;
}

int Date::getMonth() const {
	return m_month;
}

bool IsleapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || ((year % 400 == 0));
}

bool Date::isValid(const Date &t_date) {
	int DayOfMonths[13] = { 29,31,28,31,30,31,30
	,31,31,30,31,30,31 };
	if (t_date.m_year < 1000 || t_date.m_year>9999)
		return false;
	if (t_date.m_month <= 0 || t_date.m_month > 12)
		return false;
	if (t_date.m_month == 2 && IsleapYear(t_date.m_year)) {
		if (t_date.m_day <= 0 || t_date.m_day > DayOfMonths[0])
			return false;
	}
	else {
		if (t_date.m_day <= 0 || t_date.m_day > DayOfMonths[t_date.m_month])
			return false;
	}
	if (t_date.m_hour < 0 || t_date.m_hour >= 24)
		return false;
	if (t_date.m_minute < 0 || t_date.m_minute >= 60)
		return false;
	return true;
}

Date Date::stringToDate(const std::string &t_dateString) {
	return Date(t_dateString);
}



std::string Date::dateToString(const Date &t_date) {
	if (!isValid(t_date))
		return std::string("0000-00-00/00:00");
	std::string Res;
	int year = t_date.m_year;
	int month = t_date.m_month;
	int day = t_date.m_day;
	int hour = t_date.m_hour;
	int minute = t_date.m_minute;
	for (int i = 0; i < 4; i++) {
		Res.insert(0, 1, (char)(year % 10 + 48));
		year /= 10;
	}
	Res += '-';
	for (int i = 0; i < 2; i++) {
		Res.insert(5, 1, (char)(month % 10 + 48));
		month /= 10;
	}
	Res += '-';
	for (int i = 0; i < 2; i++) {
		Res.insert(8, 1, (char)(day % 10 + 48));
		day /= 10;
	}
	Res += '/';
	for (int i = 0; i < 2; i++) {
		Res.insert(11, 1, (char)(hour % 10 + 48));
		hour /= 10;
	}
	Res += ':';
	for (int i = 0; i < 2; i++) {
		Res.insert(14, 1, (char)(minute % 10 + 48));
		minute /= 10;
	}
	return Res;
}


Date &Date::operator=(const Date &t_date) {
	this->m_day = t_date.m_day;
	this->m_year = t_date.m_year;
	this->m_hour = t_date.m_hour;
	this->m_minute = t_date.m_minute;
	this->m_month = t_date.m_month;
	return *this;
}


bool Date::operator==(const Date &t_date) const {
	return m_day == t_date.m_day&&m_year == t_date.m_year&&m_hour == t_date.m_hour&&m_minute == t_date.m_minute&&m_month == t_date.m_month;
}

bool Date::operator>(const Date &t_date) const {
	if (m_year > t_date.m_year)
		return true;

	if (m_month > t_date.m_month&&m_year==t_date.m_day)
		return true;

	if (m_day > t_date.m_day&&m_month==t_date.m_month&&m_year == t_date.m_day)
		return true;

	if (m_hour > t_date.m_hour&&m_day==t_date.m_day&&m_month == t_date.m_month&&m_year == t_date.m_day)
		return true;

	if (m_minute > t_date.m_minute&&m_hour==t_date.m_hour&&m_day == t_date.m_day&&m_month == t_date.m_month&&m_year == t_date.m_day)
		return true;

	return false;
}

bool Date::operator<(const Date &t_date) const {
	return !((*this) > t_date) && !((*this) == t_date);
}

bool Date::operator>=(const Date &t_date) const {
	if (m_year >= t_date.m_year)
		return true;

	if (m_month >= t_date.m_month&&m_year == t_date.m_year)
		return true;

	if (m_day >= t_date.m_day&&m_month == t_date.m_month&&m_year == t_date.m_year)
		return true;

	if (m_hour >= t_date.m_hour&&m_day == t_date.m_day&&m_month == t_date.m_month&&m_year == t_date.m_year)
		return true;

	if (m_minute >= t_date.m_minute&&m_hour == t_date.m_hour&&m_day == t_date.m_day&&m_month == t_date.m_month&&m_year == t_date.m_year)
		return true;

	return false;
}

bool Date::operator<=(const Date &t_date) const {
	return ((*this) < t_date) || ((*this) == t_date);
}