#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP



class SfmlDisplay;

class IMonitorModule {
public:
	virtual void displaySfml(SfmlDisplay * sfml) const = 0;
	virtual void displayNcurse(void) const = 0;
};

#endif