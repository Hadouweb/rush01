#ifndef NCURSES_DISPLAY_HPP
# define NCURSES_DISPLAY_HPP

#include <ncurses.h>
#include "IMonitorDisplay.class.hpp"
#include <unistd.h>

class IMonitorModule;

class NcursesDisplay : public IMonitorDisplay {
public:
	NcursesDisplay(std::vector<IMonitorModule*> modules);

	virtual ~NcursesDisplay(void);

	void update(void);

	NcursesDisplay & operator=(NcursesDisplay const & rhs);

	virtual int getModuleEndLine() const;
	virtual void setModuleEndLine(int y);

private:
	std::vector<IMonitorModule*> _modules;
	int _y;
	int _winH;
	int _winW;
	NcursesDisplay(void);
	NcursesDisplay(NcursesDisplay const & src);
};

#endif