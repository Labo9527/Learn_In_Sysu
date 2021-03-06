#include "AgendaService.hpp"
//[=]~[&]
AgendaService::AgendaService() {
	m_storage = Storage::getInstance();
}

AgendaService::~AgendaService() {

}

bool AgendaService::userLogIn(const std::string &userName, const std::string &password) {
	auto Fun = [&](const User& Sample)->bool {return Sample.getName() == userName&&Sample.getPassword() == password; };
	std::list<User> Output = m_storage->queryUser(Fun);
	if (Output.size() == 0)
		return false;
	return true;
}

bool AgendaService::userRegister(const std::string &userName, const std::string &password,
	const std::string &email, const std::string &phone) {
	auto Fun = [&](const User& Sample)->bool {return Sample.getName() == userName; };
	std::list<User> Same = m_storage->queryUser(Fun);
	if (Same.size() != 0)
		return false;
	m_storage->createUser(User(userName, password, email, phone));
	return true;
}

bool AgendaService::deleteUser(const std::string &userName, const std::string &password) {
	auto Fun = [&](const User& Sample)->bool {return Sample.getName() == userName&&Sample.getPassword() == password; };
	int Res = m_storage->deleteUser(Fun);
	if (Res == 0)
		return false;
	auto Fun1 = [&](const Meeting& Sample)->bool {return Sample.isParticipator(userName) || Sample.getSponsor() == userName; };
	m_storage->deleteMeeting(Fun1);
	return true;
}

std::list<User> AgendaService::listAllUsers(void) const {
	auto Fun = [&](const User& Sample)->bool {return true; };
	return m_storage->queryUser(Fun);
}

bool AgendaService::createMeeting(const std::string &userName,const std::string &title,
	const std::string &startDate, const std::string &endDate,
	const std::vector<std::string> &participator) {
	if (!Date::isValid(Date(startDate)) || !Date::isValid(Date(endDate)))
		return false;
	if (Date(startDate) > Date(endDate))
		return false;
	auto Fun=[&](const Meeting &Sample)->bool {
		if (Sample.getTitle() == title)
			return true;
		return false;
	};
	std::list<Meeting> Sam = m_storage->queryMeeting(Fun);
	if (Sam.size() != 0)
		return false;
	auto Fun1 = [&](const User& K)->bool {
		return K.getName() == userName;
	};
	std::list<User> Sample = m_storage->queryUser(Fun1);
	if (Sample.size() == 0)
		return false;
	std::string KT;
	auto Fun2 = [&](const User& K)->bool {
		return K.getName() == KT;
	};
	int Size = participator.size();
	for (int i = 0; i < Size; i++) {
		KT = participator[i];
		std::list<User> J = m_storage->queryUser(Fun2);
		if (J.size() == 0)
			return false;
		if (participator[i] == userName)
			return false;
		std::list<Meeting> L = listAllMeetings(participator[i]);
		for (auto j = L.begin(); j != L.end(); j++) {
			if (j->getEndDate() <= startDate)
				continue;
			if (j->getStartDate() >= endDate)
				continue;
			return false;
		}
		for (int j = i + 1; j < Size; j++)
			if (participator[j] == participator[i])
				return false;
	}
	std::list<Meeting> L = listAllMeetings(userName);
	for (auto j = L.begin(); j != L.end(); j++) {
		if (j->getEndDate() <= startDate)
			continue;
		if (j->getStartDate() >= endDate)
			continue;
		return false;
	}
	m_storage->createMeeting(Meeting(userName, participator,startDate, endDate,title));
	return true;
}

