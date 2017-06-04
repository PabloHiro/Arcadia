#include "stat.hpp"



unsigned stat::getStat ()
{
	unsigned current_value = base_value;

	for ( auto it = modifiers.begin(); it != modifiers.end(); ++it )
	{
		current_value += it->second;
	}

	return current_value;

}

void stat::buffStat ( std::pair< std::string, unsigned > new_buff )
{
	modifiers.insert( new_buff );
}

void stat::debuffStat ( std::pair< std::string, unsigned > buff_2_remove )
{
	auto it = modifiers.find( buff_2_remove.first );

	if ( it != modifiers.end() )
	{
		modifiers.erase(buff_2_remove.first);
	}
}
