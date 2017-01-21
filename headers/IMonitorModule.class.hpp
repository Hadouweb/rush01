#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

class IMonitorModule {
public:
	virtual int getHeight(void) const = 0;
	virtual int getWidth(void) const = 0;
};

#endif