#ifndef _BEAR_HPP_
#define _BEAR_HPP_

#include "unit.hpp"

#include <array>

class bear : public unit
{
    
public:
    bear
    (
        const std::array<int,2> position, 
        const team the_team
    ) : 
    unit
    (
        "Bear",     // name
        position,   // position
        the_team,   // team
        80u,        // max_hp
        8u,         // attack
        0u,         // defense
        1u,         // level
        1u,         // attack_speed
        3u,         // mov_speed
        15u         // vision
    )
    {};

    ~bear()
    {};

};

#endif //_BEAR_HPP_
