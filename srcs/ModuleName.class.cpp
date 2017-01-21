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
