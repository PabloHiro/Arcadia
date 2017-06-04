#ifndef _BEAR_HPP_
#define _BEAR_HPP_

#include "unit.hpp"

#include <array>

class bear : public unit
{
	public:
	bear(std::array<int,2> position) : unit
		("Bear", 
		position,
		80u, 8u, 0u, 1u, 1u,
		3u, 15u)
		/*
		u_name("Bear"),
		u_position(position)
		u_hp(80u),
		u_attack(8u),
		u_defense(0u),
		u_level(1u),
		u_attack_speed(1u),

		u_mov_speed(3u),
		u_vision(15u)
		*/
	{};
	
	~bear()
	{};

};

#endif //_BEAR_HPP_
