#include "team.hpp"

#include <string>
#include <iostream>


std::ostream& operator << (std::ostream& os, const team::color& the_color)
{
    std::string color_name;
    switch(the_color)
    {
       case team::color::blue:      color_name = "blue"; break;
       case team::color::red:       color_name = "red"; break;
       case team::color::green:     color_name = "green"; break;
       case team::color::yellow:    color_name = "yellow"; break;
       case team::color::cyan:      color_name = "cyan"; break;
       case team::color::orange:    color_name = "orange"; break;
       case team::color::purple:    color_name = "purple"; break;
       case team::color::black:     color_name = "black"; break;
       case team::color::gray:      color_name = "gray"; break;
       default:                     color_name = "color not assigned"; break;
    }
    os << color_name;
    return os;
}

std::string team::name()
{
    return t_name;
}

void team::print_info()
{
    std::cout << "Team name: " << t_name << std::endl;
    std::cout << "Color: " << t_color << std::endl;
}

