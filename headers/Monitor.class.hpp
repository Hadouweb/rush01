#ifndef MONITOR_HPP
# define MONITOR_HPP

#include "IMonitorDisplay.class.hpp"
#include "IMonitorModule.class.hpp"
#include <iostream>
#include <vector>
#include <unistd.h>


class Monitor {
public:
    Monitor(void);
    Monitor(Monitor const & src);

    virtual ~Monitor(void);

    Monitor & operator=(Monitor const & rhs);

    void setDisplay(IMonitorDisplay *d);

private:
	std::vector<IMonitorModule*> _modules;
	IMonitorDisplay *_currentDisplay;
};

#endif