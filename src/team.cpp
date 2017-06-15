#include "team.hpp"

#include <string>
#include <iostream>
#include <type_traits>


std::ostream& operator << (std::ostream& os, const team::color& _color)
{
	std::string color_name;
	switch(_color)
	{
	   case team::color::blue: color_name = "blue"; break;
	   case team::color::red: color_name = "red"; break;
	   case team::color::green: color_name = "green"; break;
	   case team::color::yellow: color_name = "yellow"; break;
	   case team::color::cyan: color_name = "cyan"; break;
	   case team::color::orange: color_name = "orange"; break;
	   case team::color::purple: color_name = "purple"; break;
	   case team::color::black: color_name = "black"; break;
	   case team::color::gray: color_name = "gray"; break;
	   default: break;
	}
	os << color_name;
	return os;
}

std::string team::getTeamName()
{
	return t_name;
}

void team::printInfo()
{
	std::cout << "Team name: " << t_name << std::endl;
	std::cout << "Color: " << t_color << std::endl;
}

