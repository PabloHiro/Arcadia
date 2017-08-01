#ifndef _TEAM_HPP_
#define _TEAM_HPP_


#include <string>


class team
{

public:

    enum class color { blue, red, green, yellow, cyan, orange, purple, black, gray };
    
    team
    (
        const color the_color, 
        const std::string the_name
    ) : 
        t_color (the_color),
        t_name (the_name)
    {};
    
    ~team()
    {};

    std::string name();
    void print_info();
    
private:
    const color t_color;
    const std::string t_name;
    
};

#endif //_TEAM_HPP_
