#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"
#include <vector>

class IMonitorDisplay {
public:
	virtual void update(void) = 0;
	virtual int getModuleEndLine() const = 0;
	virtual void setModuleEndLine(int y) = 0;
};

#endif