#ifndef SFML_DISPLAY_HPP
# define SFML_DISPLAY_HPP

#include "IMonitorDisplay.class.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>


class SfmlDisplay : public IMonitorDisplay {
public:
	SfmlDisplay(std::vector<IMonitorModule*> modules);

    virtual ~SfmlDisplay(void);

	void update(void);

	SfmlDisplay & operator=(SfmlDisplay const & rhs);

	void displayModule(ModuleName * m);

private:
	std::vector<IMonitorModule*> _modules;
	sf::Window _window;
	SfmlDisplay(void);
	SfmlDisplay(SfmlDisplay const & src);
};

#endif