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

	void touchHp(int Hp);
	int getHp();

	void printInfo();
	void printStats();

	protected:

	unit(const std::string name, std::array<int, 2> position, const unsigned max_hp, const unsigned attack,
		const unsigned defense, const unsigned level, const unsigned a_speed,
		const unsigned mov_speed, const unsigned vision) :
		u_name(name),

		u_position(position),

		u_max_hp(max_hp),
		u_attack(attack),
		u_defense(defense),
		u_level(level),
		u_attack_speed(a_speed),

		u_mov_speed(mov_speed),
		u_vision(vision)
	{
		u_cur_hp = u_max_hp.getStat();
	};

	const std::string u_name;

	std::array<int, 2> u_position;

	int u_cur_hp;

	stat u_max_hp;
	stat u_attack;
	stat u_defense;
	stat u_level;
	stat u_attack_speed;

	stat u_mov_speed;
	stat u_vision;



};

#endif // _UNIT_HPP_
