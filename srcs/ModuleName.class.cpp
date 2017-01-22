#include "ModuleName.class.hpp"

ModuleName::ModuleName(void) {

}

ModuleName::ModuleName(ModuleName const &src) {
	*this = src;
}

ModuleName::~ModuleName(void) {

}

ModuleName &ModuleName::operator=(ModuleName const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void ModuleName::displaySfml(SfmlDisplay * sfml) const {
	char hostname[256];
	char username[256];

	gethostname(hostname, 256);
	getlogin_r(username, 256);

	std::string outPutHostName = "Hostname: ";
	std::string outPutUserName = "Username: ";
	outPutHostName += hostname;
	outPutUserName += username;

	sf::Text textHostName(outPutHostName, sfml->getFont(), 50);
	textHostName.setPosition(50, 10);
	textHostName.setCharacterSize(24);
	textHostName.setFillColor(sf::Color::White);

	sf::Text textUserName(outPutUserName, sfml->getFont(), 50);
	textUserName.setPosition(50, 40);
	textUserName.setCharacterSize(24);
	textUserName.setFillColor(sf::Color::White);

	sfml->getWindow().draw(textHostName);
	sfml->getWindow().draw(textUserName);
}

void ModuleName::displayNcurse(void) const {

}
