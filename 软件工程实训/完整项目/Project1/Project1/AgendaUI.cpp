#include "AgendaUI.h"
#include <iomanip>
#include <iostream>
#include "Expection.hpp"

bool q = false;
bool isLogIn = false;

AgendaUI::AgendaUI() {
	
}

void AgendaUI::userRegister() {
	std::string username, password, email, phone;
	std::cout << "[register] [username] [password] [email] [phone]" << std::endl;
	std::cout << "[register] ";
	std::cin >> username >> password >> email >> phone;
	if (m_agendaService.userRegister(username, password, email, phone)) {
		std::cout << "[register] succeed!" << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "[register] This username has been registered!" << std::endl;
		std::cout << std::endl;
	}
}

void AgendaUI::startAgenda() {
	char choice = ' ';
	while (choice != 'q'&&!isLogIn) {
		std::cout << "---------------------Agenda---------------------" << std::endl;
		std::cout << "Action :" << std::endl;
		std::cout << "l    - log in Agenda by user name and password" << std::endl;
		std::cout << "r    - register an Agenda account" << std::endl;
		std::cout << "q    - quit Agenda" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Agenda : ~$ ";
		std::cin >> choice;
		if (choice == 'l') {
			userLogIn();
		}
		else if (choice == 'r') {
			userRegister();
		}
		else if (choice == 'q') {
			q = true;
			break;
		}
	}
}

std::string AgendaUI::getOperation() {
	std::string operation;
	std::cout<<std::endl;
	std::cout << "Agenda@" << m_userName << " :~# ";
	std::cin >> operation;
	return operation;
}

void AgendaUI::listAllUsers() {
	std::cout << "[list all users]" << std::endl;
	std::cout << std::endl;
	std::cout <<std::left<< std::setw(20) << "name" << std::setw(20) << "email" << std::setw(20) << "phone" << std::endl;
	auto Users = m_agendaService.listAllUsers();
	for (auto i = Users.begin(); i != Users.end(); i++) {
		std::cout <<std::left<< std::setw(20) << i->getName() << std::setw(20) << i->getEmail() << std::setw(20) << i->getPhone() << std::endl;
	}
}

bool IsleapYea(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || ((year % 400 == 0));
}

void IncreDate(Date& sample) {
	int DayOfMonths[13] = { 29,31,28,31,30,31,30
		,31,31,30,31,30,31 };
	if (sample.getMonth() == 2 && ((sample.getDay() == DayOfMonths[0]&&IsleapYea(sample.getYear()))||(sample.getDay()==DayOfMonths[2]&&!IsleapYea(sample.getYear())))) {
		sample.setMonth(3);
		sample.setDay(1);
	}
	else if (sample.getDay() == DayOfMonths[sample.getMonth()]) {
		if (sample.getMonth() == 12) {
			sample.setYear(sample.getYear() + 1);
			sample.setMonth(1);
			sample.setDay(1);
		}
		else {
			sample.setMonth(sample.getMonth() + 1);
			sample.setDay(1);
		}
	}
	else
		sample.setDay(sample.getDay() + 1);
}

Date getNewDate(Date One, int days) {
	Date Res = One;
	for (int i = 0; i < days; i++)
		IncreDate(Res);
	return Res;
}

