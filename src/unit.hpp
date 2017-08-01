#ifndef _UNIT_HPP_
#define _UNIT_HPP_

#include <string>
#include <array>

#include "defines.h"
#include "stat.hpp"
#include "team.hpp"



class unit
{
public:

    virtual ~unit() {};

    void touch_hp( const int hp_change );
    int hp();

    void print_info();
    void print_stats();

protected:

    unit
    (
        const           std::string name, 
        const           std::array<int, 2> position, 
        const           team the_team, 
        const unsigned  max_hp, 
        const unsigned  attack,
        const unsigned  defense, 
        const unsigned  level, 
        const unsigned  a_speed,
        const unsigned  mov_speed, 
        const unsigned  vision
    ) :
        u_name          (name),
        u_position      (position),
        u_team          (the_team),
        u_max_hp        (max_hp),
        u_attack        (attack),
        u_defense       (defense),
        u_level         (level),
        u_attack_speed  (a_speed),
        u_mov_speed     (mov_speed),
        u_vision        (vision)
    {
        u_cur_hp = u_max_hp.value();
    };

    const std::string u_name;
    std::array<int, 2>  u_position;
    team u_team;

    stat u_max_hp;
    stat u_attack;
    stat u_defense;
    stat u_level;
    stat u_attack_speed;
    stat u_mov_speed;
    stat u_vision;

    int u_cur_hp;

};

#endif // _UNIT_HPP_
