#include <src/bear.hpp>
#include <src/team.hpp>

#include <iostream>

int main()
{
    bear *mybear;
    team neutral_team(team::color::gray, "Neutral");
    mybear = new bear({2,2}, neutral_team);
    mybear->print_info();
    mybear->print_stats();
    std::cout << "Now we are making a teamed bear: " << std::endl;
    delete mybear;
    team my_team(team::color::blue, "MyTeam");
    mybear = new bear({3,3}, my_team);
    mybear->print_stats();
    mybear->print_stats();
    delete mybear;
    return 0;
}