void AgendaUI::createMeeting() {
	int model = 0;
	std::cout << "[create meeting] choose model 1 or 2" << std::endl;
	while (model != 1 && model != 2)
		std::cin >> model;
	if (model == 1) {
		int number;
		std::vector<std::string> participators;
		std::cout << "[create meeting] [the number of participators]" << std::endl;
		std::cout << "[create meeting] ";
		std::cin >> number;
		for (int i = 0; i < number; i++) {
			std::string participator;
			std::cout << "[create meeting] [please enter the participator " << (i + 1) << " ]" << std::endl;
			std::cout << "[create meeting] ";
			std::cin >> participator;
			participators.push_back(participator);
		}
		std::cout << "[create meeting] [title][start time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]" << std::endl;
		std::string title, start, end;
		std::cout << "[create meeting] ";
		std::cin >> title >> start >> end;
		try {
			if (m_agendaService.meetingQuery(m_userName, title).size() != 0)
				throw TitleExist();
			for (int j = 0; j < participators.size(); j++) {
				auto Users = m_agendaService.listAllUsers();
				bool flag = false;
				for (auto i = Users.begin(); i != Users.end(); i++) {
					if (i->getName() == participators[j])
						flag = true;
				}
				if (flag == false)
					throw UserNotExist(participators[j]);
			}
			if (!Date::isValid(start) || !Date::isValid(end))
				throw DateFormatError();
			if (Date::Date(start) >= Date::Date(end))
				throw DateIntervalError();
			for (int j = 0; j < participators.size(); j++) {
				auto Meetings = m_agendaService.listAllMeetings(participators[j]);
				for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
					if (!(i->getStartDate() >= Date::Date(end) || i->getEndDate() <= Date::Date(start)))
						throw DateCrash(participators[j]);
				}
			}
		}
		catch (TitleExist e1) {
			std::cout << e1.what() << std::endl;
		}
		catch (UserNotExist e2) {
			std::cout << e2.what() << std::endl;
		}
		catch (DateFormatError e3) {
			std::cout << e3.what() << std::endl;
		}
		catch (DateIntervalError e4) {
			std::cout << e4.what() << std::endl;
		}
		catch (DateCrash e5) {
			std::cout << e5.what() << std::endl;
		}
		if (m_agendaService.createMeeting(m_userName, title, start, end, participators))
			std::cout << "[create meeting] succeed!" << std::endl;
		else
			std::cout << "[create meeting] error!" << std::endl;
	}
	else {
		int number;
		std::vector<std::string> participators;
		std::cout << "[create meeting] [the number of participators]" << std::endl;
		std::cout << "[create meeting] ";
		std::cin >> number;
		for (int i = 0; i < number; i++) {
			std::string participator;
			std::cout << "[create meeting] [please enter the participator " << (i + 1) << " ]" << std::endl;
			std::cout << "[create meeting] ";
			std::cin >> participator;
			participators.push_back(participator);
		}
		std::string title, start, end;
		int beginYear, beginMonth, beginDay, beginHour, beginMinute, Days;
		std::cout << "[create meeting] [title] :";
		std::cin >> title;
		std::cout << "[create meeting] Meeting Begin int xxxx Year: ";
		std::cin >> beginYear;
		std::cout << "[create meeting] Meeting Begin int xx Month: ";
		std::cin >> beginMonth;
		std::cout << "[create meeting] Meeting Begin at xx Day: ";
		std::cin >> beginDay;
		std::cout << "[create meeting] Meeting Begin at xx hour: ";
		std::cin >> beginHour;
		std::cout << "[create meeting] Meeting Begin at xx minute: ";
		std::cin >> beginMinute;
		std::cout << "[create meeting] Enter the number of days in the meeting ";
		std::cin >> Days;
		Date ST(beginYear, beginMonth, beginDay, beginHour, beginMinute);
		Date END = getNewDate(ST, Days);
		start = Date::dateToString(ST);
		end = Date::dateToString(END);
		try {
			if (m_agendaService.meetingQuery(m_userName, title).size() != 0)
				throw TitleExist();
			for (int j = 0; j < participators.size(); j++) {
				auto Users = m_agendaService.listAllUsers();
				bool flag = false;
				for (auto i = Users.begin(); i != Users.end(); i++) {
					if (i->getName() == participators[j])
						flag = true;
				}
				if (flag == false)
					throw UserNotExist(participators[j]);
			}
			if (!Date::isValid(start) || !Date::isValid(end))
				throw DateFormatError();
			if (Date::Date(start) >= Date::Date(end))
				throw DateIntervalError();
			for (int j = 0; j < participators.size(); j++) {
				auto Meetings = m_agendaService.listAllMeetings(participators[j]);
				for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
					if (!(i->getStartDate() >= Date::Date(end) || i->getEndDate() <= Date::Date(start)))
						throw DateCrash(participators[j]);
				}
			}
		}
		catch (TitleExist e1) {
			std::cout << e1.what() << std::endl;
		}
		catch (UserNotExist e2) {
			std::cout << e2.what() << std::endl;
		}
		catch (DateFormatError e3) {
			std::cout << e3.what() << std::endl;
		}
		catch (DateIntervalError e4) {
			std::cout << e4.what() << std::endl;
		}
		catch (DateCrash e5) {
			std::cout << e5.what() << std::endl;
		}
		if (m_agendaService.createMeeting(m_userName, title, start, end, participators))
			std::cout << "[create meeting] succeed!" << std::endl;
		else
			std::cout << "[create meeting] error!" << std::endl;
	}
}

