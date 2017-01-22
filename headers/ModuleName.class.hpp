#ifndef MODULE_NAME_HPP
# define MODULE_NAME_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include "NcursesDisplay.class.hpp"
#include <unistd.h>
#include <ncurses.h>

class ModuleName : public IMonitorModule {
public:
    ModuleName(void);
    ModuleName(ModuleName const & src);

    virtual ~ModuleName(void);

    ModuleName & operator=(ModuleName const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml) const;
	virtual void displayNcurse(NcursesDisplay * nc) const;
	virtual std::string getModuleName(void) const;

private:
	char _hostName[256];
	char _userName[256];
};

#endif