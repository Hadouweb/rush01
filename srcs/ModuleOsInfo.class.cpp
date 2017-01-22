#include "ModuleOsInfo.class.hpp"

ModuleOsInfo::ModuleOsInfo(void) {
	size_t size = 256;

	sysctlbyname("kern.osrelease", this->_osRelease, &size, NULL, 0);
	sysctlbyname("kern.ostype", this->_osType, &size, NULL, 0);
}

ModuleOsInfo::ModuleOsInfo(ModuleOsInfo const &src) {
	*this = src;
}

ModuleOsInfo::~ModuleOsInfo(void) {

}

ModuleOsInfo &ModuleOsInfo::operator=(ModuleOsInfo const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void ModuleOsInfo::displaySfml(SfmlDisplay * sfml) {
	int endLine = sfml->getModuleEndLine();

	std::string outPutRelease = "Release: ";
	std::string outPutType = "Type: ";
	outPutRelease += this->_osRelease;
	outPutType += this->_osType;

	sf::RectangleShape backgroundTitle(sf::Vector2f(10, 5));
	backgroundTitle.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 40));
	backgroundTitle.setPosition(0, endLine);
	backgroundTitle.setFillColor(sf::Color(243, 156, 18));

	sf::Text textModuleOsInfo(this->getModuleName(), sfml->getFont(), 50);
	endLine += 5;
	textModuleOsInfo.setPosition(sfml->getWindow().getSize().x / 2 - 100, endLine);
	textModuleOsInfo.setCharacterSize(24);
	textModuleOsInfo.setFillColor(sf::Color::White);

	endLine += 35;
	sf::RectangleShape background(sf::Vector2f(120, 50));
	background.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 110));
	background.setPosition(0, endLine);
	background.setFillColor(sf::Color(241, 196, 15));

	sf::Text textRelease(outPutRelease, sfml->getFont(), 50);
	endLine += 15;
	textRelease.setPosition(50, endLine);
	textRelease.setCharacterSize(24);
	textRelease.setFillColor(sf::Color::White);

	sf::Text textType(outPutType, sfml->getFont(), 50);
	endLine += 35;
	textType.setPosition(50, endLine);
	textType.setCharacterSize(24);
	textType.setFillColor(sf::Color::White);


	sfml->getWindow().draw(background);
	sfml->getWindow().draw(backgroundTitle);
	sfml->getWindow().draw(textModuleOsInfo);
	sfml->getWindow().draw(textRelease);
	sfml->getWindow().draw(textType);
	endLine += 55;
	sfml->setModuleEndLine(endLine);
}

void ModuleOsInfo::displayNcurse(NcursesDisplay * nc) {
	int endLine = nc->getModuleEndLine();

	endLine += 2;
	mvprintw(endLine++, 1, this->getModuleName().c_str());
	endLine++;
	mvprintw(endLine, 1, this->_osRelease);
	mvprintw(endLine, 10, this->_osType);
	endLine++;
	mvprintw(endLine, 1,"___________________________");
	nc->setModuleEndLine(endLine);
}

std::string ModuleOsInfo::getModuleName(void) const {
	return "Os Information";
}
