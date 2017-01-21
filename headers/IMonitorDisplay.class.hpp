#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

class IMonitorDisplay {
public:
	virtual ~IMonitorDisplay(void);
	virtual void update(void) = 0;
};

#endif