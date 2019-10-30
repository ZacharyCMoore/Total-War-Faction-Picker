#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class MedievalLists {
public:
	std::unordered_map<std::string, std::vector<std::string>> Medieval2TotalList = {
		{"Vanilla", {
		"The Byzantine Empire",
		"Denmark",
		"Egypt",
		"England",
		"France",
		"The Holy Roman Empire",
		"Hungary",
		"Milan",
		"Moors",
		"Portugal",
		"Russia",
		"Scotland",
		"Sicily",
		"Spain",
		"The Turks",
		"Venice"}},
		{"Americas", {
		"Apachean Tribes",
		"The Aztec Empire",
		"Chichimec Tribes",
		"The Mayans",
		"New Spain",
		"The Tarascans",
		"The Tlaxcalans"}},
		{"Britannia", {
		"England",
		"Ireland",
		"Norway",
		"Scotland",
		"Wales"}},
		{"Crusades", {
		"Principality of Antioch",
		"The Byzantine Empire",
		"Egypt",
		"Kingdom of Jerusalem",
		"The Turks"}},
		{"Teutonic", {
		"Denmark",
		"The Holy Roman Empire",
		"Lithuania",
		"Novgorod",
		"Poland",
		"The Teutonic Order"}}
	};

	std::vector<std::string> Medieval2Vanilla = {
		"The Byzantine Empire",
		"Denmark",
		"Egypt",
		"England",
		"France",
		"The Holy Roman Empire",
		"Hungary",
		"Milan",
		"Moors",
		"Portugal",
		"Russia",
		"Scotland",
		"Sicily",
		"Spain",
		"The Turks",
		"Venice"
	};

	std::vector<std::string> Medieval2Americas = {
		"Apachean Tribes",
		"The Aztec Empire",
		"Chichimec Tribes",
		"The Mayans",
		"New Spain",
		"The Tarascans",
		"The Tlaxcalans"
	};

	std::vector<std::string> Medieval2Britannia = {
		"England",
		"Ireland",
		"Norway",
		"Scotland",
		"Wales"
	};

	std::vector<std::string> Medieval2Crusades = {
		"Principality of Antioch",
		"The Byzantine Empire",
		"Egypt",
		"Kingdom of Jerusalem",
		"The Turks"
	};

	std::vector<std::string> Medieval2Teutonic = {
		"Denmark",
		"The Holy Roman Empire",
		"Lithuania",
		"Novgorod",
		"Poland",
		"The Teutonic Order"
	};

	std::vector<std::string> Campaigns = {
		"Vanilla",
		"Americas",
		"Britannia",
		"Crusades",
		"Teutonic"
	};

	std::vector<std::string> MedievalFilePaths = {
		"Medieval 2 Faction Pictures\\Americas\\Apachean Tribes.png",
		"Medieval 2 Faction Pictures\\Americas\\The Aztec Empire.png",
		"Medieval 2 Faction Pictures\\Americas\\Chichimec Tribes.png",
		"Medieval 2 Faction Pictures\\Americas\\New Spain.png",
		"Medieval 2 Faction Pictures\\Americas\\The Mayans.png",
		"Medieval 2 Faction Pictures\\Americas\\The Tarascans.png",
		"Medieval 2 Faction Pictures\\Americas\\The Tlaxcalans.png",
		"Medieval 2 Faction Pictures\\Britannia\\England.png",
		"Medieval 2 Faction Pictures\\Britannia\\Ireland.png",
		"Medieval 2 Faction Pictures\\Britannia\\Norway.png",
		"Medieval 2 Faction Pictures\\Britannia\\Scotland.png",
		"Medieval 2 Faction Pictures\\Britannia\\Wales.png",
		"Medieval 2 Faction Pictures\\Crusades\\Egypt.png",
		"Medieval 2 Faction Pictures\\Crusades\\Kingdom of Jerusalem.png",
		"Medieval 2 Faction Pictures\\Crusades\\Principality of Antioch.png",
		"Medieval 2 Faction Pictures\\Crusades\\The Byzantine Empire.png",
		"Medieval 2 Faction Pictures\\Crusades\\The Turks.png",
		"Medieval 2 Faction Pictures\\Teutonic\\Denmark.png",
		"Medieval 2 Faction Pictures\\Teutonic\\Lithuania.png",
		"Medieval 2 Faction Pictures\\Teutonic\\Novgorod.png",
		"Medieval 2 Faction Pictures\\Teutonic\\Poland.png",
		"Medieval 2 Faction Pictures\\Teutonic\\The Holy Roman Empire.png",
		"Medieval 2 Faction Pictures\\Teutonic\\The Teutonic Order.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Denmark.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Egypt.png",
		"Medieval 2 Faction Pictures\\Vanilla\\England.png",
		"Medieval 2 Faction Pictures\\Vanilla\\France.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Hungary.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Milan.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Poland.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Portugal.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Russia.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Scotland.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Sicily.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Spain.png",
		"Medieval 2 Faction Pictures\\Vanilla\\The Byzantine Empire.png",
		"Medieval 2 Faction Pictures\\Vanilla\\The Holy Roman Empire.png",
		"Medieval 2 Faction Pictures\\Vanilla\\The Moors.png",
		"Medieval 2 Faction Pictures\\Vanilla\\The Turks.png",
		"Medieval 2 Faction Pictures\\Vanilla\\Venice.png"
	};
};