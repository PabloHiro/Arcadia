#ifndef _TEAM_HPP_
#define _TEAM_HPP_

#include <string>

using namespace std;

class team
{
	private:

	const unsigned t_color;
	const string t_name;

	public:

	team(const unsigned color, const string name)
		: t_color (color) , t_name (name)
	{};

	string getTeamName();
};

#endif //_TEAM_HPP_
