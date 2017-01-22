#ifndef MODULE_RAM_HPP
# define MODULE_RAM_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <ncurses.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <cmath>
#include <iomanip>
#include <sstream>

class ModuleRam : public IMonitorModule {
public:
    ModuleRam(void);
    ModuleRam(ModuleRam const & src);

    virtual ~ModuleRam(void);

    ModuleRam & operator=(ModuleRam const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml);
	virtual void displayNcurse(NcursesDisplay * nc);
	virtual std::string getModuleName(void) const;

	long long getFreedMemory(void) const;
	long long getUsedMemory(void) const;
	long long getTotalMemory(void) const;
	long long getCachedFiles(void) const;

	std::string convertMemory(long long bytes);

private:
	long long _usedMemory;
	long long _freedMemory;
	long long _cachedFiles;
};

#endif