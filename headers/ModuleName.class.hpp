#ifndef MODULE_NAME_HPP
# define MODULE_NAME_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"
#include <unistd.h>

class ModuleName : public IMonitorModule {
public:
    ModuleName(void);
    ModuleName(ModuleName const & src);

    virtual ~ModuleName(void);

    ModuleName & operator=(ModuleName const & rhs);

	virtual void displaySfml(SfmlDisplay * sfml) const;
	virtual void displayNcurse(void) const;
	virtual std::string getModuleName(void) const;
};

#endif