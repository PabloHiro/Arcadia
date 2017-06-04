#include "team.hpp"

#include <string>
#include <iostream>
#include <type_traits>

team::~team()
{
	for(auto it = t_units.begin(); it != t_units.end(); it++)
	{
		delete *it;
	}
}

std::ostream& operator << (std::ostream& os, const team::color& _color)
{
   os << static_cast<std::underlying_type<team::color>::type>(_color);
   return os;
}

std::string team::getTeamName()
{
	return t_name;
}

void team::printInfo()
{
	std::cout << "Name: " << t_name << std::endl;
	std::cout << "Color: " << t_name << std::endl;
	std::cout << "Units: " << t_units.size() << std::endl;
}

void team::addUnit(unit* new_unit)
{
	t_units.push_back(new_unit);
}

void team::removeUnit(unit* unit2remove)
{
	for(auto it = t_units.begin(); it != t_units.end(); it++)
	{
		if(*it == unit2remove){
			t_units.erase(it);
			delete unit2remove;
			break;
		}
	}
}
