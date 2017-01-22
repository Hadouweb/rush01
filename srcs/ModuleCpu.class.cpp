#include "ModuleCpu.class.hpp"

ModuleCpu::ModuleCpu(void) {
	this->_frameRate = 100;
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

void ModuleCpu::displaySfml(SfmlDisplay * sfml) {
	int endLine = sfml->getModuleEndLine();

	std::string outPutModel = "Model: ";
	outPutModel += this->getModel();

	std::string outPutClockSpeed = "Clock speed: ";
	outPutClockSpeed += this->getClockSpeed();

	std::string outPutNbCore = "Number of cores: ";
	outPutNbCore += std::to_string(this->getNumberCore());

	sf::RectangleShape backgroundTitle(sf::Vector2f(120, 50));
	backgroundTitle.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 40));
	backgroundTitle.setPosition(0, endLine);
	backgroundTitle.setFillColor(sf::Color(52, 73, 94));

	sf::Text textModuleName(this->getModuleName(), sfml->getFont(), 50);
	endLine += 5;
	textModuleName.setPosition(sfml->getWindow().getSize().x / 2 - 100, endLine);
	textModuleName.setCharacterSize(24);
	textModuleName.setFillColor(sf::Color::White);

	endLine += 35;
	sf::RectangleShape background(sf::Vector2f(120, 50));
	background.setSize(sf::Vector2f(sfml->getWindow().getSize().x, 260));
	background.setPosition(0, endLine);
	background.setFillColor(sf::Color(44, 62, 80));

	sf::Text textModel(outPutModel, sfml->getFont(), 50);
	endLine += 15;
	textModel.setPosition(50, endLine);
	textModel.setCharacterSize(24);
	textModel.setFillColor(sf::Color::White);

	sf::Text textClockSpeed(outPutClockSpeed, sfml->getFont(), 50);
	endLine += 35;
	textClockSpeed.setPosition(50, endLine);
	textClockSpeed.setCharacterSize(24);
	textClockSpeed.setFillColor(sf::Color::White);

	sf::Text textClockNbCore(outPutNbCore, sfml->getFont(), 50);
	endLine += 35;
	textClockNbCore.setPosition(50, endLine);
	textClockNbCore.setCharacterSize(24);
	textClockNbCore.setFillColor(sf::Color::White);

	sfml->getWindow().draw(background);
	sfml->getWindow().draw(backgroundTitle);
	sfml->getWindow().draw(textModuleName);
	sfml->getWindow().draw(textModel);
	sfml->getWindow().draw(textClockSpeed);
	sfml->getWindow().draw(textClockNbCore);

	sfml->setModuleEndLine(endLine);
	this->displaySfmlCpuUsage(sfml);

	endLine = sfml->getModuleEndLine();
	endLine += 35;
	sfml->setModuleEndLine(endLine);
}

void ModuleCpu::displayNcurse(NcursesDisplay * nc) {
	int endLine = nc->getModuleEndLine();

	endLine += 2;
	mvprintw(endLine++, 1, this->getModuleName().c_str());
	endLine += 1;
	std::string str = (std::string("Model : ") +(this->getModel()));
	std::string str1 = std::string("Clock speed : ") + (this->getClockSpeed());
	std::string str2 = std::string("Number of cores : ") + std::to_string(this->getNumberCore());
	mvprintw(endLine, 1 , str.c_str());
	endLine += 1;
	mvprintw(endLine, 1 , str1.c_str());
	endLine += 1;
	mvprintw(endLine, 1 , str2.c_str());
	endLine += 1;

	nc->setModuleEndLine(endLine);
	this->displayNcursesCpuUsage(nc);
	endLine = nc->getModuleEndLine();
	mvprintw(++endLine, 1,"___________________________");
	nc->setModuleEndLine(endLine);
}

std::string ModuleCpu::getModuleName(void) const {
	return "CPU";
}

std::string ModuleCpu::getModel(void) const {
	char str[1024];
	size_t len = 1024;
	sysctlbyname("machdep.cpu.brand_string", str, &len, NULL, 0);
	return std::string(str);
}

