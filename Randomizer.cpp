#include "Randomizer.h"

std::string Randomizer::RandomPickAll() {
	int IPOS = rand() % list.LordList.size();
	return list.LordList.at(IPOS);
};

void Randomizer::searchByRace() {
	std::string Race;
	std::cout << "Select the Race you want to display: " << std::endl;
	std::getline(std::cin, Race);

	for (auto& i : list.TotalFactions.at(Race)) std::cout << i << std::endl;
};

std::string Randomizer::RandomBySelectedRace(std::string Race) {
	//std::cout << "Select the Race you want a randomly picked faction for:" << std::endl;
	//std::getline(std::cin, Race);
	int RFactions = list.TotalFactions.at(Race).size();
	int IPOS = rand() % RFactions;
	return list.TotalFactions.at(Race)[IPOS];
};