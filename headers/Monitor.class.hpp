#ifndef MONITOR_HPP
# define MONITOR_HPP

#include "IMonitorModule.class.hpp"
#include "IMonitorDisplay.class.hpp"
#include <iostream>
#include <vector>

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