void AgendaUI::addMeetingParticipator() {
	std::string title, name;
	std::cout << "[add participator] [meeting title] [participator username]" << std::endl;
	std::cout << "[add participator] ";
	std::cin >> title >> name;
	if (m_agendaService.addMeetingParticipator(m_userName,title,name))
		std::cout << "[add participator] succeed!" << std::endl;
	else
		std::cout << "[add participator] error!" << std::endl;
}

void AgendaUI::removeMeetingParticipator() {
	std::string title, name;
	std::cout << "[remove participator] [meeting titile] [participator username]" << std::endl;
	std::cout << "[remove participator] ";
	std::cin >> title >> name;
	if (m_agendaService.removeMeetingParticipator(m_userName, title, name))
		std::cout << "[remove participator] succeed!" << std::endl;
	else
		std::cout << "[remove participator] error!" << std::endl;
}

void AgendaUI::listAllMeetings() {
	std::cout << "[list all meetings]" << std::endl;
	std::cout << std::endl;
	std::cout <<std::left<< std::setw(20) << "title" << std::setw(20) << "sponsor" << std::setw(20) << "start time" << std::setw(20) << "end time" << std::setw(20) << "participators" << std::endl;
	auto Meetings = m_agendaService.listAllMeetings(m_userName);
	for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
		int Flag = 0;
		std::cout <<std::left<< std::setw(20) << i->getTitle() << std::setw(20) << i->getSponsor() << std::setw(20) << Date::dateToString(i->getStartDate()) << std::setw(20) << Date::dateToString(i->getEndDate());
		auto Participators = i->getParticipator();
		for (auto j = Participators.begin(); j != Participators.end(); j++) {
			if (Flag != 0) {
				std::cout << ",";
			}
			Flag++;
			std::cout << (*j);
		}
		std::cout << std::endl;
	}
}

void AgendaUI::quitMeeting() {
	std::string title;
	std::cout << "[quit meeting] [meeting title]" << std::endl;
	std::cout << "[quit meeting] ";
	std::cin >> title;
	if (m_agendaService.quitMeeting(m_userName, title))
		std::cout << "[quit meeting] succeed!" << std::endl;
	else
		std::cout << "[quit meeting] error!" << std::endl;
}

void AgendaUI::listAllSponsorMeetings() {
	std::cout << "[list all sponsor metings]" << std::endl;
	std::cout << std::endl;
	std::cout <<std::left<< std::setw(20) << "title" << std::setw(20) << "sponsor" << std::setw(20) << "start time" << std::setw(20) << "end time" << std::setw(20) << "participators" << std::endl;
	auto Meetings = m_agendaService.listAllSponsorMeetings(m_userName);
	for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
		int Flag = 0;
		std::cout <<std::left<< std::setw(20) << i->getTitle() << std::setw(20) << i->getSponsor() << std::setw(20) << Date::dateToString(i->getStartDate()) << std::setw(20) << Date::dateToString(i->getEndDate());
		auto Participators = i->getParticipator();
		for (auto j = Participators.begin(); j != Participators.end(); j++) {
			if (Flag != 0) {
				std::cout << ",";
			}
			Flag++;
			std::cout << (*j);
		}
		std::cout << std::endl;
	}
}

