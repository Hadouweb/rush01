#ifndef SFML_DISPLAY_HPP
# define SFML_DISPLAY_HPP

#include "IMonitorDisplay.class.hpp"
#include <SFML/Window.hpp>
#include <iostream>

class SfmlDisplay : public IMonitorDisplay {
public:
    SfmlDisplay(void);
    SfmlDisplay(SfmlDisplay const & src);

    virtual ~SfmlDisplay(void);

	void update(void);

	SfmlDisplay & operator=(SfmlDisplay const & rhs);

private:
	sf::Window _window;
};

#endif