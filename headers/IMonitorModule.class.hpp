#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

#include <iostream>

class SfmlDisplay;
class NcursesDisplay;

class IMonitorModule {
public:
	virtual std::string getModuleName(void) const = 0;
	virtual void displaySfml(SfmlDisplay * sfml) = 0;
	virtual void displayNcurse(NcursesDisplay * nc) = 0;
};

#endif