void AgendaUI::listAllParticipateMeetings() {
	std::cout << "[list all participator metings]" << std::endl;
	std::cout << std::endl;
	std::cout <<std::left<< std::setw(20) << "title" << std::setw(20) << "sponsor" << std::setw(20) << "start time" << std::setw(20) << "end time" << std::setw(20) << "participators" << std::endl;
	auto Meetings = m_agendaService.listAllParticipateMeetings(m_userName);
	for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
		int Flag = 0;
		std::cout <<std::left<< std::setw(20) << i->getTitle() << std::setw(20) << i->getSponsor() << std::setw(20) << Date::dateToString(i->getStartDate()) << std::setw(20) << Date::dateToString(i->getEndDate());
		auto Participators = i->getParticipator();
		for (auto j = Participators.begin(); j != Participators.end(); j++) {
			if (Flag != 0) {
				std::cout << ",";
			}
			Flag++;
			std::cout << (*j);
		}
		std::cout << std::endl;
	}
}

void AgendaUI::queryMeetingByTitle() {
	std::string title;
	std::cout << "[query meeting] [title]:" << std::endl;
	std::cout << "[query meeting] ";
	std::cin >> title;
	std::cout <<std::left<< std::setw(20) << "title" << std::setw(20) << "sponsor" << std::setw(20) << "start time" << std::setw(20) << "end time" << std::setw(20) << "participators" << std::endl;
	auto Meetings = m_agendaService.meetingQuery(m_userName,title);
	for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
		int Flag = 0;
		std::cout <<std::left<< std::setw(20) << i->getTitle() << std::setw(20) << i->getSponsor() << std::setw(20) << Date::dateToString(i->getStartDate()) << std::setw(20) << Date::dateToString(i->getEndDate());
		auto Participators=i->getParticipator();
		for (auto j = Participators.begin(); j != Participators.end(); j++) {
			if (Flag != 0) {
				std::cout << ",";
			}
			Flag++;
			std::cout << (*j);
		}
		std::cout << std::endl;
	}
}

void AgendaUI::deleteMeetingByTitle() {
	std::string title;
	std::cout << "[delete meeting] [title]" << std::endl;
	std::cout << "[delete meeting] ";
	std::cin >> title;
	if (m_agendaService.deleteMeeting(m_userName, title))
		std::cout << "[delete meeting] succeed!" << std::endl;
	else
		std::cout << "[error] delete meeting fail!" << std::endl;
}

void AgendaUI::queryMeetingByTimeInterval() {
	std::string start, end;
	std::cout << "[query meetings] [start time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]" << std::endl;
	std::cout << "[query meetings] ";
	std::cin >> start >> end;
	if (!Date::isValid(Date::dateToString(start)) || !Date::isValid(Date::dateToString(end))) {
		std::cout << "[query meetings] error!" << std::endl;
		return;
	}
	std::cout << "[query meetings]" << std::endl;
	std::cout << std::endl;
	std::cout <<std::left<< std::setw(20) << "title" << std::setw(20) << "sponsor" << std::setw(20) << "start time" << std::setw(20) << "end time" << std::setw(20) << "participators" << std::endl;
	auto Meetings = m_agendaService.meetingQuery(m_userName,start,end);
	for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
		int Flag = 0;
		std::cout <<std::left<< std::setw(20) << i->getTitle() << std::setw(20) << i->getSponsor() << std::setw(20) << Date::dateToString(i->getStartDate()) << std::setw(20) << Date::dateToString(i->getEndDate());
		auto Participators = i->getParticipator();
		for (auto j = Participators.begin(); j != Participators.end(); j++) {
			if (Flag != 0) {
				std::cout << ",";
			}
			Flag++;
			std::cout << (*j);
		}
		std::cout << std::endl;
	}
}

void AgendaUI::deleteAllMeetings() {
	m_agendaService.deleteAllMeetings(m_userName);
	std::cout << "[delete all meeting] succeed!" << std::endl;
}

void AgendaUI::printMeetings(std::list<Meeting> t_meetings) {
	std::cout <<std::left<< std::setw(20) << "title" << std::setw(20) << "sponsor" << std::setw(20) << "start time" << std::setw(20) << "end time" << std::setw(20) << "participators" << std::endl;
	auto Meetings = t_meetings;
	for (auto i = Meetings.begin(); i != Meetings.end(); i++) {
		int Flag = 0;
		std::cout <<std::left<< std::setw(20) << i->getTitle() << std::setw(20) << i->getSponsor() << std::setw(20) << Date::dateToString(i->getStartDate()) << std::setw(20) << Date::dateToString(i->getEndDate());
		auto Participators = i->getParticipator();
		for (auto j = Participators.begin(); j != Participators.end(); j++) {
			if (Flag != 0) {
				std::cout << ",";
			}
			Flag++;
			std::cout << (*j);
		}
		std::cout << std::endl;
	}
}

