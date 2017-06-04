#include "unit.hpp"

#include <iostream>

using namespace std;


void unit::printInfo()
{
	std::cout << "Unit: " <<  u_name << std::endl;
	std::cout << "Position: ( " << u_position[X] << "," << u_position[Y] << " )" << std::endl;
}

void unit::printStats()
{
	std::cout << "HP: " << u_hp.getStat() << std::endl;
	std::cout << "ATTACK: " << u_attack.getStat() << std::endl;
	std::cout << "DEFENSE: " << u_defense.getStat() << std::endl;
	std::cout << "LEVEL: " << u_level.getStat() << std::endl;
	std::cout << "ATTACK SPEED: " << u_attack_speed.getStat() << std::endl;
	std::cout << "MOV_SPEED: " << u_mov_speed.getStat() << std::endl;
	std::cout << "VISION: " << u_vision.getStat() << std::endl;
}
