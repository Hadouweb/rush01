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
	sf::Font & getFont(void);

	virtual int getModuleEndLine() const;
	virtual void setModuleEndLine(int y);

private:
	std::vector<IMonitorModule*> _modules;
	sf::RenderWindow _window;
	sf::Font _font;
	int _y;
	SfmlDisplay(void);
	SfmlDisplay(SfmlDisplay const & src);
};

#endif