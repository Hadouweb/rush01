#ifndef MODULE_CPU_HPP
# define MODULE_CPU_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <ncurses.h>

class ModuleCpu : public IMonitorModule {
public:
    ModuleCpu(void);
    ModuleCpu(ModuleCpu const & src);

    virtual ~ModuleCpu(void);

    ModuleCpu & operator=(ModuleCpu const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml) const;
	virtual void displayNcurse(NcursesDisplay * nc) const;
	virtual std::string getModuleCpu(void) const;

private:

};

#endif