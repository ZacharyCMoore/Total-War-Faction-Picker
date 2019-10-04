#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Lists.h"

class Randomizer {
public:
	std::string RandomPickAll();

	void searchByRace();

	std::string RandomBySelectedRace(std::string Race);

private:
	LegendaryLords list;
};