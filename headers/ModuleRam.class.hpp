#ifndef MODULE_RAM_HPP
# define MODULE_RAM_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <ncurses.h>

class ModuleRam : public IMonitorModule {
public:
    ModuleRam(void);
    ModuleRam(ModuleRam const & src);

    virtual ~ModuleRam(void);

    ModuleRam & operator=(ModuleRam const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml);
	virtual void displayNcurse(NcursesDisplay * nc);
	virtual std::string getModuleRam(void) const;

private:

};

#endif