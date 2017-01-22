#include "ModuleRam.class.hpp"

ModuleRam::ModuleRam(void) {

}

ModuleRam::ModuleRam(ModuleRam const &src) {
	*this = src;
}

ModuleRam::~ModuleRam(void) {

}

ModuleRam &ModuleRam::operator=(ModuleRam const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void ModuleRam::displaySfml(SfmlDisplay * sfml) const {
	if (sfml)
		;
}

void ModuleRam::displayNcurse(NcursesDisplay * nc) const {
	if (nc)
		;
}

std::string ModuleRam::getModuleRam(void) const {
	return "RAM";
}
