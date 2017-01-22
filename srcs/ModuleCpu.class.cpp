#include "ModuleCpu.class.hpp"

ModuleCpu::ModuleCpu(void) {

}

ModuleCpu::ModuleCpu(ModuleCpu const &src) {
	*this = src;
}

ModuleCpu::~ModuleCpu(void) {

}

ModuleCpu &ModuleCpu::operator=(ModuleCpu const &rhs) {
	if (this != &rhs) {

	}
	return *this;
}

void ModuleCpu::displaySfml(SfmlDisplay * sfml) const {
	if (sfml)
		;
}

void ModuleCpu::displayNcurse(NcursesDisplay * nc) const {
	if (nc)
		;
}

std::string ModuleCpu::getModuleCpu(void) const {
	return "CPU";
}
