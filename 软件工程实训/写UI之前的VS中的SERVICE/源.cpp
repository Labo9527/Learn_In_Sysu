#include <iostream>
#include "Storage.hpp"
#include "Meeting.hpp"
#include "Date.hpp"
#include "AgendaService.hpp"

using namespace std;

//0000 - 00 - 00 / 00:00

int main() {
	AgendaService T;
	Date Three("1999-12-01/12:12");
	User Four("123132", "12312345", "321", "56");
	vector<string> Par;
	Par.push_back("LAOli");
	Par.push_back("XIAOHONG");
	Par.push_back("LUOJI");
	Meeting Two("SSSDF", Par, Three,Date("2002-12-01/12:12"),"JustAConference");
	T.userRegister("YANG", "123", "2543761065@qq.com", "18027479799");
	T.userRegister("LAOli", "123", "2543761065@qq.com", "18027479799");
	T.userRegister("XIAOHONG", "123", "2543761065@qq.com", "18027479799");
	T.userRegister("LUOJI", "123", "2543761065@qq.com", "18027479799");
	T.userRegister("New", "123", "2543761065@qq.com", "18027479799");
	T.userRegister("New1", "123", "2543761065@qq.com", "18027479799");
	T.createMeeting("YANG", "SDCS", "1999-12-01/12:12", "2000-12-01/12:12", Par);
	T.createMeeting("YANG", "SDCS1", "1998-12-02/12:12", "1999-12-01/12:12", Par);
	Par.clear();
	Par.push_back("New");
	T.createMeeting("New1", "SDCS2", "1998-12-02/12:12", "1999-12-01/12:12", Par);
	T.userRegister("Yang", "123", "2543761065@qq.com", "18027479799");
	T.userLogIn("Yang", "123");
	T.userRegister("sad", "2", "123@@", "123231d");
	T.addMeetingParticipator("YANG", "SDCS", "YANG");
	auto F = T.listAllUsers();
	T.deleteUser("Yang", "1");
	F = T.listAllUsers();
	/*
	T.deleteUser("Yang", "123");
	*/
	return 0;
}