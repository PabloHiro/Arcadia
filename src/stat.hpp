#ifndef _STAT_HPP_
#define _STAT_HPP_

#include <list>
#include <string>
#include "buff.hpp"

class stat
{
public:

    stat 
    (
        const unsigned b_v
    ): 
        base_value  (b_v),
        curr_value       (b_v)
    {};

    ~stat () {};

    unsigned value () { return curr_value; }
    void buff_stat ( buff* new_buff );
    void debuff_stat ( buff* old_buff );

private:

    const unsigned base_value;
    unsigned curr_value;
    std::list <buff*> modifiers;

};

#endif // _STAT_HPP_
