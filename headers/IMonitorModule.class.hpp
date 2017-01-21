#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

class IMonitorModule {
public:
	int getHeight(void) const = 0;
	int getWidth(void) const = 0;
};

#endif