#include "Monitor.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "ModuleName.class.hpp"
#include "ModuleOsInfo.class.hpp"
#include "ModuleTime.class.hpp"
#include "ModuleCpu.class.hpp"

Monitor::Monitor(void) {
	this->_modules.push_back(new ModuleName());
	this->_modules.push_back(new ModuleOsInfo());
	this->_modules.push_back(new ModuleTime());
	this->_modules.push_back(new ModuleCpu());

	this->setDisplay(new SfmlDisplay(this->_modules));
	//this->setDisplay(new NcursesDisplay(this->_modules));
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
