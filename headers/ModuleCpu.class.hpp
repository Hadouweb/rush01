#ifndef MODULE_CPU_HPP
# define MODULE_CPU_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <ncurses.h>
#include <sys/sysctl.h>
#include <sstream>
#include <iomanip>
#include <mach/mach_host.h>
#include <mach/processor_info.h>


class ModuleCpu : public IMonitorModule {
public:
    ModuleCpu(void);
    ModuleCpu(ModuleCpu const & src);

    virtual ~ModuleCpu(void);

    ModuleCpu & operator=(ModuleCpu const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml);
	virtual void displayNcurse(NcursesDisplay * nc);
	virtual std::string getModuleName(void) const;
	std::string getModel(void) const;
	std::string getClockSpeed(void) const;
	int getNumberCore(void) const;
	float getCpuUsage(int idCore);
	void displaySfmlCpuUsage(SfmlDisplay * sfml);

private:
	struct Ticks {
		unsigned long long int usertime;
		unsigned long long int nicetime;
		unsigned long long int systemtime;
		unsigned long long int idletime;

		unsigned long long int used() { return usertime + nicetime + systemtime; }
		unsigned long long int total() { return usertime + nicetime + systemtime + idletime; }
	};
	Ticks _prevTicks[4];
	Ticks _currentTicks[4];
	std::string _percent[4];
	int _frameRate;
};

#endif