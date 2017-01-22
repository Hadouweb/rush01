#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

#include <iostream>

class SfmlDisplay;

class IMonitorModule {
public:
	virtual std::string getModuleName(void) const = 0;
	virtual void displaySfml(SfmlDisplay * sfml) const = 0;
	virtual void displayNcurse(void) const = 0;
};

#endif