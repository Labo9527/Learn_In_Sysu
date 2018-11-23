#include "Storage.hpp"
#include "Date.hpp"
#include "User.hpp"
#include <fstream>
#include "Path.hpp"

std::shared_ptr<Storage> Storage::m_instance = nullptr;

Storage::Storage() {
	this->m_dirty = false;
	readFromFile();
}

bool Storage::readFromFile() {
	try {
		std::string Information;
		std::ifstream inFile1(Path::userPath, std::ios::in);
		std::ifstream inFile2(Path::meetingPath, std::ios::in);
		if (!inFile1.is_open() || !inFile2.is_open())
			return false;
		m_userList.clear();
		m_meetingList.clear();
		while (std::getline(inFile1, Information)) {
			User sample;
			std::string Collection[4];
			int j = 0;
			for (int i = 0; i < 4; i++) {
				while (Information[j] != ',') {
					if(Information[j]!='\"')
						Collection[i] += Information[j];
					j++;
					if (j >= Information.length())
						break;
				}
				if (j >= Information.length())
					break;
				j++;
			}
			sample.setName(Collection[0]);
			sample.setPassword(Collection[1]);
			sample.setEmail(Collection[2]);
			sample.setPhone(Collection[3]);
			m_userList.push_back(sample);

		}
		while (std::getline(inFile2, Information)) {
			Meeting Test;
			std::string Collection[5];
			int j = 0;
			for (int i = 0; i < 5; i++) {
				while (Information[j] != ',') {
					if (Information[j] != '\"'&&Information[i]!='\0')
						Collection[i] += Information[j];
					j++;
					if (j >= Information.length())
						break;
				}
				j++;
				if (j >= Information.length())
					break;
			}
			Test.setSponsor(Collection[0]);
			for (int i = 0; i < Collection[1].size(); i++) {
				std::string sample;
				while (Collection[1][i] != '&') {
					sample += Collection[1][i];
					i++;
					if (i >= Collection[1].length())
						break;
				}
				if(sample.length())
					Test.addParticipator(sample);
				if (i >= Collection[1].length())
					break;
			}
			Test.setStartDate(Date(Collection[2]));
			Test.setEndDate(Date(Collection[3]));
			Test.setTitle(Collection[4]);
			m_meetingList.push_back(Test);
		}
		m_dirty = false;
		return true;
	}
	catch(std::string msg){
		return false;
	}
}

bool Storage::writeToFile() {
	try {
		std::ofstream outFile1(Path::userPath, std::ios::out);
		std::ofstream outFile2(Path::meetingPath, std::ios::out);
		if (!outFile1.is_open() || !outFile2.is_open())
			return false;
		std::list<User>::iterator it1 = m_userList.begin();
		std::list<Meeting>::iterator it2 = m_meetingList.begin();
		while (it1 != m_userList.end()) {
			outFile1 << "\"" << it1->getName() << "\",\"" << it1->getPassword() << "\",\"" << it1->getEmail() << "\",\"" << it1->getPhone() << "\"" << std::endl;
			it1++;
		}
		while (it2 != m_meetingList.end()) {
			outFile2 << "\"" << it2->getSponsor() << "\",\"";
			std::vector<std::string> Sto = it2->getParticipator();
			for (int i = 0; i < Sto.size(); i++) {
				outFile2 << Sto[i];
				if (i != it2->getParticipator().size() - 1)
					outFile2 << "&";
			}
			outFile2 << "\",\"";
			outFile2 << Date::dateToString(it2->getStartDate()) << "\",\"";
			outFile2 << Date::dateToString(it2->getEndDate()) << "\",\"";
			outFile2 << it2->getTitle() << "\"" << std::endl;
			it2++;
		}
		m_dirty = false;
		return true;
	}
	catch (std::string msg) {
		return false;
	}
}

std::shared_ptr<Storage> Storage::getInstance() {
	if (m_instance != nullptr)
		return m_instance;
	m_instance =std::shared_ptr<Storage>(new Storage());
	return m_instance;
}


Storage::~Storage() {
	sync();
}

void Storage::createUser(const User &t_user) {
	m_userList.push_back(t_user);
	m_dirty = true;
}

std::list<User> Storage::queryUser(std::function<bool(const User &)> filter) const {
	std::list<User> Res;
	std::list<User>::const_iterator it = m_userList.begin();
	while (it != m_userList.end()) {
		if (filter(*it)) {
			Res.push_back(*it);
		}
		it++;
	}
	return Res;
}

int Storage::updateUser(std::function<bool(const User &)> filter,
	std::function<void(User &)> switcher) {
	int Res = 0;
	std::list<User>::iterator it = m_userList.begin();
	while (it != m_userList.end()) {
		if (filter(*it)) {
			switcher(*it);
			Res++;
		}
		it++;
	}
	m_dirty = true;
	return Res;
}

int Storage::deleteUser(std::function<bool(const User &)> filter) {
	int Res = 0;
	std::list<User>::iterator it = m_userList.begin();
	while (it != m_userList.end()) {
		if (filter(*it)) {
			std::list<User>::iterator temp = it;
			it = m_userList.erase(temp);
			Res++;
			continue;
		}
		it++;
	}
	m_dirty = true;
	return Res;
}

void Storage::createMeeting(const Meeting &t_meeting) {
	m_meetingList.push_back(t_meeting);
	m_dirty = true;
}

std::list<Meeting> Storage::queryMeeting(
	std::function<bool(const Meeting &)> filter) const {
	std::list<Meeting> Res;
	std::list<Meeting>::const_iterator it = m_meetingList.begin();
	while (it != m_meetingList.end()) {
		if (filter(*it)) {
			Res.push_back(*it);
		}
		it++;
	}
	return Res;
}

int Storage::updateMeeting(std::function<bool(const Meeting &)> filter,
	std::function<void(Meeting &)> switcher) {
	int Res = 0;
	std::list<Meeting>::iterator it = m_meetingList.begin();
	while (it != m_meetingList.end()) {
		if (filter(*it)) {
			switcher(*it);
			Res++;
		}
		it++;
	}
	m_dirty = true;
	return Res;
}

int Storage::deleteMeeting(std::function<bool(const Meeting &)> filter) {
	int Res = 0;
	std::list<Meeting>::iterator it = m_meetingList.begin();
	while (it != m_meetingList.end()) {
		if (filter(*it)) {
			std::list<Meeting>::iterator temp = it;
			it=m_meetingList.erase(temp);
			Res++;
			continue;
		}
		it++;
	}
	m_dirty = true;
	return Res;
}

bool Storage::sync() {
	if (!m_dirty)
		return false;
	return writeToFile();
}
