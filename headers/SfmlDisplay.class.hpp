#ifndef SFML_DISPLAY_HPP
# define SFML_DISPLAY_HPP

#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.class.hpp"

class IMonitorModule;

class SfmlDisplay : public IMonitorDisplay {
public:
	SfmlDisplay(std::vector<IMonitorModule*> modules);

    virtual ~SfmlDisplay(void);

	void update(void);

	SfmlDisplay & operator=(SfmlDisplay const & rhs);

	sf::RenderWindow & getWindow(void);

private:
	std::vector<IMonitorModule*> _modules;
	sf::RenderWindow _window;
	SfmlDisplay(void);
	SfmlDisplay(SfmlDisplay const & src);
};

#endif