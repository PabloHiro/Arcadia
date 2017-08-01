#include "stat.hpp"

void stat::buff_stat ( buff* new_buff )
{
    for ( auto existing_buff = modifiers.begin(); existing_buff!=modifiers.end(); existing_buff++ )
    {
        if( (*existing_buff)->name() == new_buff->name() )
        {
            modifiers.erase(existing_buff);
            delete *existing_buff;
            break;
        }
    }
    modifiers.push_back( new_buff );
}

void stat::debuff_stat ( buff* old_buff )
{
    for ( auto existing_buff = modifiers.begin(); existing_buff!=modifiers.end(); existing_buff++ )
    {
        if( (*existing_buff)->name() == old_buff->name() )
        {
            modifiers.erase(existing_buff);
            delete *existing_buff;
            return;
        }
    }
}
