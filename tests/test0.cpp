#include <src/bear.hpp>
#include <src/team.hpp>

#include <iostream>

int main()
{
	bear *mybear;
	mybear = new bear({2,2});
	team neutral(team::color::gray,"Neutral");
	mybear->printInfo();
	mybear->printStats();
	neutral.printInfo();
	std::cout << "Adding unit" << std::endl;
	neutral.addUnit(mybear);
	neutral.printInfo();
	return 0;
}
