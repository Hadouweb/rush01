#include "ModuleName.class.hpp"

ModuleName::ModuleName(void) {
	gethostname(this->_hostName, 256);
	getlogin_r(this->_userName, 256);
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

void ModuleName::displaySfml(SfmlDisplay * sfml) {
	int endLine = sfml->getModuleEndLine();

	std::string outPutHostName = "Hostname: ";
	std::string outPutUserName = "Username: ";
	outPutHostName += this->_hostName;
	outPutUserName += this->_userName;

	sf::RectangleShape backgroundTitle(sf::Vector2f(120, 50));
	backgroundTitle.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 40));
	backgroundTitle.setPosition(0, endLine);
	backgroundTitle.setFillColor(sf::Color(22, 160, 133));

	sf::Text textModuleName(this->getModuleName(), sfml->getFont(), 50);
	endLine += 5;
	textModuleName.setPosition(sfml->getWindow().getSize().x / 2 - 100, endLine);
	textModuleName.setCharacterSize(24);
	textModuleName.setFillColor(sf::Color::White);

	endLine += 35;
	sf::RectangleShape background(sf::Vector2f(120, 50));
	background.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 110));
	background.setPosition(0, endLine);
	background.setFillColor(sf::Color(26, 188, 156));

	sf::Text textHostName(outPutHostName, sfml->getFont(), 50);
	endLine += 15;
	textHostName.setPosition(50, endLine);
	textHostName.setCharacterSize(24);
	textHostName.setFillColor(sf::Color::White);

	sf::Text textUserName(outPutUserName, sfml->getFont(), 50);
	endLine += 35;
	textUserName.setPosition(50, endLine);
	textUserName.setCharacterSize(24);
	textUserName.setFillColor(sf::Color::White);

	sfml->getWindow().draw(background);
	sfml->getWindow().draw(backgroundTitle);
	sfml->getWindow().draw(textModuleName);
	sfml->getWindow().draw(textHostName);
	sfml->getWindow().draw(textUserName);
	endLine += 55;
	sfml->setModuleEndLine(endLine);
}

void ModuleName::displayNcurse(NcursesDisplay * nc) {
	int endLine = nc->getModuleEndLine();
	mvprintw(++endLine, 1, this->getModuleName().c_str());
	endLine += 2;
	mvprintw(endLine, 1, this->_userName);
	endLine += 1;
	mvprintw(endLine, 1, this->_hostName);
	endLine++;
	mvprintw(endLine, 1,"___________________________");
	nc->setModuleEndLine(endLine);
}

std::string ModuleName::getModuleName(void) const {
	return "User Information";
}
