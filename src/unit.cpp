#include "unit.hpp"

#include <iostream>

void unit::touchHp(int Hp)
{
	u_cur_hp += Hp;
	if( u_cur_hp > u_max_hp.getStat() ) u_cur_hp = u_max_hp.getStat();
	if( u_cur_hp <= 0 )
	{
		u_cur_hp = 0;
		std::cout << "Unit: " << u_name << " is dead" << std::endl;
	}
}

int unit::getHp()
{
	return u_cur_hp;
}

void unit::printInfo()
{
	std::cout << "Unit: " <<  u_name << std::endl;
	std::cout << "Position: ( " << u_position[X] << "," << u_position[Y] << " )" << std::endl;
}

void unit::printStats()
{
	std::cout << "MAX HP: " << u_max_hp.getStat() << std::endl;
	std::cout << "ATTACK: " << u_attack.getStat() << std::endl;
	std::cout << "DEFENSE: " << u_defense.getStat() << std::endl;
	std::cout << "LEVEL: " << u_level.getStat() << std::endl;
	std::cout << "ATTACK SPEED: " << u_attack_speed.getStat() << std::endl;
	std::cout << "MOV_SPEED: " << u_mov_speed.getStat() << std::endl;
	std::cout << "VISION: " << u_vision.getStat() << std::endl;
}
