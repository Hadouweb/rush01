#include "SfmlDisplay.class.hpp"

SfmlDisplay::SfmlDisplay(void) {
	this->_window.create(sf::VideoMode(800, 600), "My monitor");
	this->update();
}

SfmlDisplay::SfmlDisplay(SfmlDisplay const &src) {
	*this = src;
}

SfmlDisplay::~SfmlDisplay(void) {

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
	}
}
