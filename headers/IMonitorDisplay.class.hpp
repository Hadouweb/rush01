#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"
#include <vector>
#include "ModuleName.class.hpp"

class IMonitorDisplay {
public:
	virtual void update(void) = 0;
	virtual void displayModule(ModuleName * m) = 0;
};

#endif