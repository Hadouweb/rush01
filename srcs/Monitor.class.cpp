#include "Monitor.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "ModuleName.class.hpp"

Monitor::Monitor(void) {
	this->_modules.push_back(new ModuleName());
	this->setDisplay(new SfmlDisplay(this->_modules));
}

Monitor::Monitor(Monitor const &src) {
	*this = src;
}

Monitor::~Monitor(void) {
	this->_modules.clear();
}

Monitor &Monitor::operator=(Monitor const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void Monitor::setDisplay(IMonitorDisplay * d) {
	this->_currentDisplay = d;
}
