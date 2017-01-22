#ifndef MODULE_OS_INFO_HPP
# define MODULE_OS_INFO_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include <sys/sysctl.h>

class ModuleOsInfo : public IMonitorModule {
public:
    ModuleOsInfo(void);
    ModuleOsInfo(ModuleOsInfo const & src);

    virtual ~ModuleOsInfo(void);

    ModuleOsInfo & operator=(ModuleOsInfo const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml) const;
	virtual void displayNcurse(void) const;
	virtual std::string getModuleName(void) const;
};

#endif