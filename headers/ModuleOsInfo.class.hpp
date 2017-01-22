#ifndef MODULE_OS_INFO_HPP
# define MODULE_OS_INFO_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <sys/sysctl.h>

class ModuleOsInfo : public IMonitorModule {
public:
    ModuleOsInfo(void);
    ModuleOsInfo(ModuleOsInfo const & src);

    virtual ~ModuleOsInfo(void);

    ModuleOsInfo & operator=(ModuleOsInfo const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml) const;
	virtual void displayNcurse(NcursesDisplay * nc) const;
	virtual std::string getModuleName(void) const;

private:
	char _osRelease[256];
	char _osType[256];
};

#endif