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
			if (event.type == sf::Event::Closed)
				this->_window.close();
			if(event.type == sf::Event::Resized)
				this->_window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
		}

		this->_window.clear(sf::Color::Black);
		this->setModuleEndLine(0);
		for (std::vector<IMonitorModule*>::iterator it = this->_modules.begin(); it != this->_modules.end(); ++it) {
			(*it)->displaySfml(this);
		}
		this->_window.display();
	}
}

SfmlDisplay::SfmlDisplay(std::vector<IMonitorModule*> modules) : _modules(modules) {
	this->_window.create(sf::VideoMode(650, 935), "My monitor");
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

int SfmlDisplay::getModuleEndLine() const {
	return this->_y;
}

void SfmlDisplay::setModuleEndLine(int y) {
	if (y >= 0 && y < static_cast<int>(this->_window.getSize().y))
		this->_y = y;
}