std::string ModuleCpu::getClockSpeed(void) const {
	size_t len = sizeof(double);
	double busFrequency;
	double cpuFrequency;
	double clockSpeed;

	sysctlbyname("hw.busfrequency", &busFrequency, &len, NULL, 0);
	sysctlbyname("hw.cpufrequency", &cpuFrequency, &len, NULL, 0);

	clockSpeed = cpuFrequency / busFrequency / 10.0f;

	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << clockSpeed;
	std::string ret = stream.str();

	return ret;
}


int ModuleCpu::getNumberCore(void) const {
	size_t len = sizeof(int);
	int nb;

	sysctlbyname("hw.ncpu", &nb, &len, NULL, 0);
	return nb;
}

float ModuleCpu::getCpuUsage(int idCore) {
	unsigned long long int usertime;
	unsigned long long int nicetime;
	unsigned long long int systemtime;
	unsigned long long int idletime;

	unsigned int cpu_count;
	processor_cpu_load_info_t cpu_load;
	mach_msg_type_number_t cpu_msg_count;

	int rc =  host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO,
			&cpu_count,
			(processor_info_array_t *) &cpu_load,
			&cpu_msg_count
	);

	if (rc)
		;

	usertime = cpu_load[idCore].cpu_ticks[CPU_STATE_USER];
	nicetime = cpu_load[idCore].cpu_ticks[CPU_STATE_NICE];
	systemtime = cpu_load[idCore].cpu_ticks[CPU_STATE_SYSTEM];
	idletime = cpu_load[idCore].cpu_ticks[CPU_STATE_IDLE];

	this->_currentTicks[idCore].usertime = usertime;
	this->_currentTicks[idCore].nicetime = nicetime;
	this->_currentTicks[idCore].systemtime = systemtime;
	this->_currentTicks[idCore].idletime = idletime;

	unsigned long long int used = this->_currentTicks[idCore].used() - this->_prevTicks[idCore].used();
	unsigned long long int total = this->_currentTicks[idCore].total() - this->_prevTicks[idCore].total();
	this->_prevTicks[idCore] = this->_currentTicks[idCore];

	float percent = static_cast<float>(used) / static_cast<float>(total) * 100.0f;
	return percent;
}

void ModuleCpu::displaySfmlCpuUsage(SfmlDisplay * sfml) {
	int endLine = sfml->getModuleEndLine();
	int nbCore = this->getNumberCore();

	for (int i = 0; i < nbCore; i++) {
		std::string outPutCpuUsage = "Core " + std::to_string(i + 1) + ": ";

		std::stringstream stream;
		stream << std::fixed << std::setprecision(1) << this->getCpuUsage(i);

		std::string ret;

		if (this->_frameRate >= 20) {
			ret = stream.str();
			this->_percent[i] = ret;
		} else {
			ret = this->_percent[i];
		}

		outPutCpuUsage += ret;

		sf::Text textCpuUsage(outPutCpuUsage, sfml->getFont(), 50);
		endLine += 35;
		textCpuUsage.setPosition(50, endLine);
		textCpuUsage.setCharacterSize(24);
		textCpuUsage.setFillColor(sf::Color::White);

		sfml->getWindow().draw(textCpuUsage);
	}
	sfml->setModuleEndLine(endLine);

	if (this->_frameRate >= 20)
		this->_frameRate = 0;
	this->_frameRate++;
}

void ModuleCpu::displayNcursesCpuUsage(NcursesDisplay * nc) {
	int endLine = nc->getModuleEndLine();
	int nbCore = this->getNumberCore();

	for (int i = 0; i < nbCore; i++) {
		std::string outPutCpuUsage = "Core " + std::to_string(i + 1) + ": ";

		std::stringstream stream;
		stream << std::fixed << std::setprecision(1) << this->getCpuUsage(i);

		std::string ret;

		if (this->_frameRate >= 10) {
			ret = stream.str();
			this->_percent[i] = ret;
		} else {
			ret = this->_percent[i];
		}

		outPutCpuUsage += ret;

		mvprintw(endLine, 1 , "                                ");
		mvprintw(endLine, 1 , outPutCpuUsage.c_str());
		endLine++;

	}
	nc->setModuleEndLine(endLine - 1);
	if (this->_frameRate >= 10)
		this->_frameRate = 0;
	this->_frameRate++;
}
