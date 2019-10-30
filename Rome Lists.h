#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class RomeLists {
public:
	std::unordered_map<std::string, std::vector<std::string>> RomeTotalList = {
		{
		"Vanilla", {
		"Carthage",
		"Britannia",
		"Gaul",
		"Germania",
		"Parthia",
		"Egypt",
		"Greek Cities",
		"Seleucid Empire",
		"House of Brutii",
		"House of Julii",
		"House of Scipii"
			}
		}
	};

	std::vector<std::string> Campaign = {
		"Vanilla"
	};

	std::vector<std::string> RomeFilePaths = {
		"Rome Faction Pictures\\Vanilla\\Britannia.png",
		"Rome Faction Pictures\\Vanilla\\Carthage.png",
		"Rome Faction Pictures\\Vanilla\\Egypt.png",
		"Rome Faction Pictures\\Vanilla\\Gaul.png",
		"Rome Faction Pictures\\Vanilla\\Germania.png",
		"Rome Faction Pictures\\Vanilla\\Greek Cities.png",
		"Rome Faction Pictures\\Vanilla\\House of Brutii.png",
		"Rome Faction Pictures\\Vanilla\\House of Julii.png",
		"Rome Faction Pictures\\Vanilla\\House of Scipii.png",
		"Rome Faction Pictures\\Vanilla\\Parthia.png",
		"Rome Faction Pictures\\Vanilla\\Seleucid Empire.png"
	};
};