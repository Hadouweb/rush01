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

void ModuleRam::displaySfml(SfmlDisplay * sfml) {

	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
		(host_info64_t)&vm_stats, &count))
	{
		this->_freedMemory = (int64_t)vm_stats.free_count * (int64_t)page_size;
		this->_usedMemory = ((int64_t)vm_stats.active_count + (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
		this->_cachedFiles = (int64_t)vm_stats.inactive_count * (int64_t)page_size ;

	}

	int endLine = sfml->getModuleEndLine();

	std::string outPutTotalMemory = "Total memory:      ";
	outPutTotalMemory += std::to_string(this->getTotalMemory());

	std::string outPutUsedMemory = "Used memory:      ";
	outPutUsedMemory += std::to_string(this->getUsedMemory());

	std::string outPutFreedMemory = "Freed memory:     ";
	outPutFreedMemory += std::to_string(this->getFreedMemory());

	std::string outPutCachedMemory = "Cached memory: ";
	outPutCachedMemory += std::to_string(this->getCachedFiles());

	sf::RectangleShape backgroundTitle(sf::Vector2f(120, 50));
	backgroundTitle.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 40));
	backgroundTitle.setPosition(0, endLine);
	backgroundTitle.setFillColor(sf::Color(52, 152, 219));

	sf::Text textModuleName(this->getModuleName(), sfml->getFont(), 50);
	endLine += 5;
	textModuleName.setPosition(sfml->getWindow().getSize().x / 2 - 100, endLine);
	textModuleName.setCharacterSize(24);
	textModuleName.setFillColor(sf::Color::White);

	endLine += 35;
	sf::RectangleShape background(sf::Vector2f(120, 50));
	background.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 160));
	background.setPosition(0, endLine);
	background.setFillColor(sf::Color(41, 128, 185));

	sf::Text textTotalMemory(outPutTotalMemory, sfml->getFont(), 50);
	endLine += 15;
	textTotalMemory.setPosition(50, endLine);
	textTotalMemory.setCharacterSize(24);
	textTotalMemory.setFillColor(sf::Color::White);

	sf::Text textUsedMemory(outPutUsedMemory, sfml->getFont(), 50);
	endLine += 35;
	textUsedMemory.setPosition(50, endLine);
	textUsedMemory.setCharacterSize(24);
	textUsedMemory.setFillColor(sf::Color::White);

	sf::Text textFreedMemory(outPutFreedMemory, sfml->getFont(), 50);
	endLine += 35;
	textFreedMemory.setPosition(50, endLine);
	textFreedMemory.setCharacterSize(24);
	textFreedMemory.setFillColor(sf::Color::White);

	sf::Text textCachedMemory(outPutCachedMemory, sfml->getFont(), 50);
	endLine += 35;
	textCachedMemory.setPosition(50, endLine);
	textCachedMemory.setCharacterSize(24);
	textCachedMemory.setFillColor(sf::Color::White);

	sfml->getWindow().draw(background);
	sfml->getWindow().draw(backgroundTitle);
	sfml->getWindow().draw(textModuleName);
	sfml->getWindow().draw(textTotalMemory);
	sfml->getWindow().draw(textUsedMemory);
	sfml->getWindow().draw(textFreedMemory);
	sfml->getWindow().draw(textCachedMemory);
	endLine += 40;
	sfml->setModuleEndLine(endLine);
}

void ModuleRam::displayNcurse(NcursesDisplay * nc) {
	if (nc)
		;
}

std::string ModuleRam::getModuleName(void) const {
	return "RAM";
}

long long  ModuleRam::getFreedMemory() const {
	return (this->_freedMemory + this->_cachedFiles);
}

long long  ModuleRam::getUsedMemory() const {
	return (this->_usedMemory);
}

long long  ModuleRam::getTotalMemory() const {
	return (this->_usedMemory + this->_freedMemory + this->_cachedFiles);
}

long long ModuleRam::getCachedFiles() const {
	return (this->_cachedFiles);
}
