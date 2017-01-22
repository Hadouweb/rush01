#include "ModuleTime.class.hpp"

ModuleTime::ModuleTime(void) {

}

ModuleTime::ModuleTime(ModuleTime const &src) {
	*this = src;
}

ModuleTime::~ModuleTime(void) {

}

ModuleTime &ModuleTime::operator=(ModuleTime const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void ModuleTime::displaySfml(SfmlDisplay * sfml) const {
	if (sfml)
		;
}

void ModuleTime::displayNcurse(NcursesDisplay * nc) const {
	if (nc)
		;
}

std::string ModuleTime::getModuleTime(void) const {
	return "Time";
}
