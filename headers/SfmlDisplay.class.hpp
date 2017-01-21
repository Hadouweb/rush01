#ifndef SFML_DISPLAY_HPP
# define SFML_DISPLAY_HPP

#include "IMonitorDisplay.class.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>


class SfmlDisplay : public IMonitorDisplay {
public:
    SfmlDisplay(void);
    SfmlDisplay(SfmlDisplay const & src);

    virtual ~SfmlDisplay(void);

	void update(void);

	std::string getHostName(void) const;
	std::string getUserName(void) const;

	SfmlDisplay & operator=(SfmlDisplay const & rhs);

private:
	sf::Window _window;
	std::string _hostName;
	std::string _userName;
};

#endif