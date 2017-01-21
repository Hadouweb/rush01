#ifndef MONITOR_HPP
# define MONITOR_HPP

class Monitor {
public:
    Monitor(void);
    Monitor(Monitor const & src);

    virtual ~Monitor(void);

    Monitor & operator=(Monitor const & rhs);

};

#endif