#ifndef _STAT_HPP_
#define _STAT_HPP_

#include <unordered_map>
#include <string>

class stat 
{
	
public:
	
	stat (const unsigned b_v)
		: base_value (b_v)
	{
	}
	
	~stat () { }
	
	unsigned getStat ();
	void buff ( std::pair< std::string, unsigned > new_buff );
	void debuff ( std::pair< std::string, unsigned > buff_2_remove );
	
private:

	const unsigned base_value;
	std::unordered_map <std::string, unsigned> modifiers;
	
};

#endif // _STAT_HPP_