#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Warhammer Lists.h"
#include "Medieval Lists.h"
#include "Shogun Lists.h"
#include "Rome Lists.h"

class Randomizer {
public:
	LegendaryLords Warhammerlist;

	MedievalLists MedievalList;

	ShogunLists ShogunList;

	RomeLists RomeList;

	std::string RandomBySelectedCampaign(std::unordered_map<std::string, std::vector<std::string>> List, std::string Campaign);

	std::vector<std::string> Reinclude(std::vector<std::string>& source, std::vector<std::string>& DestV);

	bool VortexorMortal(std::string tester);

	bool VortexorMortalRaces(std::string tester);

	std::vector<std::string> ExcludeRandAll(std::vector<std::string> &source, std::vector<std::string> &DestV);

	std::vector<std::string> ExcludeRandByRace(std::vector<std::string>& source, std::vector<std::string> &DestV);

	std::string GetPictureFilepath(std::string CamporRace, std::string Faction, std::vector<std::string> FilePaths);

	std::string GetPictureFilepath(std::string Faction, std::vector<std::string> FilePaths);

	std::vector<std::string> RandomAll(std::unordered_map<std::string, std::vector<std::string>> List);
private:
	std::vector<std::string> PriorTwoResults = {};
};