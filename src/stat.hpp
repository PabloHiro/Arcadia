#ifndef _STAT_HPP_
#define _STAT_HPP_

#include <unordered_map>
#include <string>

using namespace std;
class stat
{
	public:

	stat (const unsigned b_v)
		: base_value (b_v)
	{};

	~stat () {};

	unsigned getStat ();
	void buffStat ( pair< std::string, unsigned > new_buff );
	void debuffStat ( pair< std::string, unsigned > buff_2_remove );

	private:

	const unsigned base_value;
	unordered_map <string, unsigned> modifiers;

};

#endif // _STAT_HPP_