bool AgendaService::addMeetingParticipator(const std::string &userName,
	const std::string &title,
	const std::string &participator) {
	if (userName == participator)
		return false;
	auto Fun = [&](const User &Sample)->bool {return Sample.getName() == userName; };
	auto T = m_storage->queryUser(Fun);
	if (T.size() == 0)
		return false;
	auto Fun4 = [&](const User &Sample)->bool {return Sample.getName() == participator; };
	T = m_storage->queryUser(Fun4);
	if (T.size() == 0)
		return false;
	auto Fun1 = [&](const Meeting &Sample1)->bool {
		return Sample1.getSponsor() == userName&&Sample1.getTitle() == title;
	};
	auto Fun2 = [&](Meeting &Sample2)->void {
		if (Sample2.isParticipator(participator))
			return;
		Sample2.addParticipator(participator);
	};
	return m_storage->updateMeeting(Fun1, Fun2) != 0;//怀疑这里有问题？
}

bool AgendaService::removeMeetingParticipator(const std::string &userName,
	const std::string &title,
	const std::string &participator) {
	auto Fun = [&](const Meeting &Sample)->bool {
		if (Sample.getTitle() == title&&Sample.getSponsor() == userName) {
			return true;
		}
		return false;
	};
	auto Fun1 = [&](Meeting &Sample)->void {
		if (Sample.isParticipator(participator))//userName改为participator
			Sample.removeParticipator(participator);
	};
	if (m_storage->updateMeeting(Fun, Fun1) == 0)
		return false;
	auto X = m_storage->queryMeeting(Fun);
	auto K = X.begin();
	if ((*K).getParticipator().size() == 0)
		deleteMeeting(userName, title);
	return true;
}

bool AgendaService::quitMeeting(const std::string &userName, const std::string &title) {
	auto Fun = [&](const Meeting &Sample)->bool {
		return Sample.isParticipator(userName) && Sample.getTitle() == title;
	};
	auto Fun1 = [&](Meeting &Sample)->void {
		Sample.removeParticipator(userName);
	};
	return m_storage->updateMeeting(Fun, Fun1) != 0;
}

std::list<Meeting> AgendaService::listAllMeetings(const std::string &userName) const {
	auto Fun = [&](const Meeting &Sample)->bool {return Sample.isParticipator(userName)||Sample.getSponsor()==userName; };
	return m_storage->queryMeeting(Fun);
}

std::list<Meeting> AgendaService::listAllSponsorMeetings(const std::string &userName) const {
	auto Fun = [&](const Meeting &Sample)->bool {return Sample.getSponsor()==userName; };
	return m_storage->queryMeeting(Fun);
}

std::list<Meeting> AgendaService::listAllParticipateMeetings(
	const std::string &userName) const {
	auto Fun = [&](const Meeting &Sample)->bool {return Sample.isParticipator(userName); };
	return m_storage->queryMeeting(Fun);
}

bool AgendaService::deleteMeeting(const std::string &userName, const std::string &title) {
	auto Fun = [&](const Meeting &Sample)->bool {return Sample.getSponsor()==userName&&Sample.getTitle()==title; };
	int Re = m_storage->deleteMeeting(Fun);
	if (Re == 0)
		return false;
	return true;
}

bool AgendaService::deleteAllMeetings(const std::string &userName) {
	auto Fun = [&](const Meeting &Sample)->bool {return Sample.getSponsor() == userName; };
	int Re=m_storage->deleteMeeting(Fun);
	return Re!=0;
}

void AgendaService::startAgenda(void) {
	m_storage->sync();
}

void AgendaService::quitAgenda(void) {
	m_storage->sync();
}

std::list<Meeting> AgendaService::meetingQuery(const std::string &userName,
	const std::string &startDate,
	const std::string &endDate) const {
	auto Fun = [&](const Meeting &Sample)->bool {
		if (Sample.getSponsor() != userName && !Sample.isParticipator(userName))
			return false;
		if (Sample.getStartDate() >= startDate&&Sample.getEndDate() <= endDate)
			return true;
		return false;
	};
	return m_storage->queryMeeting(Fun);
}

std::list<Meeting> AgendaService::meetingQuery(const std::string &userName,
	const std::string &title) const {
	auto Fun = [&](const Meeting &Sample)->bool {
		if (Sample.getTitle() == title) {
			if (Sample.isParticipator(userName) || Sample.getSponsor() == userName)
				return true;
		}
		return false;
	};
	return m_storage->queryMeeting(Fun);
}