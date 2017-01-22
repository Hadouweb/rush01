#ifndef MODULE_NAME_HPP
# define MODULE_NAME_HPP

#include "IMonitorModule.class.hpp"
#include "SfmlDisplay.class.hpp"

class ModuleName : public IMonitorModule {
public:
    ModuleName(void);
    ModuleName(ModuleName const & src);

    virtual ~ModuleName(void);

    ModuleName & operator=(ModuleName const & rhs);

	int getHeight(void) const;
	int getWidth(void) const;

	virtual void displaySfml(SfmlDisplay * sfml) const;
	virtual void displayNcurse(void) const;
};

#endif