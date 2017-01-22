#include "ModuleName.class.hpp"

ModuleName::ModuleName(void) {

}

ModuleName::ModuleName(ModuleName const &src) {
	*this = src;
}

ModuleName::~ModuleName(void) {

}

ModuleName &ModuleName::operator=(ModuleName const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

int ModuleName::getHeight(void) const {
	return 0;
}

int ModuleName::getWidth(void) const {
	return 0;
}

void ModuleName::displaySfml(SfmlDisplay * sfml) const {
	sf::Text text;


// choix de la chaîne de caractères à afficher
	text.setString("Hello world");

// choix de la taille des caractères
	text.setCharacterSize(24); // exprimée en pixels, pas en points !

// choix de la couleur du texte
	text.setFillColor(sf::Color::Red);

// choix du style du texte
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
// puis, dans la boucle de dessin, entre window.clear() et window.display()

	sf::RenderWindow *w = sfml->getWindow();
	w->draw(text);
}

void ModuleName::displayNcurse(void) const {

}
