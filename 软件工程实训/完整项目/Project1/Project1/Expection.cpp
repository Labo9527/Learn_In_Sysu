#include "Expection.hpp"

string Error::what() {
	return msg;
}

Error::Error() {
	msg = string("Error(s) happen");
}

UserNotExist::UserNotExist(string people) {
	User = people;
	msg = User + " doesn't Exist";
}

DateCrash::DateCrash(string people) {
	User = people;
	msg = User + " is busy.";
}

DateFormatError::DateFormatError(string IS) {
	InvalidString = IS;
	msg = IS + " is wrong format.";
}