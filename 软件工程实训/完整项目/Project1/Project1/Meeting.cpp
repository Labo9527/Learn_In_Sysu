#include "Meeting.hpp"
#include "Date.hpp"
#include "User.hpp"

Meeting::Meeting(const std::string &t_sponsor,
	const std::vector<std::string> &t_participator,
	const Date &t_startTime, const Date &t_endTime,
	const std::string &t_title) {
	m_sponsor = t_sponsor;
	m_participators = t_participator;
	m_startDate = t_startTime;
	m_endDate = t_endTime;
	m_title = t_title;
}

Meeting::Meeting(const Meeting &t_meeting) {
	m_sponsor = t_meeting.m_sponsor;
	m_participators = t_meeting.m_participators;
	m_title = t_meeting.m_title;
	m_endDate = t_meeting.m_endDate;
	m_startDate = t_meeting.m_startDate;
}

std::string Meeting::getSponsor() const {
	return m_sponsor;
}

void Meeting::setSponsor(const std::string &t_sponsor) {
	m_sponsor = t_sponsor;
}

std::vector<std::string> Meeting::getParticipator() const {
	return m_participators;
}

void Meeting::setParticipator(const std::vector<std::string> &t_participators) {
	m_participators = t_participators;
}

void Meeting::addParticipator(const std::string &t_participator) {
	m_participators.push_back(t_participator);
}

void Meeting::removeParticipator(const std::string &t_participator) {
	for(int i=0;i<m_participators.size();i++)
		if (m_participators[i] == t_participator) {
			m_participators.erase(m_participators.begin() + i);
			return;
		}
}

Date Meeting::getStartDate() const {
	return m_startDate;
}

Date Meeting::getEndDate() const {
	return m_endDate;
}

void Meeting::setStartDate(const Date &t_startTime) {
	m_startDate = t_startTime;
}

void Meeting::setEndDate(const Date &t_endTime) {
	m_endDate = t_endTime;
}

std::string Meeting::getTitle() const {
	return m_title;
}

void Meeting::setTitle(const std::string &t_title) {
	m_title = t_title;
}

bool Meeting::isParticipator(const std::string &t_username) const {
	for (int i = 0; i < m_participators.size(); i++)
		if (m_participators[i] == t_username)
			return true;
	return false;
}