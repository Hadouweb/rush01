#include "SfmlDisplay.class.hpp"

SfmlDisplay::~SfmlDisplay(void) {
	this->_window.close();
}

SfmlDisplay &SfmlDisplay::operator=(const SfmlDisplay &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void SfmlDisplay::update(void) {
	while (this->_window.isOpen())
	{
		sf::Event event;
		while (this->_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				this->_window.close();
			}
		}

		this->_window.clear(sf::Color::Black);
		for (std::vector<IMonitorModule*>::iterator it = this->_modules.begin(); it != this->_modules.end(); ++it) {
			(*it)->displaySfml(this);
		}
		this->_window.display();
	}
}

SfmlDisplay::SfmlDisplay(std::vector<IMonitorModule*> modules) : _modules(modules){
	this->_window.create(sf::VideoMode(800, 600), "My monitor");
	this->_window.setFramerateLimit(30);
	if (!this->_font.loadFromFile("SFML/font/CaviarDreams.ttf")) {
		exit(EXIT_FAILURE);
	}
	this->update();

}


sf::RenderWindow & SfmlDisplay::getWindow(void) {
	return this->_window;
}

sf::Font &SfmlDisplay::getFont(void) {
	return this->_font;
}
