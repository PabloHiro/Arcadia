#ifndef _TEAM_HPP_
#define _TEAM_HPP_


#include <string>


class team
{	
	public:

	enum class color { blue, red, green, yellow, cyan, orange, purple, black, gray };
	
	team(const color _color, const std::string name)
		: t_color (_color) , t_name (name)
	{};
	
	~team()
	{};

	std::string getTeamName();
	void printInfo();
	
	private:
	const color t_color;
	const std::string t_name;
	
};

#endif //_TEAM_HPP_
