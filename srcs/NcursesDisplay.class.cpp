#include "NcursesDisplay.class.hpp"

NcursesDisplay::NcursesDisplay(std::vector<IMonitorModule *> modules) : _modules(modules) {
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, this->_winH, this->_winW);
	this->update();
}

NcursesDisplay::~NcursesDisplay(void) {

}

void NcursesDisplay::update(void) {
	while (42) {

		std::clock_t start = std::clock();

		this->setModuleEndLine(0);
		for (std::vector<IMonitorModule*>::iterator it = this->_modules.begin(); it != this->_modules.end(); ++it) {
			(*it)->displayNcurse(this);
		}
		refresh();
		int end = int(std::clock() - start);
		usleep(20000 - end);
	}
}

NcursesDisplay &NcursesDisplay::operator=(NcursesDisplay const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

int NcursesDisplay::getModuleEndLine() const {
	return this->_y;
}

void NcursesDisplay::setModuleEndLine(int y) {
	if (y >= 0 && y < this->_winH)
		this->_y = y;
}
