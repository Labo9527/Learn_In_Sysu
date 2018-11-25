#include "AgendaUI.hpp"

void line() {
	std::cout << "-------------------------------" << std::endl;
}

void tip() {
	std::cout << std::endl;
	std::cout << "Agenda : ~$";
	std::cout << std::endl;
}

AgendaUI::AgendaUI() {
	line();
	std::cout << "Action:" << std::endl;
	std::cout << "l		- log in Agenda by user name and password" << std::endl;
	std::cout << "r		- register an Agenda account" << std::endl;
	std::cout << "q		- quit Agenda" << std::endl;
	line();
}

int findBlock(std::string input) {
	for (int i = 0; i < input.length(); i++)
		if (input[i] == ' ')
			return i;
	return -1;
}


void AgendaUI::startAgenda(void) {

}

void AgendaUI::userLogIn(void) {
	tip();
	std::string input;
	std::string userName;
	std::string password;
	std::cout << "[log in] [user name] [password]" << std::endl;
	std::cout << "[log in] ";
	std::getline(std::cin, input);
	int index = findBlock(input);
	userName = input.substr(0, index);
	password = input.substr(index + 1);
	if (m_agendaService.userLogIn(userName, password)) {
		std::cout << "[log in] ";
		std::cout << "succeed!" << std::endl;
		m_userName = userName;
		m_userPassword = password;
	}
	else {
		std::cout << "[error] ";
		std::cout << "log in fail!" << std::endl;
	}
}

void AgendaUI::userRegister(void) {
	std::string input;
	tip();
	std::cout << "[register] [user name] [email] [phone]" << std::endl;
	std::cout << "[register] ";
	std::getline(std::cin, input);

}