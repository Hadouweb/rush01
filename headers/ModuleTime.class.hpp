#ifndef MODULE_TIME_HPP
# define MODULE_TIME_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <ncurses.h>
#include <ctime>

class ModuleTime : public IMonitorModule {
public:
    ModuleTime(void);
    ModuleTime(ModuleTime const & src);

    virtual ~ModuleTime(void);

    ModuleTime & operator=(ModuleTime const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml);
	virtual void displayNcurse(NcursesDisplay * nc);
	std::string getModuleName(void) const;
};

#endif