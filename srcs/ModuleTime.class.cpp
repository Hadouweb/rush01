#include "ModuleTime.class.hpp"

ModuleTime::ModuleTime(void) {

}

ModuleTime::ModuleTime(ModuleTime const &src) {
	*this = src;
}

ModuleTime::~ModuleTime(void) {

}

ModuleTime &ModuleTime::operator=(ModuleTime const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void ModuleTime::displaySfml(SfmlDisplay * sfml) {
	int endLine = sfml->getModuleEndLine();

	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::string outPutDate = "Date: ";
	outPutDate += std::to_string(ltm->tm_mday) + " ";
	outPutDate += std::to_string(ltm->tm_mon + 1) + " ";
	outPutDate += std::to_string(ltm->tm_year + 1900);

	std::string outPutTime = "Time: ";
	outPutTime += std::to_string(ltm->tm_hour) + ":";
	outPutTime += std::to_string(ltm->tm_min) + ":";
	outPutTime += std::to_string(ltm->tm_sec);

	sf::RectangleShape backgroundTitle(sf::Vector2f(120, 50));
	backgroundTitle.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 40));
	backgroundTitle.setPosition(0, endLine);
	backgroundTitle.setFillColor(sf::Color(155, 89, 182));

	sf::Text textModuleName(this->getModuleName(), sfml->getFont(), 50);
	endLine += 5;
	textModuleName.setPosition(sfml->getWindow().getSize().x / 2 - 100, endLine);
	textModuleName.setCharacterSize(24);
	textModuleName.setFillColor(sf::Color::White);

	endLine += 35;
	sf::RectangleShape background(sf::Vector2f(120, 50));
	background.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 110));
	background.setPosition(0, endLine);
	background.setFillColor(sf::Color(142, 68, 173));

	sf::Text textDate(outPutDate, sfml->getFont(), 50);
	endLine += 15;
	textDate.setPosition(50, endLine);
	textDate.setCharacterSize(24);
	textDate.setFillColor(sf::Color::White);

	sf::Text textTime(outPutTime, sfml->getFont(), 50);
	endLine += 35;
	textTime.setPosition(50, endLine);
	textTime.setCharacterSize(24);
	textTime.setFillColor(sf::Color::White);

	sfml->getWindow().draw(background);
	sfml->getWindow().draw(backgroundTitle);
	sfml->getWindow().draw(textModuleName);
	sfml->getWindow().draw(textDate);
	sfml->getWindow().draw(textTime);
	endLine += 55;
	sfml->setModuleEndLine(endLine);
}

void ModuleTime::displayNcurse(NcursesDisplay * nc) {
	if (nc)
		;
}

std::string ModuleTime::getModuleName(void) const {
	return "Date / Time";
}
