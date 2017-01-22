#include "SfmlDisplay.class.hpp"

SfmlDisplay::~SfmlDisplay(void) {
	this->_window->close();
}

SfmlDisplay &SfmlDisplay::operator=(const SfmlDisplay &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void SfmlDisplay::update(void) {
	while (this->_window->isOpen())
	{
		for (std::vector<IMonitorModule*>::iterator it = this->_modules.begin(); it != this->_modules.end(); ++it) {
			(*it)->displaySfml(this);
		}

		sf::Event event;
		while (this->_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				this->_window->close();
			}
		}
	}
}

SfmlDisplay::SfmlDisplay(std::vector<IMonitorModule*> modules) : _modules(modules){
	this->_window->create(sf::VideoMode(800, 600), "My monitor");
	this->update();
}


sf::RenderWindow * SfmlDisplay::getWindow(void) const {
	return this->_window;
}