void AgendaUI::userLogOut() {
	isLogIn = false;
}

bool AgendaUI::executeOperation(std::string t_operation) {
	if (t_operation == "o") {
		userLogOut();
		return true;
	}
	else if (t_operation == "dc") {
		m_agendaService.deleteUser(m_userName, m_userPassword);
		isLogIn = false;
		std::cout << std::endl;
		std::cout << "[delete agenda account] succeed!" << std::endl;
		return true;
	}
	else if (t_operation == "lu") {
		std::cout << std::endl;
		listAllUsers();
		return true;
	}
	else if (t_operation == "cm") {
		std::cout << std::endl;
		createMeeting();
		return true;
	}
	else if (t_operation == "amp") {
		std::cout << std::endl;
		addMeetingParticipator();
		return true;
	}
	else if (t_operation == "rmp") {
		std::cout << std::endl;
		removeMeetingParticipator();
		return true;
	}
	else if (t_operation == "rqm") {
		std::cout << std::endl;
		quitMeeting();
		return true;
	}
	else if (t_operation == "la") {
		std::cout << std::endl;
		listAllMeetings();
		return true;
	}
	else if (t_operation == "las") {
		std::cout << std::endl;
		listAllSponsorMeetings();
		return true;
	}
	else if (t_operation == "lap") {
		std::cout << std::endl;
		listAllParticipateMeetings();
		return true;
	}
	else if (t_operation == "qm") {
		std::cout << std::endl;
		queryMeetingByTitle();
		return true;
	}
	else if (t_operation == "qt") {
		std::cout << std::endl;
		queryMeetingByTimeInterval();
		return true;
	}
	else if (t_operation == "dm") {
		std::cout << std::endl;
		deleteMeetingByTitle();
		return true;
	}
	else if (t_operation == "da") {
		std::cout << std::endl;
		deleteAllMeetings();
		return true;
	}
	return false;
}

void AgendaUI::OperationLoop() {
	while (true) {
		while (!q && !isLogIn)
			startAgenda();
		if (q) {
			m_agendaService.quitAgenda();
			return;
		}
		std::string operation = getOperation();
		if (!executeOperation(operation))
			std::cout << "Error!" << std::endl;
	}
}


void AgendaUI::userLogIn() {
	std::string username, password;
	std::cout << std::endl;
	std::cout << "[log in] [username] [password]" << std::endl;
	std::cout << "[log in] ";
	std::cin >> username;
	std::cin >> password;
	if (m_agendaService.userLogIn(username, password)) {
		std::cout << "[log in] succeed!" << std::endl;
		std::cout << std::endl;
		m_userName = username;
		m_userPassword = password;
		isLogIn = true;
		std::cout << "---------------------Agenda---------------------" << std::endl;
		std::cout << "Action : " << std::endl;
		std::cout << "o    - log out Agenda" << std::endl;
		std::cout << "dc   - delete Agenda account" << std::endl;
		std::cout << "lu   - list all Agenda user" << std::endl;
		std::cout << "cm   - create a meeting" << std::endl;
		std::cout << "amp  - add meeting participator" << std::endl;
		std::cout << "rmp  - remove meeting participator" << std::endl;
		std::cout << "rqm  - request to quit meeting" << std::endl;
		std::cout << "la   - list all meetings" << std::endl;
		std::cout << "las  - list all sponsor meetings" << std::endl;
		std::cout << "lap  - list all participator meetings" << std::endl;
		std::cout << "qm   - query meeting by title." << std::endl;
		std::cout << "qt   - query meeting by time interval" << std::endl;
		std::cout << "dm   - delete meeting by title" << std::endl;
		std::cout << "da   - delete all meetings" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "[log in] Password error or user doesn't exist" << std::endl;
	}
}
