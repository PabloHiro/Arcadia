#ifndef _TEAM_HPP_
#define _TEAM_HPP_

#include "unit.hpp"

#include <string>
#include <vector>


class team
{	
	public:

	enum class color { blue, red, green, yellow, cyan, orange, purple, black, gray };
	
	team(const color _color, const std::string name)
		: t_color (_color) , t_name (name)
	{};
	
	~team();

	std::string getTeamName();
	void printInfo();
	void addUnit(unit* new_unit);
	void removeUnit(unit* unit2remove);
	
	private:
	std::vector<unit*> t_units;
	const color t_color;
	const std::string t_name;
	
};

#endif //_TEAM_HPP_
