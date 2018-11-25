#ifndef EXPECTION_H
#define EXPECTION_H

#include <exception>
#include <string>

using namespace std;

class Error :public exception {
public:
	string what();
	Error();
protected:
	string msg;
};

class UserNotExist :public Error {
public:
	UserNotExist() { User = "None"; };
	UserNotExist(string peopel);
private:
	string User;
};

class TitleExist :public Error {
public:
	TitleExist() { msg = "Title has existed!"; }
};

class DateCrash :public Error {
public:
	DateCrash() { User = "None"; };
	DateCrash(string people);
private:
	string User;
};

class DateFormatError :public Error {
public:
	DateFormatError() { InvalidString = "None"; };
	DateFormatError(string IS);
private:
	string InvalidString;
};

class DateIntervalError :public Error {
public:
	DateIntervalError() { msg = "Start Time should be before the End Time."; };
};


#endif EXPECTION_H