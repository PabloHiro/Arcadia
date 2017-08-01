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
        value       (b_v)
    {};

    ~stat () {};

    unsigned value () { return value; }
    void buff ( buff* new_buff );
    void debuff ( buff* old_buff );

private:

    const unsigned base_value;
    unsigned value;
    std::list <buff*> modifiers;

};

#endif // _STAT_HPP_
