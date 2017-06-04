#ifndef _UNIT_HPP_
#define _UNIT_HPP_

#include <string>
#include <array>

#include "stat.hpp"

#define X 0
#define Y 1


class unit
{
	public:

	virtual ~unit() {};

	void printInfo();
	void printStats();

	protected:

	unit(const std::string name, std::array<int, 2> position, const unsigned hp, const unsigned attack,
		const unsigned defense, const unsigned level, const unsigned a_speed,
		const unsigned mov_speed, const unsigned vision) :
		u_name(name),

		u_position(position),

		u_hp(hp),
		u_attack(attack),
		u_defense(defense),
		u_level(level),
		u_attack_speed(a_speed),

		u_mov_speed(mov_speed),
		u_vision(vision)
	{};

	const std::string u_name;

	std::array<int, 2> u_position;

	stat u_hp;
	stat u_attack;
	stat u_defense;
	stat u_level;
	stat u_attack_speed;

	stat u_mov_speed;
	stat u_vision;



};

#endif // _UNIT_HPP_
