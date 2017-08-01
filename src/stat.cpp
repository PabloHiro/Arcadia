#include "stat.hpp"

void stat::buff ( buff* new_buff )
{
    for ( auto& existing_buff : modifiers )
    {
        if( existing_buff->name == new_buff->name )
        {
            modifiers.erase(existing_buff);
            delete existing_buff;
            break;
        }
    }
    modifiers.insert( new_buff );
}

void stat::debuff ( buff* old_buff )
{
    for ( auto& existing_buff : modifiers )
    {
        if( existing_buff->name == old_buff->name )
        {
            modifiers.erase(existing_buff);
            delete existing_buff;
            return;
        }
    }
}
