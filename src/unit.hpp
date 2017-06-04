#ifndef _UNIT_HPP_
#define _UNIT_HPP_

#include <string>

#include "stat.hpp"
#include "team.hpp"

using namespace std;

class unit
{
	public:
	void printInfo();
	void printStats();

	protected:
	unit(const string name, const unsigned hp, const unsigned attack,
		const unsigned defense, const unsigned level, const unsigned a_speed,
		const unsigned mov_speed, const unsigned vision) :
		u_name(name),
		
		u_hp(hp),
		u_attack(attack),
		u_defense(defense),
		u_level(level),
		u_attack_speed(a_speed),

		u_mov_speed(mov_speed),
		u_vision(vision)
	{};
	
	virtual ~unit() {};
	
	const string u_name;

	stat u_hp;
	stat u_attack;
	stat u_defense;
	stat u_level;
	stat u_attack_speed;

	stat u_mov_speed;
	stat u_vision;

};

#endif // _UNIT_HPP_
