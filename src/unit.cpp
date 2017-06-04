#include "unit.hpp"

#include <iostream>
	
using namespace std;


void unit::printInfo()
{
	cout << "Unit: " <<  u_name << endl;
}

void unit::printStats()
{
	cout << "HP: " << u_hp.getStat() << endl;
	cout << "ATTACK: " << u_attack.getStat() << endl;
	cout << "DEFENSE: " << u_defense.getStat() << endl;
	cout << "LEVEL: " << u_level.getStat() << endl;
	cout << "ATTACK SPEED: " << u_attack_speed.getStat() << endl;
	cout << "MOV_SPEED: " << u_mov_speed.getStat() << endl;
	cout << "VISION: " << u_vision.getStat() << endl;
}
