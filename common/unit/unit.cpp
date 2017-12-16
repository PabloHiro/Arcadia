#include "unit.hpp"

#include <iostream>

void unit::touch_hp(const int hp_change)
{
    u_cur_hp += hp_change;
    
    if( u_cur_hp > static_cast<int>(u_max_hp.value()) )
    {
        u_cur_hp = u_max_hp.value();
    }
    
    if( u_cur_hp <= 0 )
    {
        u_cur_hp = 0;
        std::cerr << "Unit: " << u_name << " is dead" << std::endl;
    }
}

int unit::hp()
{
    return u_cur_hp;
}

void unit::print_info()
{
    std::cout << "Unit: " <<  u_name << std::endl;
    std::cout << "Position: ( " << u_position[X] << "," << u_position[Y] << " )" << std::endl;
    u_team.print_info();
}

void unit::print_stats()
{
    std::cout << "CURRENT HP: "     << this->hp()            << std::endl;
    std::cout << "MAX HP: "         << u_max_hp.value()       << std::endl;
    std::cout << "ATTACK: "         << u_attack.value()       << std::endl;
    std::cout << "DEFENSE: "        << u_defense.value()      << std::endl;
    std::cout << "LEVEL: "          << u_level.value()        << std::endl;
    std::cout << "ATTACK SPEED: "   << u_attack_speed.value() << std::endl;
    std::cout << "MOV_SPEED: "      << u_mov_speed.value()    << std::endl;
    std::cout << "VISION: "         << u_vision.value()       << std::endl;
}
