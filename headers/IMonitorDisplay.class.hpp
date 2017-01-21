#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

#include <iostream>

class IMonitorDisplay {
public:
	virtual void update(void) = 0;
	virtual std::string getHostName(void) const = 0;
	virtual std::string getUserName(void) const = 0;
};

#endif