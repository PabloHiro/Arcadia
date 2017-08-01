#ifndef _BUFF_HPP_
#define _BUFF_HPP_

#include <string>

class buff
{
    public:
    
    buff
    (
        const unsigned modifier,
        const float factor,
        const float duration,
        const string name
    ) :
        b_modifier  (modifier)
        b_factor    (factor)
        b_duration  (duration)
        b_name      (name)
    {};
    
    ~buff() {};
    
    unsigned modifier() { return b_modifier;    }
    float factor()      { return b_factor;      }
    float duration()    { return b_duration;    }
    std::string name()  { return b_name;        }
    
    
    private:
    const unsigned b_modifier;
    const float b_factor;
    const float b_duration;
    const std::string b_name;
};


#endif // _BUFF_HPP_