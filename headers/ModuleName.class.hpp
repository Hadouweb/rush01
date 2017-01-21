#ifndef MODULE_NAME_HPP
# define MODULE_NAME_HPP

#include "IMonitorModule.class.hpp"

class ModuleName : IMonitorModule {
public:
    ModuleName(void);
    ModuleName(ModuleName const & src);

    virtual ~ModuleName(void);

    ModuleName & operator=(ModuleName const & rhs);
};

#endif